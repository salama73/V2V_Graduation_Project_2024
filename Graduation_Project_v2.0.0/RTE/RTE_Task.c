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
#include "Dio.h"
#include "delay.h"

void LED_SWC(void);
void Main_SWC(void);
void Empty_For_Test(uint8 Frame);
void BSW_SWC(void);
void Motor_SWC(void);

extern DeclareTask(Task1_Led_ON);
extern DeclareTask(Task2_Led_OFF);

extern Can_HwHandleType Hth;
extern Can_PduType PduInfo;
uint8 c=0;
TASK(Task1_Led_ON)
{
	while(1)
	{
		WaitEvent(0xf1);
		ClearEvent(0xf1);
		Dio_WriteChannel(channel_45,STD_LOW);
	}
}

TASK(Task2_Led_OFF)
{
	while(1)
	{
		WaitEvent(0xf0);
		ClearEvent(0xf0);
		Dio_WriteChannel(channel_45,STD_HIGH);
	}
}

TASK(Task1)
{
	while(1)
	{
		WaitEvent(0x10);
		ClearEvent(0x10);
		Main_SWC();

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
		delay_ms(500);
		Can_Write(Hth,&PduInfo);
		PduInfo.sdu[1]^=1;
		/*
		x++;
		if(x==100)
		{
			x=0;
			Can_Write(Hth,&PduInfo);


		}
		*/
	}
}

