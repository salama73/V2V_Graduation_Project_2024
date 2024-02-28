/******************************************************************************
* @Module      			: CAN
* @File Name   			: Can.c
* @Description 			: This specification specifies the functionality, API and the configuration of the AUTOSAR
				 	 	  Basic Software module CAN Driver.
* Author       			: Salama Mohamed
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
#define CAN_VERSION_ID							11
#define CAN_AR_RELEASE_MAJOR_VERSION			4
#define CAN_AR_RELEASE_MINOR_VERSION			8
#define CAN_AR_RELEASE_PATCH_VERSION		    0
#define CAN_SW_RELEASE_MAJOR_VERSION			1
#define CAN_SW_RELEASE_MINOR_VERSION			0
#define CAN_SW_RELEASE_PATCH_VERSION		    0
#define VENDOR_ID								100
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Can.h"
#include "stm32f103x6.h"
/******************************************************************************
 	 	 	 	 	 	 	 	 	 Variables
 ****************************************************************************/
CanDriverStateType CanDriverState = CAN_UNINIT;
Can_ControllerStateType Can_Controller_State=CAN_CS_UNINIT;
Can_ConfigType CAN_HW_Unit_settings;
uint8 Controller_Index;
CanObjectType Hardware_Object_Type;
MessageObject Message_Object[Max_Num_HOH];
Message_Object_Status Message_ObjectStatus[Max_Num_HOH];
uint8 Interrupt_Enable_Counter=0;
uint8 Interrupt_Disable_Counter=0;
/*************************************************************************************
 	 	 	 	 	 	 	 	 Local function
************************************************************************************/
/**================================================================
* @Fn				-MCAL_CAN_Get_TX_Mailboxes_Empty
* @brief		  	-Queries and returns the number of available empty transmit mailboxes in the CAN unit
* 					 Transmi_mailbox_0,Transmi_mailbox_1 or Transmi_mailbox_2
* @retval 			-Can_Status_t	The number of an empty transmit mailbox (Transmi_mailbox_0,Transmi_mailbox_1 or Transmi_mailbox_2)
* Note				-None
*/
uint8 MCAL_CAN_Get_TX_Mailboxes_Empty(void)
{
	if(CAN_TSR & 1<<26)
		return Transmi_mailbox_0;
	else if (CAN_TSR & 1<<27)
		return Transmi_mailbox_1;
	else if (CAN_TSR & 1<<28)
		return Transmi_mailbox_2;
	else
		return Transmi_mailbox_Full;
}
/**================================================================
* @Fn				-MCAL_CAN_Add_TX_Message
* @brief		  	-Adds a new transmit message to the CAN transmit mailbox with the provided data
* 					 and retrieves the assigned mailbox.
* @param [in] 		-Message_Info: Pointer to a structure containing information about the CAN message,
* 					 including ID , ID Type , DLC, and transmission mode.
* @param [in] 		-Data: Pointer to an array containing the data to be transmitted.
* @param [output] 	-pMailbox: Pointer to a variable that will store the assigned transmit mailbox number.
* @retval 			-Can_Status_t	status of Can hardware (CAN_OK,CAN_ERROR,...)
* Note				-None
*/
Std_ReturnType MCAL_CAN_Add_TX_Message(MessageObject* Message_Info, uint8 Mailbox)
{
	Std_ReturnType status;
	status=E_OK;
	CAN_TX_mailbox_TypeDef* Current_Mailboxe=NULL_PTR;
	switch (Mailbox)
	{
		case Transmi_mailbox_0:
			Current_Mailboxe=CAN_TX_mailbox_0;
			break;
		case Transmi_mailbox_1:
			Current_Mailboxe=CAN_TX_mailbox_1;
			break;
		case Transmi_mailbox_2:
			Current_Mailboxe=CAN_TX_mailbox_2;
			break;
		default:
			status=E_NOT_OK;
			break;
	}
	//reset Current Mailboxe
	Current_Mailboxe->CAN_TDHxR=0X00000000;
	Current_Mailboxe->CAN_TDLxR=0X00000000;
	Current_Mailboxe->CAN_TDTxR=0X00000000;
	Current_Mailboxe->CAN_TIxR=0X00000000;
	//set the type of frame
	switch (Message_Info->RTR)
	{
		case CAN_RTR_Remote_Frame:
			Current_Mailboxe->CAN_TIxR |=(1<<1);
			break;
		case CAN_RTR_Data_Frame:
			Current_Mailboxe->CAN_TIxR &=~(1<<1);
			break;
		default:
			status=E_NOT_OK;
			break;
	}
	//set the identifier
	switch (Message_Info->IDE)
	{
		case CAN_IDE_Standard:
			Current_Mailboxe->CAN_TIxR &=~(1<<2);
			Current_Mailboxe->CAN_TIxR |=(uint32)(Message_Info->ID<<21);
			break;
		case CAN_IDE_Extended:
			Current_Mailboxe->CAN_TIxR |=(1<<2);
			Current_Mailboxe->CAN_TIxR |=(uint32)(Message_Info->ID<<3);
			break;
		default:
			status=E_NOT_OK;
			break;
	}
	//length of the frame
	Current_Mailboxe->CAN_TDTxR |=(Message_Info->DLC<<0);
	//Data
	for(uint8 i=0 ; i<(uint8)Message_Info->DLC ; i++)
	{
		if(i<4)
		{
			Current_Mailboxe->CAN_TDLxR |=Message_Info->SDU[i]<<(8*i);
		}
		else
		{
			Current_Mailboxe->CAN_TDHxR |=Message_Info->SDU[i]<<(8*(i-4));
		}
	}
	// Transmit mailbox request
	Current_Mailboxe->CAN_TIxR |=(1<<0);
	return status;
}
/*************************************************************************************
 	 	 	 	 	 	 	 	 APIS
************************************************************************************/
/*
 * Service name     	: Can_Init
 * Service ID[hex]   	: 0x00
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Non Reentrant
 * Parameters (in)   	: Config
                          Pointer to driver configuration.
 * Parameters (inout)	: None
 * Parameters (out)  	: None
 * Return value     	: None
 * Description       	: This function initializes the module.
 */
