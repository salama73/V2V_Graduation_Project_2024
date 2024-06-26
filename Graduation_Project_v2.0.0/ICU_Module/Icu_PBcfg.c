/******************************************************************************
* @Module      :	 Icu
* @File Name   :	 Icu_PBcfg.c
* @Description :	 the Post-build configuration of the AUTOSAR Basic Software module Icu driver.
* Author       :	 Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#include "Icu.h"
Icu_ConfigType ICU_Config=
{
	{
		IcuMax_Channel,
		{
			{0,ICU_RISING_EDGE,ICU_MODE_SIGNAL_MEASUREMENT,FALSE,{ICU_HIGH_TIME}},
			{1,ICU_RISING_EDGE,ICU_MODE_SIGNAL_MEASUREMENT,FALSE,{ICU_HIGH_TIME}},
			{2,ICU_RISING_EDGE,ICU_MODE_SIGNAL_MEASUREMENT,FALSE,{ICU_HIGH_TIME}},
			{3,ICU_RISING_EDGE,ICU_MODE_SIGNAL_MEASUREMENT,FALSE,{ICU_HIGH_TIME}}
		}
	}
};

void Icu_SignalNotification_Channel_0(void)
{

}
