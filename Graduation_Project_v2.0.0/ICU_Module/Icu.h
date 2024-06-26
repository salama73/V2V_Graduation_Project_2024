/******************************************************************************
* @Module      :	 ICU
* @File Name   :	 Icu.h
* @Description :	This specification specifies the functionality, API and the configuration of the
					AUTOSAR Basic Software module ICU driver.
* Author       :	Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#ifndef ICU_H_
#define ICU_H_
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Std_Types.h"
#include "Det.h"
#include "Icu_Cfg.h"
/******************************************************************************
                      API Service Id Macros
******************************************************************************/
#define Icu_Init_ID									(uint8)0x00
#define Icu_DeInit_ID								(uint8)0x01
#define Icu_SetMode_ID								(uint8)0x02
#define Icu_SetActivationCondition_ID				(uint8)0x05
#define Icu_DisableNotification_ID					(uint8)0x06
#define Icu_EnableNotification_ID					(uint8)0x07
#define Icu_GetInputState_ID						(uint8)0x08
#define Icu_StartTimestamp_ID						(uint8)0x09
#define Icu_StopTimestamp_ID						(uint8)0x0a
#define Icu_GetTimestampIndex_ID					(uint8)0x0b
#define Icu_StartSignalMeasurement_ID				(uint8)0x13
#define Icu_StopSignalMeasurement_ID				(uint8)0x14
#define Icu_GetTimeElapsed_ID						(uint8)0x10
#define Icu_GetDutyCycleValues_ID					(uint8)0x11
/*******************************************************************************
                      DET Error Codes
*******************************************************************************/
//API IS called with invalid pointer.
#define ICU_E_PARAM_POINTER							(uint8)0x0a
//API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API.
#define ICU_E_PARAM_CHANNEL							(uint8)0x0b
//API service used with an invalid or not feasible activation.
#define ICU_E_PARAM_ACTIVATION 						(uint8)0x0c
//Init function failed.
#define ICU_E_INIT_FAILED							(uint8)0x0d
//API service used with an invalid buffer size.
#define ICU_E_PARAM_BUFFER_SIZE						(uint8)0x0e
//API service Icu_SetMode used with an invalid mode.
#define ICU_E_PARAM_MODE							(uint8)0x0f
//API service used without module initialization
#define ICU_E_UNINIT								(uint8)0x14
//API service Icu_SetMode is called while a running operation.
#define ICU_E_BUSY_OPERATION 						(uint8)0x16
//API Icu_Init service is called and when the ICU driver and the Hardware are already initialized.
#define ICU_E_ALREADY_INITIALIZED 					(uint8)0x17
//API Icu_StartTimeStamp is called and the parameter Notify Interval is invalid
#define ICU_E_PARAM_NOTIFY_INTERVAL					(uint8)0x18
//API Icu_GetVersionInfo is called and the parameter version info is is invalid
#define ICU_E_PARAM_VINFO							(uint8)0x19
//API service Icu_StopTimestamp called on a channel which was not started or already stopped
#define ICU_E_NOT_STARTED							(uint8)0x15
/*****************************************************************************
							 Type definitions
*****************************************************************************/
#define Icu_NOT_INITIALIZED	0U
#define Icu_INITIALIZED		1U
// Allow enabling / disabling of all interrupts which are not required for the ECU wakeup.
typedef enum
{
	// Normal operation, all used interrupts are enabled according to the notification requests.
	ICU_MODE_NORMAL,
	/*
	 Reduced power operation. In sleep mode only those
	 notifications are available which are configured as wakeup capable.
	 */
	ICU_MODE_SLEEP
}Icu_ModeType;
/*
 Numeric identifier of an ICU channel.
 Comment:
 This is implementation specific but not all values may be valid within the type.
 This type shall be chosen in order to have the most efficient implementation on
 a specific microcontroller platform.
 */
