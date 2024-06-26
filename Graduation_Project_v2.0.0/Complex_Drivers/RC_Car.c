/*
 * RC_Car.c
 *
 *  Created on: Mar 31, 2024
 *      Author: ELBOSTAN
 */

#include "RC_Car.h"
#include "Pwm.h"
#include "Dio.h"

void Set_Speed(uint8 Speed)
{
	uint16 Duty=0;
	Duty=6553*Speed;
	Pwm_SetDutyCycle (PwmChannelId_0,Duty);
	Pwm_SetDutyCycle (PwmChannelId_1,Duty);
	Pwm_SetDutyCycle (PwmChannelId_2,Duty);
	Pwm_SetDutyCycle (PwmChannelId_3,Duty);
	if(Speed==0)
	{
		//led
		Dio_WriteChannel(channel_23,STD_HIGH);
	}
	else
	{
		//led
		Dio_WriteChannel(channel_23,STD_LOW);
	}
}
void Forward_Dir(void)
{
	Dio_WriteChannel(channel_16,STD_LOW);
	Dio_WriteChannel(channel_17,STD_HIGH);
	Dio_WriteChannel(channel_21,STD_LOW);
	Dio_WriteChannel(channel_22,STD_HIGH);
}
void Back_Dir(void)
{
	Dio_WriteChannel(channel_16,STD_HIGH);
	Dio_WriteChannel(channel_17,STD_LOW);
	Dio_WriteChannel(channel_21,STD_HIGH);
	Dio_WriteChannel(channel_22,STD_LOW);
}
void Right_Dir(void)
{
	Dio_WriteChannel(channel_16,STD_LOW);
	Dio_WriteChannel(channel_17,STD_HIGH);
	Dio_WriteChannel(channel_21,STD_HIGH);
	Dio_WriteChannel(channel_22,STD_LOW);
}
void Left_Dir(void)
{
	Dio_WriteChannel(channel_16,STD_HIGH);
	Dio_WriteChannel(channel_17,STD_LOW);
	Dio_WriteChannel(channel_21,STD_LOW);
	Dio_WriteChannel(channel_22,STD_HIGH);
}
void Stop_Car(void)
{
	Dio_WriteChannel(channel_16,STD_LOW);
	Dio_WriteChannel(channel_17,STD_LOW);
	Dio_WriteChannel(channel_21,STD_LOW);
	Dio_WriteChannel(channel_22,STD_LOW);
}
