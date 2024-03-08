/*
 * EEBL_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */


#include "Rte_EEBL_SWC.h"

Std_ReturnType EEBL_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Stutas=E_OK;
	my_uint8 Motor_Speed;
	my_uint8 LED_Warning;
	my_uint8 LCD_Warning;
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_Warning);
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Motor_Speed);
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning(LCD_Warning);
	return Stutas;
}