void Can_Init (const Can_ConfigType* Config)
{
	uint32 CAN_BTR_temp=0;
	uint32 Prescaler=0;
	uint32 BaudRate=0;
	uint32 Bits_Timing=0;
	#if(CanDevErrorDetect==STD_ON)
		if(NULL_PTR==Config)
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Init_ID,CAN_E_PARAM_POINTER);
		/*
		 [SWS_Can_00174] [ If development error detection for the Can module is enabled:
		  The function Can_Init shall raise the error CAN_E_TRANSITION if the driver is not in
		  state CAN_UNINIT ]
		 */
		if(CanDriverState!=CAN_UNINIT)
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Init_ID,CAN_E_TRANSITION);
		/*
		 [SWS_Can_00408] [ If development error detection for the Can module is enabled:
		  The function Can_Init shall raise the error CAN_E_TRANSITION if the CAN
		  controllers are not in state UNINIT]
		*/
		if(Can_Controller_State!=CAN_CS_UNINIT)
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Init_ID,CAN_E_TRANSITION);
	#endif
	/*
	 The Can module configuration defines the global CAN HW Unit settings and
	 references to the default CAN controller configuration sets.
	 */
	CAN_HW_Unit_settings=*Config;
	//CAN controller is used in the configuration.
	if(TRUE==Config->CanConfigSet.CanController.CanControllerActivation)
	{
		// Enable Can peripheral clock
		RCC_CAN_CLK_Enable();
		//Software sets this bit to request the CAN hardware to enter initialization mode.
		CAN_MCR &=~(1<<1);
		CAN_MCR |=(1<<0);
		//CAN bit timing register (baud Rate)
		CAN_BTR_temp=CAN_BTR;
		CAN_BTR_temp &=0XC0000000;
		//set Prescaler
		Bits_Timing=Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerPropSeg;
		Bits_Timing+=Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerSeg1;
		Bits_Timing+=Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerSeg2;
		BaudRate=Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerBaudRate;
		Prescaler=(8000000)/(Bits_Timing*1000*BaudRate);
		CAN_BTR_temp |=(Prescaler-1)<<0;
		//set TimeSeg1
		CAN_BTR_temp |=(Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerSeg1-1)<<16;
		//set TimeSeg2
		CAN_BTR_temp |=(Config->CanConfigSet.CanController.CanControllerDefaultBaudrate->CanControllerSeg2-1)<<20;
		CAN_BTR=CAN_BTR_temp;
		/*
		 Configure CAN operating mode
		 */
		//CAN_MODE_Loop_back_Silent for test
		CAN_BTR |=(1<<31);
		CAN_BTR |=(1<<30);
		/*
		 enable Transmit interrupt
		 */
		CAN_IER |=(1<<0);
		NVIC_IRQ19_CAN_TX_Enable();
		/*
		 enable Receive Fifo 0 interrupt
		 */
		//FIFO message pending interrupt enable
		CAN_IER |=(1<<1);
		//FIFO full interrupt enable
		CAN_IER |=(1<<2);
		//FIFO overrun interrupt enable
		CAN_IER |=(1<<3);
		NVIC_IRQ20_CAN_RX0_Enable();
		/*
		 enable Receive Fifo 1 interrupt
		 */
		//FIFO message pending interrupt enable
		CAN_IER |=(1<<4);
		//FIFO full interrupt enable
		CAN_IER |=(1<<5);
		//FIFO overrun interrupt enable
		CAN_IER |=(1<<6);
		NVIC_IRQ21_CAN_RX1_Enable();
	}
	else
	{
		//
	}
    // Hardware Object
    for (int i = 0; i < Max_Num_HOH ; i++)
    {
    	// Set Message Objects as Free
    	Message_ObjectStatus[i].Object_Free= TRUE;
    }
    /*
    [SWS_Can_00246] The function Can_Init shall change the module state to
    CAN_READY, after initializing all controllers inside the HW Unit.
    */
    CanDriverState=CAN_READY;
	Can_Controller_State=CAN_CS_STOPPED;
}
/********************************************************************************
 * Service ID [hex] 	: 0x10
 *  Service name      	: Can_DeInit
 *  Sync/Async        	: Synchronous
 *  Reentrancy        	: Non-Reentrant
 *  Parameters (in)   	: None
 *  Parameters (inout)	: None
 *  Parameters (out)  	: None
 *  Return value      	: None
 *  Description      	: This function de-initializes the module.
*******************************************************************************/
void Can_DeInit (void)
{
#if(CanDevErrorDetect==STD_ON)
	/*
	[SWS_Can_91011] If development error detection for the Can module is enabled:
	The function Can_DeInit shall raise the error CAN_E_TRANSITION if the driver is not
	in state CAN_READY
	*/
	if(CanDriverState!=CAN_READY)
	{
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_DeInit_ID,CAN_E_TRANSITION);
	}
	else
	{
		//
	}
	/*
	 [SWS_Can_91012] If development error detection for the Can module is enabled:
	 The function Can_DeInit shall raise the error CAN_E_TRANSITION if any of the CAN
	 controllers is in state STARTED
	 */
	if(Can_Controller_State==CAN_CS_STARTED)
	{
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_DeInit_ID,CAN_E_TRANSITION);
	}
	else
	{
		//
	}
