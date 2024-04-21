/*****************************************************
 * SWC        : FCW_SWC.c
 * Author	  : Andrew Nasser
 *****************************************************
 * Port		  : PP_LED_Warning
 * Interface  :	SRI_LED_Warning
 * DataElement:	LED_Warning
 * Runnable   :	BSW_SWC_Runnable
 *****************************************************
 * Port: 		PP_Call_Subsystem
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 *****************************************************
 * Port: 		PP_Motor_Speed
 * Interface:	SRI_Motor_Speed
 * DataElement:	Motor_Speed
 * Runnable:	FCW_SWC_Runnable */
#include "Rte_FCW_SWC.h"

Std_ReturnType FCW_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Stutas=E_OK;
	my_uint8 Motor_Speed;
	my_uint8 LED_Warning;
	my_uint8 LCD_Warning;
	Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_Warning);
	Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Motor_Speed);
	Rte_IWrite_FCW_SWC_FCW_SWC_Runnable_PP_LCD_LCD_Warning(LCD_Warning);
	return Stutas;
}

