/*****************************************************
 * SWC        : LED_SWC.c
 * Created on : 28/2/2024
 * Author	  : Salama Mohamed
 *****************************************************/
/******************************************************
 *********************Include**************************
 ******************************************************/
#include "Rte_LED_SWC.h"
#include "Dio.h"
/*******************************************************
 **********************Definitions**********************
 *******************************************************/
#define LED_BSW_ON (uint8)1
#define LED_BSW_OFF (uint8)0
/*******************************************************
 **********************Runnable*************************
 *******************************************************/
void LED_SWC(void)
{
	uint8 LED_Status;
	LED_Status=Rte_IRead_LED_SWC_LED_SWC_Runnable_RP_LED_Warning_LED_Warning();
	switch (LED_Status)
	{
		case LED_BSW_ON:
			Dio_WriteChannel(channel_45,STD_LOW);
			break;
		case LED_BSW_OFF:
			Dio_WriteChannel(channel_45,STD_HIGH);
			break;
		default:
			break;
	}
}
