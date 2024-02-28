/************************************************
 * File Name   : Scheduler.H
 *  Created on : 20/11/2023
 *  Author     : Salama mohamed
 ************************************************/
#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "Type.h"

#include "Cortex_Mx_Porting.h"

typedef struct
{
	uint16_t* Ppayload					;
	unsigned int   PayloadSize 				;
	TaskRefType* 	   CurrentTUser 			;//Not Entered by the user
	TaskRefType* 	   NextTUser 				;//Not Entered by the user
	char 		   MutexName[30]  			;
	uint8_t 		priority_Inversion		;//Not Entered by the user
} Mutex_Ref;


typedef struct
{
	unsigned char* Ppayload					;
	TaskRefType* 	   CurrentTUser 			;//Not Entered by the user
	TaskRefType* 	   NextTUser 				;//Not Entered by the user
	char 		   SemaphoreName[30]  		;
	uint8_t 		state					;//Not Entered by the user
} Semaphore_Ref;



/*
 * *************************************************************
 * 						APIS
 ***************************************************************
 */

MY_RTOS_ErrorID MYRTOS_Init();
void MYRTOS_CreateTask(TaskRefType* Tref);
void MYRTOS_ActivateTask (TaskRefType* Tref);
void MYRTOS_TerminateTask (TaskRefType* Tref);
void MYRTOS_STARTOS();
void MYRTOS_TaskWait(unsigned int Num_Tick,TaskRefType* Tref);
MY_RTOS_ErrorID MYRTOS_AcquireMutex(Mutex_Ref* Mref , TaskRefType* Tref);
void MYRTOS_ReleaseMutex(Mutex_Ref* Mref , TaskRefType* Tref);
MY_RTOS_ErrorID MYRTOS_AcquireSemaphore(Semaphore_Ref* Sref ,TaskRefType* Tref);
void MYRTOS_ReleaseSemaphore(Semaphore_Ref* Sref);

#endif /* INC_SCHEDULER_H_ */
