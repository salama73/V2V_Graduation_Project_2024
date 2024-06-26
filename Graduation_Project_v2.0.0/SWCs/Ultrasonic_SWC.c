/*
 * EEBL_SWC.c
 *
 *  Created on: Mar 9, 2024
 *      Author: ELBOSTAN
 */

#include "Rte_Ultrasonic_SWC.h"
#include "Dio.h"
#include "Icu.h"
#include "delay.h"

void delay_ms1(uint8 ms)
{
	for(int i=0 ;i<ms;i++)
		for(int x=0;x<50;x++);
}

Std_ReturnType Ultrasonic_SWC(my_uint16* Distance)
{
	Std_ReturnType Stutas=E_OK;
	my_uint16 Dis;
	Icu_StartSignalMeasurement(Icu_Channel_0);
	Dio_WriteChannel(channel_29,STD_HIGH);
	delay_ms(10);
	Dio_WriteChannel(channel_29,STD_LOW);
	while(1)
	{
		Dis=Icu_GetTimeElapsed(Icu_Channel_0);
		if(Dis!=0)break;
	}
	*Distance=Dis/58;
	Icu_StopSignalMeasurement(Icu_Channel_0);
	return Stutas;
}