typedef uint8 Icu_ChannelType;
// Input state of an ICU channel
typedef enum
{
	// An activation edge has been detected
	ICU_ACTIVE,
	/*
	 No activation edge has been detected since the last call of Icu_
	 GetInputState() or Icu_Init().
	 */
	ICU_IDLE
}Icu_InputStateType;
// Definition of the type of activation of an ICU channel.
typedef enum
{
	//An appropriate action shall be executed when a rising edge occurs on the ICU input signal.
	ICU_RISING_EDGE,
	// An appropriate action shall be executed when a falling edge occurs on the ICU input signal.
	ICU_FALLING_EDGE,
	// An appropriate action shall be executed when either a rising or falling edge occur on the ICU input signal.
	ICU_BOTH_EDGES
}Icu_ActivationType;
// Width of the buffer for timestamp ticks and measured elapsed timeticks.(0 ... <width of the timer register>)
typedef uint16 Icu_ValueType;
//Type which shall contain the values, needed for calculating duty cycles.
typedef struct
{
	// This shall be the coherent active-time measured on a channel
	Icu_ValueType ActiveTime;
	// This shall be the coherent period-time measured on a channel
	Icu_ValueType PeriodTime;
}Icu_DutyCycleType;
// Definition of the measurement mode type
typedef enum
{
	// Mode for detecting edges
	ICU_MODE_SIGNAL_EDGE_DETECT,
	// Mode for measuring different times between various configurable edges
	ICU_MODE_SIGNAL_MEASUREMENT,
	// Mode for capturing timer values on configurable edges
	ICU_MODE_TIMESTAMP,
	// Mode for counting edges on configurable edges
	ICU_MODE_EDGE_COUNTER
}Icu_MeasurementModeType;
// Definition of the measurement property type
typedef enum
{
	// The channel is configured for reading the elapsed Signal Low Time
	ICU_LOW_TIME,
	// The channel is configured for reading the elapsed Signal High Time
	ICU_HIGH_TIME,
	// The channel is configured for reading the elapsed Signal Period Time
	ICU_PERIOD_TIME,
	//The channel is configured to read values which are needed for calculating the duty cycle (coherent Active and Period Time
	ICU_DUTY_CYCLE
}Icu_SignalMeasurementPropertyType;
// Definition of the timestamp measurement property type
typedef enum
{
	// The buffer will just be filled once
	ICU_LINEAR_BUFFER,
	// After reaching the end of the buffer, the driver restarts at the beginning of the buffer
	ICU_CIRCULAR_BUFFER
}Icu_TimestampBufferType;
/************************************************************************************
Name			:           	IcuSignalMeasurement
Parent Container: 				IcuChannel
Description		:				This container contains the configuration (parameters) in case
								the measurement mode is "IcuSignalMeasurement"
Type			:               Container
*************************************************************************************/
typedef struct
{
	/*
	 Configures the property that could be measured in case the mode is "IcuSignal
	 Measurement". This property can not be changed during runtime.
	 */
	Icu_SignalMeasurementPropertyType IcuSignalMeasurementProperty;
}IcuSignalMeasurement;
/************************************************************************************
Name			:           	IcuChannel
Parent Container: 				IcuConfigSet
Description		:				Configuration of an individual ICU channel.
Type			:               Container
*************************************************************************************/
typedef struct
{
	//Channel Id of the ICU channel.
	Icu_ChannelType IcuChannelId;
	/*
	 Configures the default-activation-edge which shall be used for this channel if
	 there was no activation-edge configured by the call of service Icu_SetActivation Condition().
	 */
	Icu_ActivationType IcuDefaultStartEdge;
	//Configures the measurement mode of this channel.
	Icu_MeasurementModeType IcuMeasurementMode;
	//Information about the wakeup-capability of this channel.
	boolean IcuWakeupCapability;
	//Information about Signal Measurement
	IcuSignalMeasurement IcuSignal_Measurement;
}IcuChannel;
/************************************************************************************
Name			:           	IcuConfigSet
Parent Container: 				ICU
Description		:				This container contains the configuration parameters and
								sub containers of the AUTOSAR ICU module.
Type			:               Container
*************************************************************************************/
typedef struct
{
	//This parameter contains the number of Channels configured
	Icu_ChannelType IcuMaxChannel;
	//Configuration of an individual ICU channel.
	IcuChannel IcuChannel[IcuMax_Channel];
}IcuConfigSet;

