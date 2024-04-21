/************************************************
 * File Name   : Task.c
 *  Created on : 23/11/2023
 *  Author     : Salama mohamed
 ************************************************/
/***********************************************************************************
************************************* Include***************************************
************************************************************************************/
#include "Task.h"
#include "Cortex_Mx_Porting.h"
#include"MY_RTOS_FIFO.h"
#include "Task_Config.h"
/***********************************************************************************
*************************************Global Variable********************************
************************************************************************************/
extern struct System_Conctrol OS_Control;
FIFO_Buf_t Ready_QUEUE ;
TaskRefType* Ready_QUEUE_FIFO[10];
extern TaskRefType MYRTOS_idleTask;
/***********************************************************************************
*************************************Services***************************************
************************************************************************************/
uint8_t Mutex=0;
#define Mutex_Lock 		if(Mutex!=0)return 0;else Mutex=1
#define Mutex_UnLock 	Mutex=1
/***********************************************************************************
*************************************APIS***************************************
************************************************************************************/
/**================================================================
* @Fn				-ActivateTask
* @brief		  	 The specified task TaskName is transferred from the suspended state into the
					 ready state.
* @param [in] 		-TaskName:  a reference to the task.
* @retval 			-StatusType
* Note				-The service may be called both on the task level (from a task) and the interrupt level (from ISR).
*/
StatusType ActivateTask(TaskRefType* TaskName)
{
	//The specified task TaskName is transferred from the suspended state into the ready state.
	StatusType status=E_OK;
	if(NULL==TaskName)
	{
		//the task identifier TaskName is invalid
		status=E_ID;
		return status;
	}
	else
	{
		if(TaskName->MultipleActivation==0)
		{
			if(TaskName->TaskState==Suspend)
			{
				if(FIFO_is_full(&Ready_QUEUE)==FIFO_NOT_FULL||FIFO_is_full(&Ready_QUEUE)==FIFO_EMPTY)
				{
					TaskName->TaskState=Ready;
					if(OS_Control.CurrentTask->TaskSchedlerType!=NONE_PREEMPTIVE)
					{
						if(TaskName->priority>OS_Control.CurrentTask->priority)
						{
							//the new task high priority than CurrentTask
							OS_Control.NextTask=TaskName;
							//push current Queue
							FIFO_enqueue(&Ready_QUEUE,OS_Control.CurrentTask);
							if(OS_Control.OSmodeID==OsRunning)
							{
								trigger_OS_PendSV();
							}
							else
							{
								/************************************************************************/
								//Add task to ready buffer
								FIFO_enqueue(&Ready_QUEUE, TaskName);
								/**************************************************************************/
							}
						}
						else
						{
							/************************************************************************/
							//Add task to ready buffer
							FIFO_enqueue(&Ready_QUEUE, TaskName);
							/**************************************************************************/
						}
					}
					else
					{
						//NONE PREEMPTIVE task
					}
				}
				else
				{
					// too many task activations of the specified task or there is no enough resources to activate the task.
					status=E_STATE;
					return status;
				}
			}
			else
			{
				// the task identifier TaskName is invalid
				status=E_STATE;
				return status;
			}
		}
		else
		{
			//later (MultipleActivation property in Basic Task)
		}
	}
	return status;
}
/**================================================================
* @Fn				-TerminateTask
* @brief		  	 This service causes the termination of the calling task. The calling task is
					 transferred from the running state into the suspended state and releases all
                     occupied system resources
* @param [in] 		-None
* @param [out] 		-None
* @retval 			-StatusType
* Note				-None
*/
StatusType TerminateTask(void)
{
	StatusType Error=E_OK;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0)
	{
		if(OS_Control.CurrentTask->TaskType==Extended_Task)
		{
			// a call at the interrupt level.
			Error=E_CALLEVEL;
			return Error;
		}
		else
		{
			// No return to the caller (handle later)
		}
	}
	else
	{
		//resource management handle later
		OS_Control.CurrentTask->TaskState=Suspend;
		Error=Schedule();
		trigger_OS_PendSV();
	}
	return Error;
}
/**================================================================
* @Fn				-ChainTask
* @brief		  	 This service causes the termination of the calling task. After termination of the
					 calling task a succeeding task <TaskName> is activated sequentially.
* @param [in] 		-TaskNamea:
					 reference to the sequential succeeding task to be activated.
* @param [out] 		-None
* @retval 			-StatusType
* Note				- Using this service, it ensures that the succeeding task only starts
					  to run after the calling task has been terminated.
*/
StatusType ChainTask(TaskRefType* TaskName)
{
	/*
	 This service causes the termination of the calling task. After termination of the
	 calling task a succeeding task <TaskName> is activated sequentially.
	 */
	// The resources occupied by the calling task must have been released before. (later)
	StatusType Error=E_OK;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0)
	{
		if(OS_Control.CurrentTask->TaskType==Extended_Task)
		{
			// a call at the interrupt level.
			Error=E_CALLEVEL;
			return Error;
		}
		else
		{
			// No return to the caller (handle later)
		}
	}
	else
	{
		//resource management handle later
		OS_Control.CurrentTask->TaskState=Suspend;
		// it ensures that the succeeding task only starts to run after the calling task has been terminated.
		if(NULL==TaskName)
		{
			//the task identifier TaskName is invalid
			Error=E_ID;
			return Error;
		}
		else
		{
			TaskName->TaskState=Ready;
			if(OS_Control.OSmodeID==OsRunning)
			{
				OS_Control.NextTask=TaskName;
				trigger_OS_PendSV();
			}
			else
			{
				// os not run
			}
		}
	}
	return Error;
}
/**================================================================
* @Fn				-Schedule
* @brief		  	 If a higher-priority task is ready, the current task is put into the ready state and a
					 higher-priority task is executed.
* @param [in] 		-None.
* @param [out] 		-None
* @retval 			-StatusType
* Note				-None
*/
#if(Conformance_Classe==ECC2||Conformance_Classe==BCC2)
StatusType Schedule(void)
{
	StatusType Error=E_OK;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0)
	{
		if(OS_Control.CurrentTask->TaskType==Extended_Task)
		{
			// a call at the interrupt level.
			Error=E_CALLEVEL;
			return Error;
		}
		else
		{
			// No return to the caller (handle later)
		}
	}
	else
	{
		TaskRefType* Task_temp[10]={NULL};
		if(FIFO_is_full(&Ready_QUEUE)==FIFO_EMPTY&&OS_Control.CurrentTask->TaskState==Suspend)
		{
			OS_Control.NextTask=&MYRTOS_idleTask;
		}
		else
		{
			//Refresh queue buffer
			TaskRefType* temp=NULL;
			for(uint8_t i=0;i<=Ready_QUEUE.counter-1;i++)
			{
				temp=Ready_QUEUE_FIFO[i];
				for(uint8_t j=i+1;j<Ready_QUEUE.counter;j++)
				{
					if(Ready_QUEUE_FIFO[i]->priority<Ready_QUEUE_FIFO[j]->priority)
					{
						temp=Ready_QUEUE_FIFO[i];
						Ready_QUEUE_FIFO[i]=Ready_QUEUE_FIFO[j];
						Ready_QUEUE_FIFO[j]=temp;
					}
					else
					{
						//
					}
				}
			}
			uint8_t numOFtask=Ready_QUEUE.counter;
			for(uint8_t i=0;i<numOFtask;i++)
			{
				FIFO_dequeue(&Ready_QUEUE,&Task_temp[i]);
			}
			//always ready queue Refers to first element
			Ready_QUEUE.head=Ready_QUEUE.base;
			Ready_QUEUE.tail=Ready_QUEUE.base;
			for(uint8_t i=0;i<numOFtask;i++)
			{
				FIFO_enqueue(&Ready_QUEUE, Task_temp[i]);
			}
			FIFO_dequeue(&Ready_QUEUE,&OS_Control.NextTask);
		}
	}
	return Error;
}
#else
/**================================================================
* @Fn				-Schedule
* @brief		  	 If each task in the application has an unique priority the simplified scheduler may
					 be used to reduce memory and time consuming.
* @param [in] 		-None.
* @param [out] 		-None
* @retval 			-StatusType
* Note				-None
*/
StatusType Schedule(void)
{
	StatusType Error=E_OK;
	TaskRefType* Temp;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0&&IRQ_Flag!=36)
	{
		if(OS_Control.CurrentTask->TaskType==Extended_Task)
		{
			// a call at the interrupt level.
			Error=E_CALLEVEL;
			return Error;
		}
		else
		{
			// No return to the caller (handle later)
		}
	}
	else
	{
		for(int i=0;i<OS_Control.NoOfActiveTasks-1;i++)
		{
			for(int j=i+1;j<OS_Control.NoOfActiveTasks;j++)
			{
				if(OS_Control.OSTasks[i]->priority<OS_Control.OSTasks[j]->priority)
				{
					Temp=OS_Control.OSTasks[i];
					OS_Control.OSTasks[i]=OS_Control.OSTasks[j];
					OS_Control.OSTasks[j]=Temp;
				}
				else
				{
					//
				}
			}
		}
		//initial value for Next Task
		OS_Control.NextTask=&MYRTOS_idleTask;
		uint8_t index=0;
		while(index< OS_Control.NoOfActiveTasks)
		{
			//select ready task
			if (OS_Control.OSTasks[index]->TaskState == Ready)
			{
				OS_Control.NextTask=OS_Control.OSTasks[index] ;
				break ;
			}
			else
			{
				index++ ;
			}
		}
	}
	return Error;
}
#endif
/**================================================================
* @Fn				-GetTaskId
* @brief		  	 This system service returns the name (<TaskName>) of the task which is currently active.
* @param [in] 		-None
* @param [out] 		-TaskName: a reference to the task which is currently active.
* @retval 			-StatusType
* Note				-None
*/
StatusType GetTaskId(TaskRefType* TaskName)
{
	//This system service returns the name (<TaskName>) of the task which is currently active.
	/*
	 This service is useful, for instance, in the case if two or more tasks shares the same
	 piece of code
	 */
	StatusType Error=E_OK;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0)
	{
		if(OS_Control.CurrentTask->TaskType==Extended_Task)
		{
			// a call at the interrupt level.
			Error=E_CALLEVEL;
			return Error;
		}
		else
		{
			// No return to the caller (handle later)
		}
	}
	else
	{
		TaskName=OS_Control.CurrentTask;
	}
	return Error;
}

