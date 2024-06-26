/******************************************************************************
* @Module      :	 ICU
* @File Name   :	 Icu.c
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
/*****************************************************************************
							Source File Version Informations
*****************************************************************************/
#define ICU_VERSION_ID							23
#define VENDOR_ID								100
#define ICU_AR_RELEASE_MAJOR_VERSION			4
#define ICU_AR_RELEASE_MINOR_VERSION			8
#define ICU_AR_RELEASE_PATCH_VERSION		    0
#define ICU_SW_RELEASE_MAJOR_VERSION			1
#define ICU_SW_RELEASE_MINOR_VERSION			0
#define ICU_SW_RELEASE_PATCH_VERSION		    0
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Icu.h"
#include "stm32f103x6.h"
/******************************************************************************
 	 	 	 	 	 	 	 	 	 Variables
******************************************************************************/
Icu_ConfigType* Icu_config;
//channel state
Icu_InputStateType Channel_config[IcuMax_Channel];
Icu_ActivationType Channel_Activation[IcuMax_Channel];
//icu state
Icu_ModeType ICU_MODE;
uint8 Icu_State=Icu_NOT_INITIALIZED;
//interrupt flag
struct
{
	uint8 CC1IF:1;
	uint8 CC2IF:1;
	uint8 CC3IF:1;
	uint8 CC4IF:1;
}Isr_Flag;
//notification flag
struct
{
	uint8 Channel_0_notification_flag:1;
	uint8 Channel_1_notification_flag:1;
	uint8 Channel_2_notification_flag:1;
	uint8 Channel_3_notification_flag:1;
}Notification_Flag;
uint16 h;
uint16 l;
uint16 Read_High;
uint16 Read_Low;
uint16 Read_Period;
typedef struct
{
	uint16 Time_Low;
	uint16 Time_High;
}Time_Measurement;
Time_Measurement Channel_Measurement[IcuMax_Channel];
/*************************************************************************************
 	 	 	 	 	 	 	 	 Local function
**************************************************************************************/