/*
  This type contains initialization data.
  Comment:
  Hardware and implementation dependent structure. The contents of the
  initialization data structure are microcontroller specific.
 */
typedef struct
{
	IcuConfigSet IcuConfigSet;
}Icu_ConfigType;
/*************************************************************************
                               APIS
*************************************************************************/
//callback notification
void Icu_SignalNotification_Channel_0(void);
void Icu_SignalNotification_Channel_1(void);
void Icu_SignalNotification_Channel_2(void);
void Icu_SignalNotification_Channel_3(void);
/************************************************************************
* Service ID [hex]	:	0x00
* Service Name		:	Icu_Init
* Sync/Async		:	Synchronous
* Reentrancy		:	Non Reentrant
* Parameters (in)	:	ConfigPtr
 	 	 	 	 	 	Pointer to a selected configuration structure
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function initializes the driver.
***********************************************************************/
void Icu_Init (const Icu_ConfigType* ConfigPtr);
/************************************************************************
* Service ID [hex]	:	0x01
* Service Name		:	Icu_DeInit
* Sync/Async		:	Synchronous
* Reentrancy		:	Non Reentrant
* Parameters (in)	:	None
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function de-initializes the ICU module.
***********************************************************************/
void Icu_DeInit (void);
/************************************************************************
* Service ID [hex]	:	0x02
* Service Name		:	Icu_SetMode
* Sync/Async		:	Synchronous
* Reentrancy		:	Non Reentrant
* Parameters (in)	:	Mode
 	 	 	 	 	 	ICU_MODE_NORMAL or ICU_MODE_SLEEP
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function sets the ICU mode.
***********************************************************************/
void Icu_SetMode (Icu_ModeType Mode);
/************************************************************************
* Service ID [hex]	:	0x05
* Service Name		:	Icu_SetActivationCondition
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel-->Numeric identifier of the ICU channel
 	 	 	 	 	 	Activation-->Type of activation
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function sets the activation-edge for the given channel.
***********************************************************************/
void Icu_SetActivationCondition (Icu_ChannelType Channel,Icu_ActivationType Activation);
/************************************************************************
* Service ID [hex]	:	0x06
* Service Name		:	Icu_DisableNotification
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channe
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function disables the notification of a channel.
***********************************************************************/
void Icu_DisableNotification (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x07
* Service Name		:	Icu_EnableNotification
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channe
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function enables the notification on the given channel.
***********************************************************************/
void Icu_EnableNotification (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x02
* Service Name		:	Icu_GetInputState
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channel
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	Icu_InputStateType
						ICU_ACTIVE or ICU_IDLE
* Description		:	 This function returns the status of the ICU input.
***********************************************************************/
Icu_InputStateType Icu_GetInputState (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x13
* Service Name		:	Icu_StartSignalMeasurement
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channel
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function starts the measurement of signals.
***********************************************************************/
void Icu_StartSignalMeasurement (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x14
* Service Name		:	Icu_StopSignalMeasurement
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channel
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	This function stops the measurement of signals of the given channel.
***********************************************************************/
void Icu_StopSignalMeasurement (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x10
* Service Name		:	Icu_GetTimeElapsed
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channel
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	see Description
* Description		:	This function reads the elapsed Signal Low Time for the given channel.
***********************************************************************/
Icu_ValueType Icu_GetTimeElapsed (Icu_ChannelType Channel);
/************************************************************************
* Service ID [hex]	:	0x11
* Service Name		:	Icu_GetDutyCycleValues
* Sync/Async		:	Synchronous
* Reentrancy		:	Reentrant
* Parameters (in)	:	Channel
 	 	 	 	 	 	Numeric identifier of the ICU channel
* Parameters (inout):	None
* Parameters (out)	:	DutyCycleValues
						Pointer to a buffer where the results
* Return value		:	None
* Description		:	This function stops the measurement of signals of the given channel.
***********************************************************************/
void Icu_GetDutyCycleValues (Icu_ChannelType Channel,Icu_DutyCycleType* DutyCycleValues);

#endif /* ICU_H_ */
