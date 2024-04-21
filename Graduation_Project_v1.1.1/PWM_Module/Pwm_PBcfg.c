/******************************************************************************
* @Module      :	 Pwm
* @File Name   :	 Pwm_PBcfg.c
* @Description :	the Post-build configuration of the AUTOSAR Basic Software module PWM driver.
* Author       :	Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#include "Pwm.h"
void CH3(void)
{
	uint8 b;
	b=0;
}
Pwm_ConfigType PWM_Config=
{
	{
		{
			{PWM_FIXED_PERIOD,PwmChannelId_0,Default_Dutycycle,PWM_LOW,NULL_PTR,Default_Period,PWM_HIGH},
			{PWM_FIXED_PERIOD,PwmChannelId_1,Default_Dutycycle,PWM_LOW,NULL_PTR,Default_Period,PWM_HIGH},
			{PWM_FIXED_PERIOD,PwmChannelId_2,Default_Dutycycle,PWM_LOW,NULL_PTR,Default_Period,PWM_HIGH},
			{PWM_FIXED_PERIOD,PwmChannelId_3,Default_Dutycycle,PWM_LOW,NULL_PTR,Default_Period,PWM_HIGH}
		}
	}
};