/*************************************************************************************
 	 	 	 	 	 	 	 	 APIS
*************************************************************************************/
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
void Icu_Init (const Icu_ConfigType* ConfigPtr)
{
	#if(IcuDevErrorDetect==TRUE)
	if(Icu_State==Icu_INITIALIZED)
		Det_ReportError(ICU_VERSION_ID,0, Icu_Init_ID, ICU_E_ALREADY_INITIALIZED);
	else
		Icu_config=ConfigPtr;
	#endif
	//[SWS_Icu_00061] [The function Icu_Init shall disable all notifications.]
	for(uint8 index=0;index<ConfigPtr->IcuConfigSet.IcuMaxChannel;index++)
	{
		Icu_DisableNotification(ConfigPtr->IcuConfigSet.IcuChannel[index].IcuChannelId);
	}
	//[SWS_Icu_00040] [The function Icu_Init shall set all used ICU channels to status ICU_IDLE.]
	for(uint8 index=0;index<ConfigPtr->IcuConfigSet.IcuMaxChannel;index++)
	{
		Channel_config[index]=ICU_IDLE;
	}
	//[SWS_Icu_00060] [The function Icu_Init shall set the module mode to ICU_MODE_NORMAL.]
	ICU_MODE=ICU_MODE_NORMAL;
	/*
	 [SWS_Icu_00054] ⌈The function Icu_Init shall only set the resources that are
	 configured in the configuration file (including clearing of pending interrupt flags).
	 */
	TIM3->SR=0X0000;
	//set Prescalers 7+1=8 TIM4 Clock=8mhz/8=1mh
	TIM3->PSC=7;
	//set top value
	TIM3->ARR=0XFFFF;
	//CC1,CC2,CC3 and CC4 channel is configured as input, ICx is mapped on TIx
	TIM3->CCMR1 =0x3131;
	TIM3->CCMR2 =0x3131;
	// Enable capture on CC1,CC2,CC3 and CC4
	TIM3->CCER |= (0X1111<<0);
	for(uint8 index=0;index<ConfigPtr->IcuConfigSet.IcuMaxChannel;index++)
	{
		switch (ConfigPtr->IcuConfigSet.IcuChannel[index].IcuDefaultStartEdge)
		{
		case ICU_RISING_EDGE:
			Channel_Activation[index]=ICU_RISING_EDGE;
			//non-inverted: capture is done on a rising edge of ICx.
			TIM3->CCER &=~(1<<(1+(index*4)));
			break;
		case ICU_FALLING_EDGE:
			Channel_Activation[index]=ICU_FALLING_EDGE;
			// inverted: capture is done on a falling edge of ICx.
			TIM3->CCER |=(1<<(1+(index*4)));
			break;
		default:
			break;
		}
	}
	//Capture interrupt enable
	//TIM3->DIER=0x0f;
	//isr_flag reset
	Isr_Flag.CC1IF=0;
	Isr_Flag.CC2IF=0;
	Isr_Flag.CC3IF=0;
	Isr_Flag.CC4IF=0;
	NVIC_IRQ29_TIM3_Enable();
	Icu_State=Icu_INITIALIZED;
	TIM3->CR1=1;
}
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
void Icu_DeInit (void)
{
	/*
	 [SWS_Icu_00385] [If development error detection for the Icu module is enabled:
	 This function shall raise development error ICU_E_UNINIT when the function ]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Icu_State!=Icu_INITIALIZED)
		Det_ReportError(ICU_VERSION_ID,0, Icu_DeInit_ID, ICU_E_UNINIT);
	else
		//
	#endif
	/*
	 [SWS_Icu_00036] [The function Icu_DeInit shall set the state of the peripherals
	 used by configuration as the same after power on reset.]
	 */
	TIM3->CCER=0x0000;
	TIM3->ARR=0x0000;
	TIM3->PSC=0x0000;
	TIM3->CCMR1 =0x0000;
	TIM3->CCMR2 =0x0000;
	TIM3->CR1=0x0000;
	//[SWS_Icu_00037] [The function Icu_DeInit shall disable all used interrupts and notifications.]
	for(uint8 index=0;index<Icu_config->IcuConfigSet.IcuMaxChannel;index++)
	{
		Icu_DisableNotification(Icu_config->IcuConfigSet.IcuChannel[index].IcuChannelId);
	}
}
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
void Icu_SetMode (Icu_ModeType Mode)
{
	/*
	 [SWS_Icu_00125] [If development error detection is enabled for the module Icu the
	 function Icu_SetMode shall check the parameter Mode and shall raise the error
	 ICU_E_PARAM_MODE if the parameter Mode is not within the allowed range set in the configuration.]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Mode!=ICU_MODE_SLEEP||Mode!=ICU_MODE_NORMAL)
	{
		Det_ReportError(ICU_VERSION_ID,0, Icu_SetMode_ID, ICU_E_UNINIT);
	}
	#endif
	if(Mode==ICU_MODE_NORMAL)
	{
		for(uint8 index=0;index<Icu_config->IcuConfigSet.IcuMaxChannel;index++)
		{
			Icu_EnableNotification(Icu_config->IcuConfigSet.IcuChannel[index].IcuChannelId);
		}
	}
	else if(Mode==ICU_MODE_SLEEP)
	{
		for(uint8 index=0;index<Icu_config->IcuConfigSet.IcuMaxChannel;index++)
		{
			if(Icu_config->IcuConfigSet.IcuChannel[index].IcuWakeupCapability!=TRUE)
			{
				Icu_DisableNotification(Icu_config->IcuConfigSet.IcuChannel[index].IcuChannelId);
			}
			else
			{
				//
			}
		}
	}
	else
	{
		//ERROR
	}
}
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
void Icu_SetActivationCondition (Icu_ChannelType Channel,Icu_ActivationType Activation)
{
	/*
	 [SWS_Icu_00159] [If development error detection is enabled the function
	 Icu_SetActivationCondition shall check the parameter Channel and shall raise the error
	 ICU_E_PARAM_CHANNEL if Channel is not within the range set in the configuration.]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel)
		Det_ReportError(ICU_VERSION_ID,0, Icu_SetActivationCondition_ID, ICU_E_PARAM_CHANNEL);
	#endif
	//set active edge
	Channel_Activation[Channel]=Activation;
	/*
	 [SWS_Icu_00139] [The function Icu_SetActivationCondition shall reset the
	 state for the given channel to ICU_IDLE.]
	 */
	Channel_config[Channel]=ICU_IDLE;
}
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
void Icu_DisableNotification (Icu_ChannelType Channel)
{
	/*
	 [SWS_Icu_00161] [If development error detection is enabled the function
	 Icu_DisableNotification shall check the parameter Channel and shall raise
	 the error ICU_E_PARAM_CHANNEL if Channel is invalid]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel)
		Det_ReportError(ICU_VERSION_ID,0, Icu_DisableNotification_ID, ICU_E_PARAM_CHANNEL);
	#endif
	switch (Channel)
	{
	case Icu_Channel_0:
		Notification_Flag.Channel_0_notification_flag=0;
		break;
	case Icu_Channel_1:
		Notification_Flag.Channel_1_notification_flag=0;
		break;
	case Icu_Channel_2:
		Notification_Flag.Channel_2_notification_flag=0;
		break;
	case Icu_Channel_3:
		Notification_Flag.Channel_3_notification_flag=0;
		break;
	default:
		break;
	}
}
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
void Icu_EnableNotification (Icu_ChannelType Channel)
{
	/*
	 [SWS_Icu_00161] [If development error detection is enabled the function
	 Icu_EnableNotification shall check the parameter Channel and shall raise
	 the error ICU_E_PARAM_CHANNEL if Channel is invalid]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel)
		Det_ReportError(ICU_VERSION_ID,0, Icu_EnableNotification_ID, ICU_E_PARAM_CHANNEL);
	#endif
	switch (Channel)
	{
	case Icu_Channel_0:
		Notification_Flag.Channel_0_notification_flag=1;
		break;
	case Icu_Channel_1:
		Notification_Flag.Channel_1_notification_flag=1;
		break;
	case Icu_Channel_2:
		Notification_Flag.Channel_2_notification_flag=1;
		break;
	case Icu_Channel_3:
		Notification_Flag.Channel_3_notification_flag=1;
		break;
	default:
		break;
	}
}
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
Icu_InputStateType Icu_GetInputState (Icu_ChannelType Channel)
{
	Icu_InputStateType State=0;
	/*
	 [SWS_Icu_00162] ⌈If development error detection is enabled the function
	 Icu_GetInputState shall check the parameter Channel and shall raise the error
	 ICU_E_PARAM_CHANNEL if Channel is invalid (invalid identifier or channel not
	configured for modes ICU_MODE_SIGNAL_EDGE_DETECT or ICU_MODE_SIGNAL_MEASUREMENT)
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel||Icu_config->IcuConfigSet.IcuChannel[Channel].IcuMeasurementMode!=ICU_MODE_SIGNAL_MEASUREMENT)
		Det_ReportError(ICU_VERSION_ID,0, Icu_GetInputState_ID, ICU_E_PARAM_CHANNEL);
	#endif
	/*
	 [SWS_Icu_00313] [Icu_GetInputState shall return Icu_InputStateType
	 which will have value ICU_IDLE when no activation edge has been detected since
	 the last call of Icu_GetInputState() or Icu_Init().]
	 */
	State=Channel_config[Channel];
	/*
	 [SWS_Icu_00032] [Once the function Icu_GetInputState has returned the
	 status ICU_ACTIVE, the function Icu_GetInputState shall set the stored status
`    to ICU_IDLE until the next edge is detected.]
	 */
	Channel_config[Channel]=ICU_IDLE;
	return State;
}
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
void Icu_StartSignalMeasurement (Icu_ChannelType Channel)
{
	/*
	 [SWS_Icu_00176] If development error detection is enabled, the function
	 Icu_StartSignalMeasurement shall check the parameter Channel. If Channel
	 is invalid (invalid identifier or channel not configured for mode ICU_MODE_SIGNAL_MEASUREMENT
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel||Icu_config->IcuConfigSet.IcuChannel[Channel].IcuMeasurementMode!=ICU_MODE_SIGNAL_MEASUREMENT)
		Det_ReportError(ICU_VERSION_ID,0, Icu_StartSignalMeasurement_ID, ICU_E_PARAM_CHANNEL);
	#endif
	/*
	 [SWS_Icu_00146] [The function Icu_StartSignalMeasurement shall reset the
	 state for the given channel to ICU_IDLE.]
	 */
	Channel_config[Channel]=ICU_IDLE;
	//Capture interrupt enable
	TIM3->DIER |=1<<(Channel+1);
}
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
void Icu_StopSignalMeasurement (Icu_ChannelType Channel)
{
	/*
	 [SWS_Icu_00144] [The function Icu_StopSignalMeasurement shall only be
	 available in Measurement Mode”ICU_MODE_SIGNAL_MEASUREMENT”]
	 */
	/*
	 [SWS_Icu_00176] If development error detection is enabled, the function
	 Icu_StopSignalMeasurement shall check the parameter Channel. If Channel
	 is invalid (invalid identifier or channel not configured for mode ICU_MODE_SIGNAL_MEASUREMENT
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel||Icu_config->IcuConfigSet.IcuChannel[Channel].IcuMeasurementMode!=ICU_MODE_SIGNAL_MEASUREMENT)
		Det_ReportError(ICU_VERSION_ID,0, Icu_StopSignalMeasurement_ID, ICU_E_PARAM_CHANNEL);
	#endif
	//Capture interrupt disable
	TIM3->DIER &=~(1<<(Channel+1));
}
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
Icu_ValueType Icu_GetTimeElapsed (Icu_ChannelType Channel)
{
	Icu_ValueType Icu_Read=0;
	/*
	 [SWS_Icu_00178] [If development error detection is enabled, the parameter
	 Channel shall be checked by this service. If Channel is invalid (invalid identifier or
	 channel not configured for mode ICU_MODE_SIGNAL_MEASUREMENT), then the error
	 ICU_E_PARAM_CHANNEL shall be reported to the Default Error Tracer.]
	 */
	#if(IcuDevErrorDetect==TRUE)
	if(Channel>IcuMax_Channel||Icu_config->IcuConfigSet.IcuChannel[Channel].IcuMeasurementMode!=ICU_MODE_SIGNAL_MEASUREMENT)
		Det_ReportError(ICU_VERSION_ID,0, Icu_GetTimeElapsed_ID, ICU_E_PARAM_CHANNEL);
	#endif
	/*
	 [SWS_Icu_00136][The function Icu_GetTimeElapsed shall return “0” in case no requested time has been captured]
	 [SWS_Icu_00339][The function Icu_GetTimeElapsed shall return “0” in case the
	 capturing of a requested time is ongoing and not finished]
	 */
	if(Channel_config[Channel]==ICU_IDLE)
	{
		return 0;
	}
	else
	{
		/*
		 [SWS_Icu_00081]Signal Low Time--->> Return Signal Low Time
		 [SWS_Icu_00082]Signal High Time--->> Return Signal High Time
		 */
		switch (Icu_config->IcuConfigSet.IcuChannel[Channel].IcuSignal_Measurement.IcuSignalMeasurementProperty)
		{
		case ICU_LOW_TIME:
			Icu_Read=Channel_Measurement[Channel].Time_Low;
			break;
		case ICU_HIGH_TIME:
			Icu_Read=Channel_Measurement[Channel].Time_High;
			break;
		default:
			break;
		}
		Channel_config[Channel]=ICU_IDLE;
		return Icu_Read;
	}
}
/************************************************************************
* Service Name		:	TIM3_IRQHandler
* * Parameters (in) :	None
* Parameters (inout):	None
* Parameters (out)	:	None
* Return value		:	None
* Description		:	The ISRs shall reset the interrupt flags (if needed by hardware)
						and call the corresponding notification functions
***********************************************************************/
void TIM3_IRQHandler(void)
{
	//check flag for channel 0
	if((TIM3->SR&(1<<1))!=0)
	{
		//First edge for signal
		if(Isr_Flag.CC1IF==0)
		{
			//measurement of signals beginning with the configured default start edge(ICU_RISING_EDGE).
			if(Channel_Activation[0]==ICU_RISING_EDGE)
			{
				// Capture at Rising Edge
				l=TIM3->CCR1;
				if(h>l)
					Read_Low=(0xffff-h)+l;
				else
					Read_Low=l-h;
				// Capture Signal Low Time
				Channel_Measurement[0].Time_High=Read_Low;
				TIM3->SR &=~(1<<1);
				//FALLING_EDGE
				TIM3->CCER |=(1<<1);
			}
			//measurement of signals beginning with the configured default start edge(ICU_FALLING_EDGE).
			else if(Channel_Activation[0]==ICU_FALLING_EDGE)
			{
				// Capture at Falling Edge
				h=TIM3->CCR1;
				if(l>h)
					Read_Low=(0xffff-l)+h;
				else
					Read_Low=h-l;
				// Capture Signal High Time
				Channel_Measurement[0].Time_High=Read_High;
				TIM3->SR &=~(1<<1);
				//RISING_EDGE
				TIM3->CCER &=~(1<<1);
			}
			else
			{
				//Later
			}
			Isr_Flag.CC1IF=1;
		}
		else if(Isr_Flag.CC1IF==1)
		{
			//measurement of signals beginning with the second edge.
			if(Channel_Activation[0]==ICU_RISING_EDGE)
			{
				TIM3->SR &=~(1<<1);
				// Capture at Falling Edge
				h=TIM3->CCR1;
				if(l>h)
					Read_High=(0xffff-l)+h;
				else
					Read_High=h-l;
				// Capture Signal High Time
				Channel_Measurement[0].Time_High=Read_High;
				//RISING_EDGE
				TIM3->CCER &=~(1<<1);
			}
			else if(Channel_Activation[0]==ICU_FALLING_EDGE)
			{
				// Capture at Rising Edge
				l=TIM3->CCR1;
				if(h>l)
					Read_Low=(0xffff-h)+l;
				else
					Read_Low=l-h;
				// Capture Signal Low Time
				Channel_Measurement[0].Time_High=Read_Low;
				TIM3->SR &=~(1<<1);
				//FALLING_EDGE
				TIM3->CCER |=(1<<1);
			}
			else
			{
				//
			}
			Isr_Flag.CC1IF=0;
			Read_Period=Read_Low+Read_High;
			// An activation edge has been detected
			Channel_config[0]=ICU_ACTIVE;
			//call notification function for channel 0
			if(Notification_Flag.Channel_0_notification_flag==1)
			{
				Icu_SignalNotification_Channel_0();
			}
		}
		else
		{
			//Error
		}
	}
	else if((TIM3->SR&(1<<2))!=0)
	{
		//The counter value has been captured in TIMx_CCR2
	}
	else if((TIM3->SR&(1<<3))!=0)
	{
		//The counter value has been captured in TIMx_CCR3
	}
	else if((TIM3->SR&(1<<4))!=0)
	{
		//The counter value has been captured in TIMx_CCR4
	}
	else
	{
		//
	}
}

