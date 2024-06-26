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
#include "Dio.h"
/*******************************************************
 **********************Definitions**********************
 *******************************************************/
#define LED_ON               1
#define LED_OFF              0
#define Stop                 0
#define LOW_Speed            1
#define HIGH_Speed           2
#define Super_Speed          3
uint8 FRAME[2]={0};
my_uint16 Dis=0;
/*******************************************************
 **********************Runnable*************************
 *******************************************************/
Std_ReturnType BSW_SWC(const my_uint8* CAN_Frame)
{
	Std_ReturnType Status=E_OK;
	for(int i=0;i<2;i++)
		FRAME[i]=CAN_Frame[i];
	//Status=Rte_Call_BSW_SWC_RP_Get_Distance_Call_Ultrasonic(&Dis);
	switch (FRAME[1])
	{
		case TRUE:
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_ON);
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(Stop);
			break;
		case FALSE:
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(LED_OFF);
			Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(HIGH_Speed);
			break;
		default:
			Status=E_NOT_OK;
			break;
	}
	/*
	if(Dis<20)
	{
		Dio_WriteChannel(channel_45,STD_LOW);
	}
	else
	{
		Dio_WriteChannel(channel_45,STD_HIGH);
	}
	return Status;
	*/
}
