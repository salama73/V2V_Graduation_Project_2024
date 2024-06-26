/*
 * IMA_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */

#include "Rte_IMA_SWC.h"
#include "Event.h"

#define Periodic_Duration   50
#define LED_ON               1
#define LED_OFF              0
#define Stop                 0
#define LOW_Speed            1
#define HIGH_Speed           2
#define Super_Speed          3
#define Time_Threshold       2000

#define Time_OF_HostV              Frame[1]
#define Time_Of_RemoteV            Frame[2]
#define Speed_OF_HostV             Frame[3]
#define Speed_Of_RemoteV           Frame[4]

Std_ReturnType IMA_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Status=E_OK;
	boolean Button_set=FALSE;
	//my_uint8 Motor_Speed;
	//my_uint8 LED_Warning;
	//my_uint8 LCD_Warning;
	const my_uint8* Frame = CAN_Frame ;
	my_uint16 Number_Of_Periodic_Alarms = (0.5*Time_OF_HostV*1000)/Periodic_Duration ;

	while(--Number_Of_Periodic_Alarms)
	{
		// Todo : should go throw the RTE
		Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_ON);
		WaitEvent(0x02);
		ClearEvent(0x02);

		if(Button_set == TRUE)
		{
			Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_OFF);
			break;
		}

	}
	Number_Of_Periodic_Alarms=0;
	if(!Number_Of_Periodic_Alarms)
	{
		if(Time_OF_HostV > Time_Of_RemoteV)
		{
			if(Speed_OF_HostV < Speed_Of_RemoteV)
			{
				Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(LOW_Speed);
			}
			else
			{
				if((Time_OF_HostV-Time_Of_RemoteV) > Time_Threshold )
				{
					Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Super_Speed);
				}
				else
				{
					Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Stop);
				}
			}
		}
		else
		{
			if(Speed_OF_HostV > Speed_Of_RemoteV)
			{
				Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(HIGH_Speed);
			}
			else
			{
				if((Time_Of_RemoteV-Time_OF_HostV) > Time_Threshold )
				{
					Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Stop);
				}
				else
				{
					Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Super_Speed);
				}
			}

		}
	}



	//Rte_IWrite_IMA_SWC_IMA_SWC_Runnable_PP_LCD_LCD_Warning(LCD_Warning);


	return Status;
}
