/*****************************************************
 * SWC        : RTE_Task.c
 * Created on : 27/2/2024
 * Author	  : Salama Mohamed
 *****************************************************/

#include "Scheduler.h"
#include "Task.h"
#include "Task_Config.h"
#include "Event.h"
#include "Can.h"

void LED_SWC(void);
void Main_SWC(void);
void Empty_For_Test(uint8 Frame);
void BSW_SWC(void);
void Motor_SWC(void);

extern Can_HwHandleType Hth;
extern Can_PduType PduInfo;


DeclareTask(Task1);
DeclareTask(Task2);
DeclareTask(Task3);
DeclareTask(Task4);
DeclareTask(CAT2_CAN_Task);

TASK(Task1)
{
	while(1)
	{
		WaitEvent(0xff);
		Main_SWC();
		ClearEvent(0xff);
	}
}

TASK(Task3)
{
	while(1)
	{
		WaitEvent(0X0F);
		LED_SWC();
		ClearEvent(0X0F);
	}
}

TASK(Task4)
{
	while(1)
	{
		WaitEvent(0X1F);
		Motor_SWC();
		ClearEvent(0X1F);
	}
}

TASK(Task2)
{
	int x=0;
	while (1)
	{
		//delay_ms(500);
		x++;
		if(x==10)
		{
			x=0;
			Can_Write(Hth,&PduInfo);

		}
	}
}

void ECUM_Init(void)
{
	 HW_init();
	if (MYRTOS_Init() != NO_ERROR)
		while (1);
	DefineTask(Task1,512,Task_Suspend,6,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task2,512,Task_Suspend,4,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task3,512,Task_Suspend,5,FULL_PREEMPTIVE,Extended_Task);
	DefineTask(Task4,512,Task_Suspend,5,FULL_PREEMPTIVE,Extended_Task);
	ActivateTask(&Task1);
	ActivateTask(&Task2);
	ActivateTask(&Task3);
	ActivateTask(&Task4);
	MYRTOS_STARTOS();
}
