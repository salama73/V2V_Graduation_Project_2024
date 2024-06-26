/******************************************************************************
* @Module      :	 ICU
* @File Name   :	 Icu._Cfgh
* @Description :	the Pre-compile configuration of the AUTOSAR Basic Software module PWM Driver.
* Author       :	Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#ifndef ICU_CFG_H_
#define ICU_CFG_H_
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Std_Types.h"
/******************************************************************************
			Pre-compile configuration parameters of the Icu driver.
*******************************************************************************/
#define IcuMax_Channel					(uint8)4
#define Icu_Channel_0					(uint8)0
#define Icu_Channel_1					(uint8)1
#define Icu_Channel_2					(uint8)2
#define Icu_Channel_3					(uint8)3
//Switches the development error detection and notification on or off.
#define IcuDevErrorDetect				TRUE
//Switch for enabling Wakeup source reporting.
#define IcuReportWakeupSource			FALSE
//Adds / removes the service Icu_DeInit() from the code.
#define IcuDeInitApi					TRUE
//Adds / removes the service Icu_DisableWakeup() from the code.
#define IcuDisableWakeupApi				FALSE
//Adds / removes all services related to the edge counting functionality from the code.
#define IcuEdgeCountApi 				FALSE
//Adds / removes the services related to the edge detection functionality, from the code:
#define IcuEdgeDetectApi				TRUE
//Adds / removes the service Icu_EnableWakeup() from the code.
#define IcuEnableWakeupApi				FALSE
//Adds / removes the service Icu_GetDutyCycleValues() from the code.
#define IcuGetDutyCycleValuesApi		TRUE
//Adds / removes the service Icu_GetInputState() from the code.
#define IcuGetInputStateApi				TRUE
//Adds / removes the service Icu_GetTimeElapsed() from the code.
#define IcuGetTimeElapsedApi			TRUE
//Adds / removes the service Icu_GetVersionInfo() from the code
#define IcuGetVersionInfoApi			FALSE
//Adds / removes the service Icu_SetMode() from the code.
#define IcuSetModeApi				    TRUE
//Adds / removes the services Icu_StartSignalMeasurement() and Icu_StopSignal Measurement() from the code.
#define IcuSignalMeasurementApi			TRUE
//Adds / removes all services related to the timestamping functionality from the code.
#define IcuTimestampApi					TRUE
//Adds / removes the service Icu_CheckWakeup() from the code.
#define IcuWakeupFunctionalityApi		FALSE
#endif /* ICU_CFG_H_ */
