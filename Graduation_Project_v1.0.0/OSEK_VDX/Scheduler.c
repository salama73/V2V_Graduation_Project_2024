/************************************************
 * File Name   : Scheduler.c
 *  Created on : 20/11/2023
 *  Author     : Salama mohamed
 ************************************************/
#include "Scheduler.h"
#include"MY_RTOS_FIFO.h"

TaskRefType* OS_Task_Ready[20]={NULL};
uint8_t TaskReady_Id=0;
uint8_t IdleTaskLED;
/*****************************************************************
 **************************Generic Variable***********************
 *****************************************************************/
struct System_Conctrol OS_Control;
extern FIFO_Buf_t Ready_QUEUE ;
extern TaskRefType* Ready_QUEUE_FIFO[10] ;
TaskRefType MYRTOS_idleTask;

// idle task
void MYRTOS_IdleTask()
{
	IdleTaskLED ^=1;
	IdleTaskLED ^=1;
	while(1)
	{
		IdleTaskLED ^=1;
		__asm("WFE");
	}
}
 /****************************************************************************************
 *                      Function
******************************************************************************************/
/*****************************************************************************************
* @Fn          - PendSV_Handler
* @brief       - Interrupt handler for PendSV to switch Context and restore to cpu register
* @retval      - None
* note         - Since the function is declared with the naked attribute, it is responsible
* 				for managing the necessary operations within the interrupt handler,
* 				such as saving and restoring task context, updating task states,
* 				or performing other operations related to task scheduling or context management.
*****************************************************************************************/
__attribute ((naked)) void PendSV_Handler()
{
	if(OS_Control.NextTask != NULL)
	{
		if(OS_Control.CurrentTask->TaskType!=Basic_Task||OS_Control.CurrentTask->TaskState!=Suspend)
		{
			//====================================
			//Save the Context of the Current Task
			//====================================
			//Get the Current Task "Current PSP from CPU register" as CPU Push
			OS_GET_PSP(OS_Control.CurrentTask->Current_PSP);
			//using this Current_PSP store from R4 to R11
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r4 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r5 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r6 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r7 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r8 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r9 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r10 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			OS_Control.CurrentTask->Current_PSP-- ;
			__asm volatile("mov %0,r11 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
			/*
			 * save the current Value of PSP
			 * already saved in Current_PSP
			 */
		}
		else
		{
			//basic task reallocate stack
			OS_Control.CurrentTask->Current_PSP= OS_Control.CurrentTask->_S_PSP_Task ;
			OS_Control.CurrentTask->Current_PSP-- ;
			*(OS_Control.CurrentTask->Current_PSP) = 0x01000000;
			OS_Control.CurrentTask->Current_PSP-- ;
			*(OS_Control.CurrentTask->Current_PSP) = (uint32_t)OS_Control.CurrentTask->P_TaskEntry ;
			OS_Control.CurrentTask->Current_PSP-- ;
			*(OS_Control.CurrentTask->Current_PSP)  = 0xFFFFFFFD ;
			//set R0 to R12 by value 0
			for (int  i=0 ; i< 13 ; i++ )
			{
				OS_Control.CurrentTask->Current_PSP-- ;
				*(OS_Control.CurrentTask->Current_PSP)  = 0 ;
			}

		}
		//====================================
		//Restore the Context of the Next Task
		//====================================
		OS_Control.CurrentTask = OS_Control.NextTask ;
		__asm volatile("mov r11,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r10,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r9,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r8,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r7,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r6,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r5,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		__asm volatile("mov r4,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP++ ;
		//update PSP and exit
		OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
		// return to next task
	}
	OS_Control.NextTask = NULL ;
	OS_Control.Call_Leve=TASK_LEVEL;
	__asm volatile("BX LR");
}
/****************************************************************************************
* @Fn          - MYRTOS_Create_MainStack
* @brief       - Creates the main stack for the MYRTOS (My Real-Time Operating System)
* @retval      - None
******************************************************************************************/
void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP_Task = &_estack;
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - MainStackSize;
	//Aligned 8 Bytes spaces between Main Task and PSP tasks
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8);
	//if (_E_MSP_Task <&_eheap) Error:excedded the available stack size
}
/****************************************************************************************
* @Fn          - MYRTOS_Init
* @brief       - Initializes the MYRTOS (My Real-Time Operating System)
* @retval      - The error code indicating the success or failure of the initialization process
******************************************************************************************/
MY_RTOS_ErrorID MYRTOS_Init()
{
	MY_RTOS_ErrorID error = NO_ERROR ;
	//Update OS Mode (OSsuspend)
	OS_Control.OSmodeID = OSsuspend ;
	//Create main Stack for OS
	MYRTOS_Create_MainStack();
	//Create OS Ready Queue
	if (FIFO_init(&Ready_QUEUE, Ready_QUEUE_FIFO, 100) !=FIFO_NO_ERROR)
	{
		error = Ready_Queue_Init_Error ;
	}
	//Configure IDLE TASK
	strcpy (MYRTOS_idleTask.Task_Name, "idleTask");
	MYRTOS_idleTask.priority = 0 ;
	MYRTOS_idleTask.P_TaskEntry = MYRTOS_IdleTask ;
	MYRTOS_idleTask.Stack_Size = 300 ;
	MYRTOS_CreateTask(&MYRTOS_idleTask);
	MYRTOS_idleTask.TaskSchedlerType=FULL_PREEMPTIVE;
	return error ;
}
/******************************************************************************************
* @Fn          - MyRTOS_Create_TaskStack
* @brief       - Creates the stack for a specific task in MyRTOS
* @param [in]  - Tref: Pointer to the TaskRefType structure representing the task
* @retval      - None
*****************************************************************************************/
void MyRTOS_Create_TaskStack(TaskRefType* Tref)
{
	/*Task Frame
	 * ======
	 * XPSR
	 * PC (Next Task Instruction which should be Run)
	 * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *====
	 *R5-R6-R7-R8-R9-R10-R11 Saved and Restore Manual
	 * DUMMY Value
	 * XPSR should T =1 to thumb mode
	 * LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
	 */
	//set current PSP
	Tref->Current_PSP = Tref->_S_PSP_Task ;
	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = 0x01000000;
	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = (uint32_t)Tref->P_TaskEntry ;
	Tref->Current_PSP-- ;
	*(Tref->Current_PSP)  = 0xFFFFFFFD ;
	//set R0 to R12 by value 0
	for (int  i=0 ; i< 13 ; i++ )
	{
		Tref->Current_PSP-- ;
		*(Tref->Current_PSP)  = 0 ;
	}
}
/****************************************************************************************
* @Fn          - MYRTOS_CreateTask
* @brief       - Creates a new task in MyRTOS
* @param [in]  - Tref: Pointer to the TaskRefType structure representing the task
* @retval      - The error code indicating the success or failure of the task creation
*******************************************************************************************/
void MYRTOS_CreateTask(TaskRefType* Tref)
{
	//Create Its OWN PSP Stack
	// Start PSP Stack for Tref
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	// End PSP Stack for Tref
	Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size ;
	//check that the stack task  does not exceed the stack size
	if(Tref->_E_PSP_Task < (uint32_t)(&(_eheap)))
	{
		HardFault_Handler();
	}
	//Aligned 8 Bytes spaces between Current Task PSP and next
	OS_Control.PSP_Task_Locator=(Tref->_E_PSP_Task-8);
	//Initialize PSP Task Stack
	MyRTOS_Create_TaskStack(Tref);
	//update Scheduler Table
	OS_Control.OSTasks[OS_Control.NoOfActiveTasks]= Tref ;
	OS_Control.NoOfActiveTasks++ ;
	//Task by default State is Suspend
	if(Tref->AutoStart)
	{
		ActivateTask(Tref);
	}
	else
		Tref->TaskState = Suspend ;
}
/****************************************************************************************
 * @Fn          - MYRTOS_CreateTask
 ******************************************************************************************/
void MYRTOS_STARTOS()
{
	OS_Control.CurrentTask=&MYRTOS_idleTask;
	if(Ready_QUEUE.counter==0)
	{
		OS_Control.NextTask=&MYRTOS_idleTask;
		MYRTOS_idleTask.TaskState=Ready;
		OS_Control.CurrentTask=&MYRTOS_idleTask;
	}
	else
	{
		Schedule();
	}
	OS_Control.CurrentTask=&MYRTOS_idleTask;
	//Start Ticker
	Start_Ticker(); // 1ms
	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	//Switch Thread Mode SP from MSP to PSP
	OS_Switch_SP_PSP;
	OS_Control.OSmodeID = OsRunning ;
	trigger_OS_PendSV();
	CPU_Access_Level_Unprivileged();
	MYRTOS_idleTask.P_TaskEntry();
}
