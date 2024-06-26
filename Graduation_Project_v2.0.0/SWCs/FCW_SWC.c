/*
 * FCW_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */
#include "Rte_FCW_SWC.h"
#include "Event.h"

#define Distance_Threshold  50
#define Periodic_Duration   250
#define LED_ON               1
#define LED_OFF              0
#define LOW_Speed            1
#define HIGH_Speed           2


Std_ReturnType FCW_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Status=E_OK;
	//my_uint8 Motor_Speed;
	//my_uint8 LED_Warning;
	//my_uint8 LCD_Warning;
	const my_uint8* Frame = CAN_Frame ;
	my_uint16 Distance = 0;
	Rte_Call_FCW_SWC_RP_Get_Distance_Call_Ultrasonic(&Distance);
	my_uint16 Number_Of_Periodic_Alarms = (0.5*Frame[1]*1000)/Periodic_Duration ;
	while(--Number_Of_Periodic_Alarms)
	{
		// Todo : should go throw the RTE , button
		WaitEvent(0x08);
		ClearEvent(0x08);
		Rte_Call_FCW_SWC_RP_Get_Distance_Call_Ultrasonic(&Distance);
		if(Distance > Distance_Threshold)
		{
			Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_ON);
		}
		else
		{
			Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(LOW_Speed);
		}
	}
	if(!Number_Of_Periodic_Alarms)
	{
		Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(LOW_Speed);
	}

	//Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_LCD_LCD_Warning(LCD_Warning);


	return Status;
}