#endif
	// disable Transmit interrupt
	CAN_IER &=~(1<<0);
	// Transmit global interrupt disable
	NVIC_IRQ19_CAN_TX_Enable();
	//FIFO 0 message pending interrupt disable
	CAN_IER &=~(1<<1);
	//FIFO 0 full interrupt disable
	CAN_IER &=~(1<<2);
	//FIFO 0 overrun interrupt disable
	CAN_IER &=~(1<<3);
	// FIFO 0 global interrupt disable
	NVIC_IRQ20_CAN_RX0_Enable();
	//FIFO 1 message pending interrupt disable
	CAN_IER &=~(1<<4);
	//FIFO 1 full interrupt disable
	CAN_IER &=~(1<<5);
	//FIFO 1 overrun interrupt disable
	CAN_IER &=~(1<<6);
	// FIFO 1 global interrupt disable
	NVIC_IRQ21_CAN_RX1_Enable();
    /*
    [SWS_Can_00246] The function Can_Init shall change the module state to
    CAN_READY, after initializing all controllers inside the HW Unit.
    */
	CanDriverState=CAN_READY;
    Can_Controller_State=CAN_CS_UNINIT;
    // Hardware Object
    for (int i = 0; i < Max_Num_HOH ; i++)
    {
    	// Set Message Objects as not Free
    	Message_ObjectStatus[i].Object_Free= FALSE;
    }
	/*
	bxCAN software master reset
	Force a master reset of the bxCAN -> Sleep mode activated after reset (FMP bits and
	CAN_MCR register are initialized to the reset values). This bit is automatically reset to 0.
	*/
	CAN_MCR |=(1<<15);
}
/*******************************************************************************
 * Service ID[hex]		: 0x12
 * Service name			: Can_GetControllerMode
 * Sync/Async			: Synchronous
 * Reentrancy			: Non Reentrant
 * Parameters (in)		: Controller
 *                  	  CAN controller for which the status shall be changed
 * Parameters (out)		: ControllerModePtr
                  	  	  Pointer to a memory location,
                    	  where the current mode of the CAN controller will be stored.
 * Parameters (inout)	:  None
 * Return value			: Std_ReturnType
               	   	      E_OK (request accepted)
               	   	   	  E_NOT_OK (request not accepted)
 * Description			: This service reports about the current status of the requested CAN controller.
*******************************************************************************/
Std_ReturnType Can_SetControllerMode (uint8 Controller,Can_ControllerStateType Transition)
{
	Std_ReturnType Status=E_OK;
#if(CanDevErrorDetect==STD_ON)
	/*
	[SWS_Can_00198]  If development error detection for the Can module is enabled: if
	the module is not yet initialized, the function Can_SetControllerMode shall raise
	development error CAN_E_UNINIT and return E_NOT_OK.
	*/
	if(CanDriverState!=CAN_READY)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetControllerMode_ID,CAN_E_UNINIT);
		return Status;
	}
