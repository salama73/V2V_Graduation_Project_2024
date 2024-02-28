/*****************************************************
 * SWC        : BSW_SWC.c
 * Created on : 28/2/2024
 * Author	  : Salama Mohamed
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
 * Runnable:	BSW_SWC_Runnable
 *****************************************************/
/******************************************************
 *********************Include**************************
 ******************************************************/
#include "Rte_BSW_SWC.h"
/*******************************************************
 **********************Definitions**********************
 *******************************************************/
#define LED_BSW_ON (uint8)1
#define LED_BSW_OFF (uint8)0
#define LOW_Speed (uint8)2
#define HIGH_Speed (uint8)4
uint8 FRAME[2]={0};
/*******************************************************
 **********************Runnable*************************
 *******************************************************/
Std_ReturnType BSW_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Stutas=E_OK;
	for(int i=0;i<2;i++)
		FRAME[i]=CAN_Frame[i];
	switch (FRAME[1])
	{
		case TRUE:
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_BSW_ON);
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(LOW_Speed);
			break;
		case FALSE:
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_BSW_OFF);
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(HIGH_Speed);
			break;
		default:
			Stutas=E_NOT_OK;
			break;
	}
	return Stutas;
}
