/******************************************
 * File Name   : Event.c
 * Created on  : 28/11/2023
 * Author     : Salama mohamed
 *****************************************/
#include "Event.h"
#include"MY_RTOS_FIFO.h"

extern FIFO_Buf_t Ready_QUEUE ;
extern TaskRefType* Ready_QUEUE_FIFO[10];
extern struct System_Conctrol OS_Control;

StatusType SetEvent(TaskRefType* TaskName,EventMaskType Mask)
{
	StatusType statu=NO_ERROR;
	uint32_t IRQ_Flag=0;
	if(TaskName->TaskType!=Extended_Task)
	{
		// the referenced task is not an Extended Task
		statu=E_ACCESS;
		return statu;
	}
	else
	{
		if(TaskName->TaskState==Suspend)
		{
			//  the referenced task is in the suspended state
			//statu=E_STATE;
			return statu;
		}
		else
		{
			//read state of cpu
			OS_GET_IRQ_Flag(IRQ_Flag);
			//36 for can handler (Excepted)
			if(IRQ_Flag!=0&&IRQ_Flag!=36&&IRQ_Flag!=15)
			{
				// a call at the interrupt level.
				statu=E_OS_CALLEVEL;
				return statu;
			}
			else
			{
				//set mask
				TaskName->Events.Public_Mask|=Mask;
				//check any waiting for this task
				if(TaskName->Events.Public_Mask&TaskName->Events.Private_Mask)
				{
					TaskName->TaskState=Ready;
					if(OS_Control.CurrentTask->priority>TaskName->priority)
					{
						//Add task to ready buffer
						FIFO_enqueue(&Ready_QUEUE,TaskName);
					}
					else
					{
						Schedule();
						trigger_OS_PendSV();
					}
				}
			}
		}
	}
	return statu;
}

StatusType ClearEvent(EventMaskType Mask)
{
	StatusType statu=NO_ERROR;
	uint32_t IRQ_Flag=0;
	//read state of cpu
	OS_GET_IRQ_Flag(IRQ_Flag);
	if(IRQ_Flag!=0)
	{
		// a call at the interrupt level.
		statu=E_OS_CALLEVEL;
		return statu;
	}
	else
	{
		if(OS_Control.CurrentTask->TaskType!=Extended_Task)
		{
			// the referenced task is not an Extended Task
			statu=E_ACCESS;
			return statu;
		}
		else
		{
			OS_Control.CurrentTask->Events.Private_Mask&=~Mask;
			OS_Control.CurrentTask->Events.Public_Mask&=~Mask;
		}
	}
	return statu;
}

StatusType GetEvent(TaskRefType* TaskName,EventMaskType* Event)
{
	StatusType statu=NO_ERROR;
	uint32_t IRQ_Flag=0;
	if(TaskName->TaskType!=Extended_Task)
	{
		// the referenced task is not an Extended Task
		statu=E_ACCESS;
		return statu;
	}
	else
	{
		if(TaskName->TaskState==Suspend)
		{
			//  the referenced task is in the suspended state
			//statu=E_STATE;
			return statu;
		}
		else
		{
			//read state of cpu
			OS_GET_IRQ_Flag(IRQ_Flag);
			if(IRQ_Flag!=0)
			{
				// a call at the interrupt level.
				statu=E_OS_CALLEVEL;
				return statu;
			}
			else
			{
				*Event=TaskName->Events.Public_Mask;
			}
		}
	}
	return statu;
}

StatusType WaitEvent(EventMaskType Mask)
{
	StatusType statu=NO_ERROR;
	uint32_t IRQ_Flag=0;
	if(OS_Control.CurrentTask->TaskType!=Extended_Task)
	{
		// the referenced task is not an Extended Task
		statu=E_ACCESS;
		return statu;
	}
	else
	{
		//read state of cpu
		OS_GET_IRQ_Flag(IRQ_Flag);
		if(IRQ_Flag!=0)
		{
			// a call at the interrupt level.
			statu=E_OS_CALLEVEL;
			return statu;
		}
		else
		{
			OS_Control.CurrentTask->Events.Private_Mask|=Mask;
			if(OS_Control.CurrentTask->Events.Private_Mask&OS_Control.CurrentTask->Events.Public_Mask)
			{
				return statu;
			}
			else
			{
				OS_Control.CurrentTask->TaskState=Waiting;
				statu=Schedule();
				trigger_OS_PendSV();
			}
		}
	}
	return statu;
}