#endif
	/*
	 The function Can_SetControllerMode(CAN_CS_STARTED)
	 shall set the hardware registers in a way that makes the CAN controller participating
	 on the network
	 */
	if(Transition==CAN_CS_STARTED)
	{
		/*
		 When the function Can_SetControllerMode
		 (CAN_CS_STARTED) is entered and the CAN controller is not in state STOPPED it
		 shall detect a invalid state transition
		 */
		if(Can_Controller_State==CAN_CS_STOPPED)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanController.CanBusoffProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanTxProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanRxProcessing==INTERRUPT)
			{
				Can_EnableControllerInterrupts(Controller);
			}
			else
			{
				//
			}
			/*
			 [SWS_Can_00261] ⌈ The function Can_SetControllerMode(CAN_CS_STARTED)
			 shall set the hardware registers in a way that makes the CAN controller participating
			 on the network
			 */
			// enter STARTED mode
			CAN_MCR &=~(1<<0);
			/*
			 This bit is cleared by hardware when the CAN hardware has left the initialization mode (to
			 be synchronized on the CAN bus). To be synchronized the hardware has to monitor a
			 sequence of 11 consecutive recessive bits on the CAN RX signal.
			 */
			while(CAN_MSR & (1<<0));
			Can_Controller_State=CAN_CS_STARTED;
		}
		else
		{
			/*
			 [SWS_Can_00409] When the function Can_SetControllerMode
			 (CAN_CS_STARTED) is entered and the CAN controller is not in state STOPPED it
			 shall detect a invalid state transition
			 */
		#if(CanDevErrorDetect==STD_ON)
			Status=E_NOT_OK;
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetControllerMode_ID,CAN_E_TRANSITION);
			return Status;
		#endif

		}
	}
	else if(Transition==CAN_CS_STOPPED)
	{
		if(Can_Controller_State==CAN_CS_SLEEP||Can_Controller_State==CAN_CS_STARTED)
		{
			/*
			 [SWS_Can_00263] ⌈ The function Can_SetControllerMode(CAN_CS_STOPPED)
			 shall set the bits inside the CAN hardware such that the CAN controller stops
			 participating on the network.
			 */
			CAN_MCR |=(1<<0);
			if(CAN_HW_Unit_settings.CanConfigSet.CanController.CanBusoffProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanTxProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanRxProcessing==INTERRUPT)
			{
				Can_DisableControllerInterrupts(Controller);
			}
			else
			{
				//
			}
			Can_Controller_State=CAN_CS_STOPPED;
		}
		else
		{
			Status=E_NOT_OK;
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetControllerMode_ID,CAN_E_TRANSITION);
			return Status;
		}
	}
	else if(Transition==CAN_CS_SLEEP)
	{
		if(Can_Controller_State==CAN_CS_STOPPED)
		{
			/*
			 The function Can_SetControllerMode(CAN_CS_SLEEP) shall
			 set the controller into sleep mode.
			 */
			/*
			 This bit is set by software to request the CAN hardware to enter the Sleep mode. Sleep
			 mode will be entered as soon as the current CAN activity (transmission or reception of a
			 CAN frame) has been completed.
			 */
			CAN_MCR |=(1<<1);
			Can_Controller_State=CAN_CS_SLEEP;
		}
		else
		{
			/*
			  When the function Can_SetControllerMode(CAN_CS_SLEEP)
			 is entered and the CAN controller is neither in state STOPPED nor in state SLEEP, it
			 shall detect a invalid state transition
			 */
			Status=E_NOT_OK;
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetControllerMode_ID,CAN_E_TRANSITION);
			return Status;
		}
	}
	else
	{
		/*
		[SWS_Can_00200] ⌈ If development error detection for the Can module is enabled: if
		an invalid transition has been requested, the function Can_SetControllerMode shall
		raise the error CAN_E_TRANSITION and return E_NOT_OK.
		*/
	#if(CanDevErrorDetect==STD_ON)
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetControllerMode_ID,CAN_E_TRANSITION);
		return Status;
	#endif
	}
	/*
	 The Can module notifies the upper layer (CanIf_ControllerModeIndication) after a
	 successful state transition about the new state.
	 */
	CanIf_ControllerModeIndication(Controller,Can_Controller_State);
	return Status;
}
/******************************************************************************
 * Service ID[hex]		: 0x06
 * Service name			: Can_Write
 * Sync/Async     		: Synchronous
 * Reentrancy     		: Reentrant (thread-safe)
 * Parameters (in)		: Hth
                  	  	  Information which HW-transmit handle shall be used for
                     	  transmit. Implicitly this is also the information about
                    	  the controller to use because the Hth numbers are unique inside one hardware unit.
 *                 	 	: PduInfo
                  	  	  Pointer to SDU user memory, DLC and Identifier.
 * Parameters (inout)	: None
 * Parameters (out)  	: None
 * Return value			: Std_ReturnType
                		  E_OK (Write command has been accepted)
                          E_NOT_OK (development error occurred)
                          CAN_BUSY (No TX hardware buffer available or pre-emptive call
                          of Can_Write that can't be implemented re-entrant)
 * Description			: This function is called by CanIf to pass a CAN message to CanDrv for transmission.
******************************************************************************/
Std_ReturnType Can_Write (Can_HwHandleType Hth,const Can_PduType* PduInfo)
{
	Std_ReturnType Status;
	Status=E_OK;
#if(CanDevErrorDetect==STD_ON)
	/*
	 If development error detection for the Can module is enabled:
	 The function Can_Write shall raise the error CAN_E_UNINIT and shall return
	 E_NOT_OK if the driver is not yet initialized
	*/
	if(CanDriverState!=CAN_READY)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Write_ID,CAN_E_UNINIT);
		return Status;
	}
	else
	{
		//
	}
	/*
	 [SWS_Can_00217] ⌈ If development error detection for the Can module is enabled:
	 The function Can_Write shall raise the error CAN_E_PARAM_HANDLE and shall
	 return E_NOT_OK if the parameter Hth is not a configured Hardware Transmit Handle
	 */
	if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[Hth].CanObjectType==RECEIVE)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Write_ID,CAN_E_PARAM_HANDLE);
		return Status;
	}
	else
	{
		//
	}
	/*
	 If development error detection for CanDrv is enabled:
	 Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the
	 parameter PduInfo is a null pointer
	 */
	if(PduInfo==NULL_PTR)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Write_ID,CAN_E_PARAM_POINTER);
		return Status;
	}
	else
	{
		//
	}
	/*
	 [SWS_Can_00218] ⌈ The function Can_Write shall return E_NOT_OK and if
	 development error detection for the CAN module is enabled shall raise the error
	 CAN_E_PARAM_DATA_LENGTH:
	 -If the length is more than 8 byte and the CAN controller is not in CAN FD mode
	 */
	if(PduInfo->length>8)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Write_ID,CAN_E_PARAM_DATA_LENGTH);
		return Status;
	}
	else
	{
		//
	}
	/*
	 If development error detection for CanDrv is enabled:
	 Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the
	 trigger transmit API is disabled for this hardware object (CanTriggerTransmitEnable =
	 FALSE) and the SDU pointer inside PduInfo is a null pointer.
	 */
	if(PduInfo->sdu==NULL_PTR)
	{
		if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[Hth].CanTriggerTransmitEnable==FALSE)
		{
			Status=E_NOT_OK;
			Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_Write_ID,CAN_E_PARAM_DATA_LENGTH);
			return Status;
		}
		else
		{
			//
		}
	}
	else
	{
		//
	}
#endif
	/*
	 The function Can_Write first checks if the hardware transmit object that is identified
	 by the HTH is free and if another Can_Write is ongoing for the same HTH.
	 */
	if(Message_ObjectStatus[Hth].Object_Free==TRUE)
	{
		// The mutex for that HTH is set to ‘signaled’
		Message_ObjectStatus[Hth].Object_Free=FALSE;
		Message_ObjectStatus[Hth].mailbox=MCAL_CAN_Get_TX_Mailboxes_Empty();
		Message_ObjectStatus[Hth].CanObjectId=Hth;
		Message_ObjectStatus[Hth].swPduHandle=PduInfo->swPduHandle;
		/*
		 The CAN Frame has to be sent according to the two most
		 significant bits of Can_PduType->id. The CAN FD frame bit is only evaluated if
		 CAN Controller is in CAN FD mode (valid CanControllerFdBaudrateConfig).
		 */
		Message_Object[Hth].DLC=PduInfo->length;
		if((PduInfo->id&(3<<30))==0)
		{
			Message_Object[Hth].IDE=CAN_IDE_Standard;
			Message_Object[Hth].ID=PduInfo->id;
		}
		else if((PduInfo->id&(3<<30))==2)
		{
			Message_Object[Hth].IDE=CAN_IDE_Extended;
			Message_Object[Hth].ID=(PduInfo->id&(0x1FFFFFFF));
		}
		Message_Object[Hth].RTR=CAN_RTR_Data_Frame;
		for(int i=0;i<PduInfo->length;i++)
		{
			Message_Object[Hth].SDU[i]=PduInfo->sdu[i];
		}
		MCAL_CAN_Add_TX_Message(&Message_Object[Hth],Message_ObjectStatus[Hth].mailbox);
	}
	else
	{
		/*
		 The function Can_Write shall perform no actions if the
		 hardware transmit object is busy with another transmit request for an L-PDU:
 	 	 1. The transmission of the other L-PDU shall not be cancelled and the function
		Can_Write is left without any actions.
 	 	2. The function Can_Write shall return CAN_BUSY
		 */
		Status=CAN_BUSY;
		return Status;
	}
	return Status;
}
/*******************************************************************************
 * Service ID[hex]   	: 0x04
 * Service name      	: Can_DisableControllerInterrupts
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Reentrant
 * Parameters (in)   	: Controller
                  	   	  CAN controller for which interrupts shall be disabled.
 * Parameters (inout)	: None
 * Parameters (out)  	: None
 * Return value      	: None
 * Description       	: This function disables all interrupts for this CAN controller
*******************************************************************************/
void Can_DisableControllerInterrupts (uint8 Controller)
{
#if(CanDevErrorDetect==STD_ON)
	/*
	 [SWS_Can_00205] If development error detection for the Can module is enabled:
	 The function Can_DisableControllerInterrupts shall raise the error CAN_E_UNINIT if
	 the driver not yet initialized.
	 */
	if(CanDriverState!=CAN_READY)
	Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_DisableControllerInterrupts_ID,CAN_E_UNINIT);
