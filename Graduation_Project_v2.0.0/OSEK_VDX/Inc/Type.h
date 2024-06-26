/************************************************
 * File Name   : Type.h
 *  Created on : 23/11/2023
 *  Author     : Salama mohamed
 ************************************************/
#ifndef INC_TYPE_H_
#define INC_TYPE_H_

#include <stdlib.h>
#include "Std_Types.h"


typedef enum
{
	OSsuspend,
	OsRunning
}OSmode;

typedef enum
{
	// no error
	//E_OK,
	//Alarm <AlarmID> is invalid
	 E_OS_ID,
	// the task has already been activated and multiple requests are not allowed
	 E_OS_LIMIT,
	//the task identifier TaskName is invalid
	E_ID,
	//a call at the interrupt level
	E_OS_CALLEVEL,
	// the task still occupies resources
	E_RESOURCE,
	// the referenced task is not an Extended Task
	E_ACCESS
}StatusType;

typedef enum {
	SVC_Activatetask,
	SVC_terminateTask,
	SVC_TaskWaitingTime,
	SVC_AquireMutex,
	SVC_ReleaseMutex
}SVC_ID;
//Each ET has a definite number of events - 8 or less
typedef uint8 EventMaskType;

typedef enum
{
	NO_ERROR,
	Ready_Queue_Init_Error,
	Task_exceeded_StackSize,
	SO_Table_Sort_Error,
	MutexisReacedToMaxNumberOfUsers
}MY_RTOS_ErrorID;

typedef enum
{
	Suspend,
	Running,
	Waiting,
	Ready
}TaskStateType;

typedef	enum
{
	Basic_Task,
	Extended_Task
}Task_Type;

typedef enum
{
  NONE_PREEMPTIVE,
  FULL_PREEMPTIVE
}Tasks_Scheduler_Type;

typedef enum
{
	Task_Suspend,
	Task_Start
}Auto_Start	;

typedef struct
{
	uint32 Stack_Size							;
	uint8 priority							;
	void (*P_TaskEntry)(void)					; //pointer to Tack C Function
	uint32 _S_PSP_Task 						;//Not Entered by the user
	uint32 _E_PSP_Task 						;//Not Entered by the user
	uint32* Current_PSP 						;//Not Entered by the user
	uint8 Task_Name[30] 						;
	TaskStateType TaskState						;//Not Entered by the user
	Task_Type	TaskType						;
	Auto_Start AutoStart						;
	Tasks_Scheduler_Type  TaskSchedlerType		;
	struct
	{
		enum
		{
			disable,
			enable
		}Blocking;
		uint32 Ticks_Count ;
	}Timing_Waiting;
	uint8 MultipleActivation;
	struct
	{
		EventMaskType Public_Mask;
		EventMaskType Private_Mask;
	}Events;
}TaskRefType;

typedef enum
{
	TASK_LEVEL,
	ISR_CAT1,
	ISR_CAT2,
	HOOK
}OS_level;

struct System_Conctrol
{
	TaskRefType* OSTasks[100]		; //Scheduler Table
	unsigned int _S_MSP_Task 		;
	unsigned int _E_MSP_Task 		;
	unsigned int PSP_Task_Locator 	;
	unsigned int NoOfActiveTasks 	;
	TaskRefType* CurrentTask 		;
	TaskRefType* NextTask 			;
	OSmode OSmodeID					;
	OS_level Call_Leve				;
};

//This data type represents count values in ticks
typedef uint32 TickType;
//This data type points to the data type TickType.
typedef TickType* TickRefType;
//This data type represents a structure for storage of counter characteristics
typedef struct
{
	// Maximum possible allowed count value in ticks
	TickType maxallowedvalue;
	// Number of ticks required to reach a counter-specific unit
	TickType ticksperbase;
	// Smallest allowed value for the cycle-parameter of SetRelAlarm/SetAbsAlarm
	TickType mincycle;
}AlarmBaseType;
typedef struct
{
	AlarmBaseType Counter_Ifo;
	TickType Counter_Value;
}OS_Counters;
//This data type points to the data type AlarmBaseType.
typedef AlarmBaseType* AlarmBaseRefType;
//This data type represents an alarm object
typedef uint8 AlarmType;


void OSEK_SVC(SVC_ID ID);

#endif /* INC_TYPE_H_ */
