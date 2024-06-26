/*
 * Cortex_Mx_Porting.c
 *  Created on: 27/4/2023
 *  Author: Salama mohamed
 */

#include "Cortex_Mx_Porting.h"
#include "Alarm.h"
#include "Dio.h"

uint8 SysTickLED;

void HardFault_Handler(void)
{
	while(1);
}

void MemManage_Handler(void)
{
	while(1);
}

void vBusFault_Handler(void)
{
	while(1);
}

void UsageFault_Handler(void)
{
	while(1);
}

/*
__attribute((naked)) void SVC_Handler (void)
{
    __asm(  "TST LR,#4\n\t"
    		"ITE EQ \n\t"
    		"MRSEQ R0,MSP\n\t"
    		"MRSNE R0,PSP\n\t"
    		"B OS_SV");
}
*/
void HW_init()
{
	/*
	 * Initialize Clock Tree (RCC -> SysTick Timer & CPU) 8MHZ
	 * Clock tree
	 * RCC Default Values makes CPU Clock & SySTick Timer clock=8MHZ
	 * 8 MHZ
	 * 1 count -> 0.125 us
	 * X count -> 1 ms
	 * X = 8000 Count
	 */
	__NVIC_SetPriority(PendSV_IRQn, 15) ;

}
void trigger_OS_PendSV()
{
	int x=5;
	x++;
	SCB->ICSR|=SCB_ICSR_PENDSVSET_Msk;
}

void Start_Ticker()
{
	/*
	 * This clock tree should be defined in HW_init()
	 * 8 MHZ
	 * 1 count -> 0.125 us
	 * X count -> 1 ms
	 * X = 8000 Count
	 */
	 SysTick_Config(8000);
}
uint32 count=0;
uint32 newtime[10]={0};
uint8 fla=STD_LOW;
ALARMCALLBACK(Alarm1);
ALARMCALLBACK(Alarm0);
ALARMCALLBACK(Alarm2);
void SysTick_Handler(void)
{

	if(count==2000)count=0;
	if(Alarms_Number!=0)
	{
		for(uint8 x=0;x<Alarms_Number;x++)
		{
			Alarms[x]->Counter.Counter_Value++;
			if(Alarms[x]->Counter.Counter_Value>Alarms[x]->Counter.Counter_Ifo.maxallowedvalue)Alarms[x]->Counter.Counter_Value=0;
			if(Alarms[x]->Counter.Counter_Ifo.mincycle<=Alarms[x]->AlarmTime)
			{
				if((count==Alarms[x]->AlarmTime&&newtime[x]==0) ||(Alarms[x]->Counter.Counter_Value==newtime[x]))
				{
					if(x==0)
					{
						AlarmCallback_Alarm0();
					}
					else if(x==1)
					{
						AlarmCallback_Alarm1();
					}
					else if(x==2)
					{
						AlarmCallback_Alarm2();
					}
					else
					{

					}
					/*
					if(fla==STD_HIGH)
					{
						Dio_WriteChannel(channel_45,STD_HIGH);
						fla=STD_LOW;
					}
					else
					{
						Dio_WriteChannel(channel_45,STD_LOW);
						fla=STD_HIGH;
					}*/
					newtime[x]=(uint16)(Alarms[x]->Counter.Counter_Value+Alarms[x]->CycleTime);
					if(newtime[x]>Alarms[x]->Counter.Counter_Ifo.maxallowedvalue)newtime[x]-=Alarms[x]->Counter.Counter_Ifo.maxallowedvalue;
				}
				else
				{
					//Dio_WriteChannel(channel_45,STD_LOW);
					//fla=STD_LOW;
				}
			}
		}
	}
	//MYRTOS_Update_TasksWaitingTime();
	//MYRTOS_Update_TasksWaitingTime();
	//Determine Pcurrent & Pnext
	//Decide_whatNext();
	//Switch Context & restore
	//Schedule();
	//trigger_OS_PendSV();

}