#endif
	if(CAN_HW_Unit_settings.CanConfigSet.CanController.CanBusoffProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanTxProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanRxProcessing==INTERRUPT)
	{
		/*
		 The function Can_DisableControllerInterrupts can increase a counter on every
		 execution that indicates how many Can_EnableControllerInterrupts need to be called
		 before the interrupts will be enabled
		 */
		Interrupt_Disable_Counter++;
		// disable all interrupts for that CAN controller only, if interrupts for that CAN Controller are enabled.
		if(CAN_IER&(1<<0))
		{
			/*
			 When Can_EnableControllerInterrupts has been called several
			 times, Can_DisableControllerInterrupts must be called as many times before the
			 interrupts are re-disabled.
			*/
			if(Interrupt_Enable_Counter>0)
			{
				Interrupt_Enable_Counter--;
			}
			else
			{
				// disable Transmit interrupt
				CAN_IER &=~(1<<0);
				//FIFO 0 message pending interrupt disable
				CAN_IER &=~(1<<1);
				//FIFO 0 full interrupt disable
				CAN_IER &=~(1<<2);
				//FIFO 0 overrun interrupt disable
				CAN_IER &=~(1<<3);
				//FIFO 1 message pending interrupt disable
				CAN_IER &=~(1<<4);
				//FIFO 1 full interrupt disable
				CAN_IER &=~(1<<5);
				//FIFO 1 overrun interrupt disable
				CAN_IER &=~(1<<6);
			}

		}
		else
		{
			//
		}
	}
	else
	{
		//
	}
}
/******************************************************************************
 * Service ID[hex]   	: 0x05
 * Service name      	: Can_EnableControllerInterrupts
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Reentrant
 * Parameters (in)   	: Controller
                     	  CAN controller for which interrupts shall be re-enabled.
 * Parameters (inout)	: None
 * Parameters (out)  	: None
 * Return value      	: None
 * Description       	: This function enables all allowed interrupts
******************************************************************************/
void Can_EnableControllerInterrupts (uint8 Controller)
{
#if(CanDevErrorDetect==STD_ON)
	/*
	 [SWS_Can_00209] If development error detection for the Can module is enabled:
	 The function Can_EnableControllerInterrupts shall raise the error CAN_E_UNINIT if
	 the driver not yet initialized.
	 */
	if(CanDriverState!=CAN_READY)
	Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_EnableControllerInterrupts_ID,CAN_E_UNINIT);
#endif
	if(CAN_HW_Unit_settings.CanConfigSet.CanController.CanBusoffProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanTxProcessing==INTERRUPT||CAN_HW_Unit_settings.CanConfigSet.CanController.CanRxProcessing==INTERRUPT)
	{
		/*
		 The function Can_EnableControllerInterrupts can increase a counter on every
		 execution that indicates how many Can_DisableControllerInterrupts need to be called
		 before the interrupts will be disabled
		 */
		Interrupt_Enable_Counter++;
		// enable all interrupts for that CAN controller only, if interrupts for that CAN Controller are disabled.
		if((CAN_IER&(1<<0))==0)
		{
			/*
			 [SWS_Can_00202] When Can_DisableControllerInterrupts has been called several
			 times, Can_EnableControllerInterrupts must be called as many times before the
			 interrupts are re-enabled.
			*/
			if(Interrupt_Disable_Counter>0)
			{
				Interrupt_Disable_Counter--;
			}
			else
			{
				// enable Transmit interrupt
				CAN_IER |=(1<<0);
				//FIFO 0 message pending interrupt enable
				CAN_IER |=(1<<1);
				//FIFO 0 full interrupt enable
				CAN_IER |=(1<<2);
				//FIFO 0 overrun interrupt enable
				CAN_IER |=(1<<3);
				//FIFO 1 message pending interrupt enable
				CAN_IER |=(1<<4);
				//FIFO 1 full interrupt enable
				CAN_IER |=(1<<5);
				//FIFO 1 overrun interrupt enable
				CAN_IER |=(1<<6);
			}

		}
		else
		{
			//
		}
	}
	else
	{
		//
	}
}
/********************************************************************************
 *  Service ID[hex]  	: 0x0f
 *  Function name     	: Can_SetBaudrate
 *  Sync/Async        	: Synchronous
 *  Reentrancy        	: Reentrant for different Controllers.
 *                        Non reentrant for the same Controller.
 *  Parameters (in)  	: None
 *  Parameters (inout)	: None
 *  Parameters (out)  	: None
 *  Return value      	: None
 *  Description       	: This service shall set the baud rate configuration
                          of the CAN controller. Depending on necessary baud rate
                          modifications the controller might have to reset.
********************************************************************************/
Std_ReturnType Can_SetBaudrate (uint8 Controller,uint16 BaudRateConfigID)
{
	uint32 CAN_BTR_temp=0;
	uint32 Prescaler=0;
	uint32 BaudRate=0;
	uint32 Bits_Timing=0;
	Std_ReturnType Status=E_OK;
#if(CanDevErrorDetect==STD_ON)
	/*
 	 If development error detection for the Can module is enabled:
	 The function Can_SetBaudrate shall raise the error CAN_E_UNINIT and return
	 E_NOT_OK if the driver is not yet initialized
	*/
	if(CanDriverState!=CAN_READY)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetBaudrate_ID,CAN_E_UNINIT);
		return Status;
	}
	else
	{
		//
	}
	/*
	 [SWS_Can_00493] ⌈ If development error detection for the Can module is enabled:
	 The function Can_SetBaudrate shall raise the error CAN_E_PARAM_BAUDRATE
	 and return E_NOT_OK if the parameter BaudRateConfigID has an invalid value.
	 */
	if(BaudRateConfigID>Max_Num_Baud_Rate)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_SetBaudrate_ID,CAN_E_PARAM_BAUDRATE);
		return Status;
	}
	else
	{
		//
	}
	/*
	 If re-initialization is necessary, the CAN Controller has to be switched to STOPPED
	 before Can_SetBaudrate() can be executed and the new baud rate configuration can
	 be applied.
	 */
	if(Can_Controller_State!=CAN_CS_STOPPED)
	{
		Status=E_NOT_OK;
		return Status;
	}
	else
	{
		//
	}
