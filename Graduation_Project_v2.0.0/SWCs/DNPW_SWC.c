/*
 * DNPW_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */

#include "Rte_DNPW_SWC.h"
#define AHED_LEFT 1
#define REVERSE 1
#define LED_ON               1
#define LED_OFF              0
#define LOW_Speed            0
#define HIGH_Speed           1
#define Super_Speed          3
#define Stop                 2


Std_ReturnType DNPW_SWC(const my_uint8* CAN_Frame)
{
	const my_uint8* Frame= CAN_Frame;
	//  my_uint8 Motor_Speed;
	//  my_uint8 LED_Warning;
	//  my_uint8 LCD_Warning;
	//  my_uint8 CAN_Frame[]={/* Id,ALL_Zones, LON_OFFSET , RV_ZONE,RV_DIRECTION*/};
	    my_uint8 DNPW_WARNING = 0;



	if((Frame[3]== AHED_LEFT )&&(Frame[4] == REVERSE))
	{
		if(Frame[2] < Frame[1])
		{
			DNPW_WARNING =1;
			if(DNPW_WARNING){

				Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_ON);
				Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed (LOW_Speed);
			}
		}
	}
	else
	{
		Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_OFF);
		Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed (HIGH_Speed);
	}

	Std_ReturnType Stutas=E_OK;
	//Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_LCD_LCD_Warning (LCD_Warning);
	return Stutas;
}
