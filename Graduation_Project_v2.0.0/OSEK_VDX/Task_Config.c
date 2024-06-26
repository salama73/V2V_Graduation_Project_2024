/************************************************
 * Task_Config.c
 *  Created on: 27/11/2023
 *  Author: Salama mohamed
 ************************************************/
#include "Task_Config.h"

DeclareTask(Task1);
DeclareTask(Task2);
DeclareTask(Task3);
DeclareTask(Task4);
DeclareTask(Task1_Led_ON);
DeclareTask(Task2_Led_OFF);

extern TASK(Task1);
extern TASK(Task3);
extern TASK(Task4);
extern TASK(Task2);
extern TASK(Task1_Led_ON);
extern TASK(Task2_Led_OFF);

void Os_Init(void)
{
	HW_init();
	if (MYRTOS_Init() != NO_ERROR)
		while (1);
	//DefineTask(Task1_Led_ON,512,Task_Suspend,5,FULL_PREEMPTIVE,Extended_Task);
	//DefineTask(Task2_Led_OFF,512,Task_Suspend,4,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task1,512,Task_Suspend,5,FULL_PREEMPTIVE,Extended_Task);
	//DefineTask(Task2,512,Task_Suspend,4,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task3,512,Task_Suspend,6,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task4,512,Task_Suspend,7,FULL_PREEMPTIVE,Extended_Task);
	ActivateTask(&Task1);
	//ActivateTask(&Task2);
	ActivateTask(&Task3);
	ActivateTask(&Task4);
	//ActivateTask(&Task1_Led_ON);
	//ActivateTask(&Task2_Led_OFF);
	MYRTOS_STARTOS();
}