#endif
	for(int i=0;i<Max_Num_Baud_Rate;i++)
	{
		if(CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerBaudRateConfigID==BaudRateConfigID)
		{
			//CAN bit timing register (baud Rate)
			CAN_BTR_temp=CAN_BTR;
			CAN_BTR_temp &=0XC0000000;
			//set Prescaler
			Bits_Timing=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerPropSeg;
			Bits_Timing+=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerSeg1;
			Bits_Timing+=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerSeg2;
			BaudRate=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerBaudRate;
			Prescaler=(8000000)/(Bits_Timing*1000*BaudRate);
			CAN_BTR_temp |=(Prescaler-1)<<0;
			//set TimeSeg1
			CAN_BTR_temp |=(CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerSeg1-1)<<16;
			//set TimeSeg2
			CAN_BTR_temp |=(CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerBaudrateConfig[i].CanControllerSeg2-1)<<20;
			CAN_BTR=CAN_BTR_temp;
		}
		else
		{
			//
		}
	}
	return Status;
}
/*********************************************************************************
 * Service ID[hex] 		: 0x07
 * Service name    		: Can_GetVersionInfo
 * Sync/Async      		: Synchronous
 * Reentrancy      		: Reentrant
 * Parameters (in) 		: None
 * Parameters (inout)	: None
 * Parameters (out)  	: versioninfo
                       	  Pointer to where to store the version information of this
                          module.
 * Return value      	: None
 * Description       	: This function returns the version information of this
                   	  	  module
********************************************************************************/
void Can_GetVersionInfo (Std_VersionInfoType* versioninfo)
{
#if(CanDevErrorDetect==STD_ON)
	/*
	 [SWS_Can_00177] If development error detection for the Can module is enabled:
	 The function Can_GetVersionInfo shall raise the error CAN_E_PARAM_POINTER if
	 the parameter versionInfo is a null pointer.
	 */
	if(versioninfo==NULL_PTR)
	{
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_GetVersionInfo_ID,CAN_E_PARAM_POINTER);
	}
	else
	{
		//
	}
#endif
	versioninfo->moduleID = CAN_VERSION_ID ;
	versioninfo->sw_major_version = CAN_SW_RELEASE_MAJOR_VERSION ;
	versioninfo->sw_minor_version = CAN_SW_RELEASE_MINOR_VERSION ;
	versioninfo->sw_patch_version = CAN_SW_RELEASE_PATCH_VERSION ;
	versioninfo->vendorID = VENDOR_ID ;
}
/******************************************************************************
 * Service ID[hex]		: 0x12
 * Service name			: Can_GetControllerMode
 * Sync/Async			: Synchronous
 * Reentrancy			: Non Reentrant
 * Parameters (in)		: Controller
                   	   	  CAN controller for which the status shall be changed
 * Parameters (out)		: ControllerModePtr
                  	  	  Pointer to a memory location,
                    	  where the current mode of the CAN controller will be stored.
 * Parameters (inout)	: None
 * Return value			: Std_ReturnType
               	   	   	  E_OK (request accepted)
               	   	   	  E_NOT_OK (request not accepted)
 * Description			: This service reports about the current status of the requested CAN controller.
******************************************************************************/
Std_ReturnType Can_GetControllerMode (uint8 Controller,Can_ControllerStateType* ControllerModePtr)
{
	Std_ReturnType Status=E_OK;
#if(CanDevErrorDetect==STD_ON)
	/*
 	 [SWS_Can_91016] If development error detection for the Can module is enabled:
	 The function Can_GetControllerMode shall raise the error CAN_E_UNINIT and return
	 E_NOT_OK if the driver is not yet initialized.
	*/
	if(CanDriverState!=CAN_READY)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_GetControllerMode_ID,CAN_E_UNINIT);
		return Status;
	}
	else
	{
		//
	}
	/*
	 [SWS_Can_91018] If parameter ControllerModePtr of Can_GetControllerMode()
	 has an null pointer, the CanDrv shall report development error code
	 CAN_E_PARAM_POINTER to the Det_ReportError service of the DET.
	 */
	if(ControllerModePtr==NULL_PTR)
	{
		Status=E_NOT_OK;
		Det_ReportError(CAN_VERSION_ID,CONTROLLER_ZERO,Can_GetControllerMode_ID,CAN_E_PARAM_POINTER);
		return Status;
	}
	else
	{
		//
	}
