/*
 * EEBL_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */


#include "Rte_EEBL_SWC.h"
#include "Event.h"

#define LED_ON               1
#define LED_OFF              0
#define Stop                 0
#define LOW_Speed            1
#define HIGH_Speed           2
#define Super_Speed          3

Std_ReturnType EEBL_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Status=E_OK;
		//my_uint8 Motor_Speed;
		//my_uint8 LED_Warning;
		//my_uint8 LCD_Warning;
		const my_uint8* Frame = CAN_Frame ;
		my_uint16 Distance = 0;
		Rte_Call_EEBL_SWC_RP_Get_Distance_Call_Ultrasonic(&Distance);
		my_uint16 Number_Of_Periodic_Alarms = 5 ;
		while(--Number_Of_Periodic_Alarms)
		{
			// Todo : should go throw the RTE
			WaitEvent(0x01);
			ClearEvent(0x01);
			Rte_Call_EEBL_SWC_RP_Get_Distance_Call_Ultrasonic(&Distance);
			if(Frame[1] < Distance)
			{
				Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_ON);
			}
			else
			{
				Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Stop);
			}
		}

		//Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning(LCD_Warning);


		return Status;
}