#endif
	/*
	[SWS_Can_91015] ⌈ The service Can_GetControllerMode shall return the mode of
	the requested CAN controller.
	*/
	*ControllerModePtr=Can_Controller_State;
	return Status;
}
/******************************************************************************
 * Service ID[hex]: 0x08
 * Service name   : Can_MainFunction_Read
 * Mode           : Supervisor Mode (Privileged Mode)
 * Description    : This function performs the polling of RX indications when
                    CAN_RX_PROCESSING is set to POLLING.
 *******************************************************************************/
void Can_MainFunction_Read (void)
{
	/*
	 [SWS_Can_00108] ⌈ The function Can_MainFunction_Read shall perform the polling
	 of RX indications when CanRxProcessing is set to POLLING or MIXED. In case of
	 MIXED processing only the hardware objects for which
	 CanHardwareObjectUsesPolling is set to TRUE shall be polled.⌋
	 */
	//These bits indicate how many messages are pending in the receive FIFO
	//These bits indicate how many messages are pending in the receive FIFO
	if ((CAN_RF0R & (3<<0))!=0)
	{
		for(int i=0;i<Max_Num_HOH;i++)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectType==RECEIVE)
			{
				if(Message_ObjectStatus[i].Object_Free==TRUE)
				{
					//Identifier extension
					if((CAN_RX_FIFO_0->CAN_RIxR & (1<<2))==1)
					{
						//1: Extended identifier
						if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanIdType==EXTENDED)
						{
							if((CAN_RX_FIFO_0->CAN_RIxR>>3|(2<<29))==CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanHwFilter.CanHwFilterCode)
							{
								Can_HwType Mailbox;
								PduInfoType PduInfoPtr;
								//HOH is busy
								Message_ObjectStatus[i].Object_Free=FALSE;
								//copy message
								Message_Object[i].ID=(CAN_RX_FIFO_0->CAN_RIxR>>3);
								// 10 CAN message with Extended CAN ID
								Message_Object[i].ID|=(2<<29);
								//Length of data
								Message_Object[i].DLC=(CAN_RX_FIFO_0->CAN_RDTxR & 0x0000000F);
								//Data
								*((volatile uint32*)Message_Object[i].SDU)=CAN_RX_FIFO_0->CAN_RDLxR;
								*(((volatile uint32*)Message_Object[i].SDU)+1)=CAN_RX_FIFO_0->CAN_RDHxR;
								Mailbox.CanId=Message_Object[i].ID;
								Mailbox.Hoh=CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId;
								Mailbox.ControllerId=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerId;
								PduInfoPtr.SduDataPtr=Message_Object[i].SDU;
								PduInfoPtr.SduLength=Message_Object[i].DLC;
								//callback function to upper layer
								//CanIf_RxIndication(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId,Message_Object[i].ID,Message_Object[i].DLC,Message_Object[i].SDU);
								CanIf_RxIndication (&Mailbox,&PduInfoPtr);
								Message_ObjectStatus[i].Object_Free=TRUE;
								break;
							}
							else
							{
								//
							}
						}
						else
						{
							//
						}
					}
					else
					{
						//0: Standard identifier
						if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanIdType==STANDARD)
						{
							if((CAN_RX_FIFO_0->CAN_RIxR>>21)==CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanHwFilter.CanHwFilterCode)
							{
								Can_HwType Mailbox;
								PduInfoType PduInfoPtr;
								//HOH is busy
								Message_ObjectStatus[i].Object_Free=FALSE;
								//00 CAN FD frame with Extended CAN ID
								Message_Object[i].ID=(CAN_RX_FIFO_0->CAN_RIxR>>21);
								//Data Length
								Message_Object[i].DLC=(CAN_RX_FIFO_0->CAN_RDTxR & 0x0000000F);
								//Data
								*((volatile uint32*)Message_Object[i].SDU)=CAN_RX_FIFO_0->CAN_RDLxR;
								*(((volatile uint32*)Message_Object[i].SDU)+1)=CAN_RX_FIFO_0->CAN_RDHxR;
								Mailbox.CanId=Message_Object[i].ID;
								Mailbox.Hoh=CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId;
								Mailbox.ControllerId=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerId;
								PduInfoPtr.SduDataPtr=Message_Object[i].SDU;
								PduInfoPtr.SduLength=Message_Object[i].DLC;
								//callback function to upper layer
								//CanIf_RxIndication(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId,Message_Object[i].ID,Message_Object[i].DLC,Message_Object[i].SDU);
								CanIf_RxIndication (&Mailbox,&PduInfoPtr);
								Message_ObjectStatus[i].Object_Free=TRUE;
								break;
							}
							else
							{
								//
							}
						}
						else
						{
							//Clear message
							//Set by software to release the output mailbox of the FIFO
							CAN_RF0R |=(1<<5);
						}
					}
				}
				else
				{
					//HOH not free
				}
			}
			else
			{
				//
			}
		}
		//Clear message
		//Set by software to release the output mailbox of the FIFO
		CAN_RF0R |=(1<<5);
	}
	else
	{
		//
	}
}
/*************************************************************************
 *************************************ISR*********************************
 ************************************************************************/
void USB_HP_CAN_TX_IRQHandler(void)
{
	//Check which mailbox transmit is complete
	// RQCPx: Request completed mailbox
	//Set by hardware when the last request (transmit or abort) has been performed.
	if((CAN_TSR & (1<<0))==1)
	{
		 //Request completed mailbox0
		CAN_TSR |=1<<0;
		for(int i=0;i<Max_Num_HOH;i++)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectType==TRANSMIT)
			{
				if(Message_ObjectStatus[i].mailbox==Transmi_mailbox_0)
				{
					if(Message_ObjectStatus[i].Object_Free==FALSE)
					{
						Message_ObjectStatus[i].Object_Free=TRUE;
						CanIf_TxConfirmation(Message_ObjectStatus[i].swPduHandle);
					}
				}
			}
		}
	}
	else if((CAN_TSR & (1<<8))==1)
	{
		 //Request completed mailbox1
		CAN_TSR |=1<<8;
		for(int i=0;i<Max_Num_HOH;i++)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectType==TRANSMIT)
			{
				if(Message_ObjectStatus[i].mailbox==Transmi_mailbox_1)
				{
					if(Message_ObjectStatus[i].Object_Free==FALSE)
					{
						Message_ObjectStatus[i].Object_Free=TRUE;
						MCAL_CAN_Mailbox_1_Empty_Callback();
					}
				}
			}
		}
	}
	else if((CAN_TSR & (1<<16))==1)
	{
		 //Request completed mailbox2
		CAN_TSR |=1<<16;
		for(int i=0;i<Max_Num_HOH;i++)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectType==TRANSMIT)
			{
				if(Message_ObjectStatus[i].mailbox==Transmi_mailbox_2)
				{
					if(Message_ObjectStatus[i].Object_Free==FALSE)
					{
						Message_ObjectStatus[i].Object_Free=TRUE;
						MCAL_CAN_Mailbox_2_Empty_Callback();
					}
				}
			}
		}
	}
	else
	{
		// no call back
	}
}

void USB_LP_CAN_RX0_IRQHandler(void)
{
	//These bits indicate how many messages are pending in the receive FIFO
	if ((CAN_RF0R & (3<<0))!=0)
	{
		for(int i=0;i<Max_Num_HOH;i++)
		{
			if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectType==RECEIVE)
			{
				if(Message_ObjectStatus[i].Object_Free==TRUE)
				{
					//Identifier extension
					if((CAN_RX_FIFO_0->CAN_RIxR & (1<<2))==1)
					{
						//1: Extended identifier
						if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanIdType==EXTENDED)
						{
							if((CAN_RX_FIFO_0->CAN_RIxR>>3|(2<<29))==CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanHwFilter.CanHwFilterCode)
							{
								Can_HwType Mailbox;
								PduInfoType PduInfoPtr;
								//HOH is busy
								Message_ObjectStatus[i].Object_Free=FALSE;
								//copy message
								Message_Object[i].ID=(CAN_RX_FIFO_0->CAN_RIxR>>3);
								// 10 CAN message with Extended CAN ID
								Message_Object[i].ID|=(2<<29);
								//Length of data
								Message_Object[i].DLC=(CAN_RX_FIFO_0->CAN_RDTxR & 0x0000000F);
								//Data
								*((volatile uint32*)Message_Object[i].SDU)=CAN_RX_FIFO_0->CAN_RDLxR;
								*(((volatile uint32*)Message_Object[i].SDU)+1)=CAN_RX_FIFO_0->CAN_RDHxR;
								Mailbox.CanId=Message_Object[i].ID;
								Mailbox.Hoh=CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId;
								Mailbox.ControllerId=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerId;
								PduInfoPtr.SduDataPtr=Message_Object[i].SDU;
								PduInfoPtr.SduLength=Message_Object[i].DLC;
								//callback function to upper layer
								CanIf_RxIndication (&Mailbox,&PduInfoPtr);
								//CanIf_RxIndication(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId,Message_Object[i].ID,Message_Object[i].DLC,Message_Object[i].SDU);
								Message_ObjectStatus[i].Object_Free=TRUE;
								break;
							}
							else
							{
								//
							}
						}
						else
						{
							//
						}
					}
					else
					{
						//0: Standard identifier
						if(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanIdType==STANDARD)
						{
							if((CAN_RX_FIFO_0->CAN_RIxR>>21)==CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanHwFilter.CanHwFilterCode)
							{
								Can_HwType Mailbox;
								PduInfoType PduInfoPtr;
								//HOH is busy
								Message_ObjectStatus[i].Object_Free=FALSE;
								//00 CAN FD frame with Extended CAN ID
								Message_Object[i].ID=(CAN_RX_FIFO_0->CAN_RIxR>>21);
								//Data Length
								Message_Object[i].DLC=(CAN_RX_FIFO_0->CAN_RDTxR & 0x0000000F);
								//Data
								*((volatile uint32*)Message_Object[i].SDU)=CAN_RX_FIFO_0->CAN_RDLxR;
								*(((volatile uint32*)Message_Object[i].SDU)+1)=CAN_RX_FIFO_0->CAN_RDHxR;
								Mailbox.CanId=Message_Object[i].ID;
								Mailbox.Hoh=CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId;
								Mailbox.ControllerId=CAN_HW_Unit_settings.CanConfigSet.CanController.CanControllerId;
								PduInfoPtr.SduDataPtr=Message_Object[i].SDU;
								PduInfoPtr.SduLength=Message_Object[i].DLC;
								//callback function to upper layer
								//CanIf_RxIndication(CAN_HW_Unit_settings.CanConfigSet.CanHardwareObject[i].CanObjectId,Message_Object[i].ID,Message_Object[i].DLC,Message_Object[i].SDU);
								CanIf_RxIndication (&Mailbox,&PduInfoPtr);
								Message_ObjectStatus[i].Object_Free=TRUE;
								break;
							}
							else
							{
								//
							}
						}
						else
						{
							//Clear message
							//Set by software to release the output mailbox of the FIFO
							CAN_RF0R |=(1<<5);
						}
					}
				}
				else
				{
					//HOH not free
				}
			}
			else
			{
				//
			}
		}
		//Clear message
		//Set by software to release the output mailbox of the FIFO
		CAN_RF0R |=(1<<5);
	}
	else if((CAN_RF0R & (1<<3))==1)
	{
		// FIFO 0 full
	}
	else if((CAN_RF0R & (1<<4))==1)
	{
		// FIFO 0 overrun
	}
	else
	{
		//
	}
}
/*************************************************************************
 *************************************CallBack****************************
 ************************************************************************/
__attribute__((weak)) void MCAL_CAN_Mailbox_0_Empty_Callback(void)
{

}
__attribute__((weak)) void MCAL_CAN_Mailbox_1_Empty_Callback(void)
{

}
__attribute__((weak)) void MCAL_CAN_Mailbox_2_Empty_Callback(void)
{

}
