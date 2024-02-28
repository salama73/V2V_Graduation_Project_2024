/******************************************************************************
*
* @Module      :	 CAN
* @File Name   :	 Can.h
* @Description :	This specification specifies the functionality, API and the configuration of the AUTOSAR
					Basic Software module CAN Driver.
* Author       :	Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#ifndef CAN_H_
#define CAN_H_
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
#include "Det.h"
#include "Can_Cfg.h"
#include "Std_Types.h"
// AUTOSAR checking Std_Version
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
||  (STD_TYPES_AR_RELEASE_MINOR_VERSION  != CAN_AR_RELEASE_MINOR_VERSION)\
||  (STD_TYPES_AR_RELEASE_PATCH_VERSION  != CAN_AR_RELEASE_PATCH_VERSION))
#error "The Autosar version of Std_Types.h does not match the CAN version"
#endif
#include "ComStack_Types.h"
// AUTOSAR checking ComStack_Types.h
#if ((COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
||  (COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION  != CAN_AR_RELEASE_MINOR_VERSION)\
||  (COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION  != CAN_AR_RELEASE_PATCH_VERSION))
#error "The Autosar version of Std_Types.h does not match the CAN version"
#endif
#include "Can_GeneralTypes.h"
// AUTOSAR checking Can_GeneralTypes.h
#if ((CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
||  (CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION  != CAN_AR_RELEASE_MINOR_VERSION)\
||  (CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION  != CAN_AR_RELEASE_PATCH_VERSION))
#error "The Autosar version of Std_Types.h does not match the CAN version"
#endif
/*****************************************************************************
							 Development Errors
 ****************************************************************************/
//API Service called with wrong parameter
#define CAN_E_PARAM_POINTER						(uint8)0x01
//API Service called with wrong parameter
#define CAN_E_PARAM_HANDLE						(uint8)0x02
//API Service called with wrong parameter
#define CAN_E_PARAM_DATA_LENGTH					(uint8)0x03
//API Service called with wrong parameter
#define CAN_E_PARAM_CONTROLLER					(uint8)0x04
//API Service used without initialization
#define CAN_E_UNINIT							(uint8)0x05
//Invalid transition for the current mode
#define CAN_E_TRANSITION 						(uint8)0x06
//Parameter Baudrate has an invalid value
#define CAN_E_PARAM_BAUDRATE					(uint8)0x07
//Invalid configuration set selection
#define CAN_E_INIT_FAILED						(uint8)0x08
//API service called with invalid PDU ID
#define CAN_E_PARAM_LPDU						(uint8)0x09
/*****************************************************************************
							 APIS ID
 ****************************************************************************/
#define Can_Init_ID                             (uint8)0x00
#define Can_GetVersionInfo_ID					(uint8)0x07
#define Can_DeInit_ID                           (uint8)0x10
#define Can_SetBaudrate_ID                      (uint8)0x0f
#define Can_SetControllerMode_ID                (uint8)0x03
#define Can_DisableControllerInterrupts_ID      (uint8)0x04
#define Can_EnableControllerInterrupts_ID       (uint8)0x05
#define Can_CheckWakeup_ID                      (uint8)0x0b
#define Can_GetControllerErrorState_ID          (uint8)0x0b
#define Can_GetControllerMode_ID                (uint8)0x12
#define Can_Write_ID                            (uint8)0x06
/*****************************************************************************
							 Type definitions
 ****************************************************************************/
//one CAN controller in HW
typedef enum
{
	//All the CANIDs are of type extended only (29 bit).
	EXTENDED,
	//The type of CANIDs can be both Standard or Extended.
	MIXED,
	//All the CANIDs are of type standard only (11bit).
	STANDARD
}CanIdType;
typedef enum  {
    BASIC,
	FULL
}CanHandleType;
typedef enum
{
	//Receive HOH
	RECEIVE,
	//Transmit HOH
	TRANSMIT
}CanObjectType;
/*
 The Can module has a very simple state machine, with the two states CAN_UNINIT
 and CAN_READY. Figure 7.1 shows the state machine.
 */
typedef enum {
    CAN_UNINIT,
    CAN_READY
}CanDriverStateType;
/************************************************************************************
Name			:           	CanControllerBaudrateConfig
Parent Container: 				CanController
Description		:				This container contains bit timing related configuration parameters of
								the CAN controller(s).
Type			:               Container
*************************************************************************************/
typedef struct
{
	/*
	 Specifies the baudrate of the controller in kbps.
	 */
	float32 CanControllerBaudRate;
	/*
	 This ID is used by SetBaudrate API and uniquely identifies a specific baud
	 rate configuration within a controller configuration.
	 */
	uint16 CanControllerBaudRateConfigID;
	/*
	 Specifies propagation delay in time quantas
	 */
	uint16 CanControllerPropSeg;
	/*
	 Specifies phase segment 1 in time quantas.
	 */
	uint8 CanControllerSeg1;
	/*
	 Specifies phase segment 2 in time quantas.
	 */
	uint8 CanControllerSeg2;
	/*
	 Specifies the synchronization jump width for the controller in time quantas.
	 */
	uint8 CanControllerSyncJumpWidth;
}CanControllerBaudrateConfig;
/************************************************************************************
Name			:           	CanHwFilter
Parent Container: 				CanHardwareObject
Description		:				This container is only valid for HRHs and contains the configuration (parameters)
								of one hardware filter.
Type			:               Container
*************************************************************************************/
typedef struct
{
	/*
	 Specifies (together with the filter mask) the identifiers range that passes
	 the hardware filter.
	 */
	uint32 CanHwFilterCode;
	/*
	 Describes a mask for hardware-based filtering of CAN identifiers.
	 The mask shall be build by filling with leading 0. In case of CanIdType
	 EXTENDED or MIXED a 29 bit mask shall be build. In case of CanIdType
	 STANDARD a 11 bit mask shall be build
	 */
	uint32 CanHwFilterMask;
}CanHwFilter;
/************************************************************************************
Name			:           	CanController
Parent Container: 				CanConfigSet
Description		:				This container contains the configuration parameters of the CAN
								controller(s).
Type:                           Container
*************************************************************************************/
typedef struct
{
	/*
	 Enables / disables API Can_MainFunction_BusOff() for handling busoff
	 events in polling mode.
	 */
	uint8 CanBusoffProcessing;
	/*
	 Defines if a CAN controller is used in the configuration.
	 */
	boolean CanControllerActivation;
	/*
	 Specifies the CAN controller base address.
	 */
	uint32 CanControllerBaseAddress;
	/*
	 This parameter provides the controller ID which is unique in a given CAN
	 Driver. The value for this parameter starts with 0 and continue without any gaps.
	 */
	uint8 CanControllerId;
	/*
	 Enables / disables API Can_MainFunction_Read() for handling PDU
	 reception events in polling mode.
	 */
	uint8 CanRxProcessing;
	/*
	 Enables / disables API Can_MainFunction_Write() for handling PDU
	 transmission events in polling mode.
	 */
	uint8 CanTxProcessing;
	/*
	 Enables / disables API Can_MainFunction_Wakeup() for handling wakeup
	 events in polling mode.
	 */
	uint8 CanWakeupProcessing;
	/*
	 CAN driver support for wakeup over CAN Bus
	 */
	boolean CanWakeupSupport;
	/*
	 This container contains bit timing related configuration parameters of
	 the CAN controller(s).
	 */
	CanControllerBaudrateConfig CanControllerBaudrateConfig[Max_Num_Baud_Rate];
	/*
	 Reference to baudrate configuration container configured for the Can
	 Controller
	 */
	CanControllerBaudrateConfig* CanControllerDefaultBaudrate;
}CanController;
/************************************************************************************
Name			:           	CanHardwareObject
Parent Container: 				CanConfigSet
Description		:				This container contains the configuration (parameters) of CAN
								Hardware Objects.
Type:                           Container
*************************************************************************************/
typedef struct
{
	/*
	 Specifies the type (Full-CAN or Basic-CAN) of a hardware object.
	 */
	CanHandleType CanHandleType;
	/*
	 Number of hardware objects used to implement one HOH. In case of a HRH this
	 parameter defines the number of elements in the hardware FIFO or the number
	 of shadow buffers, in case of a HTH it defines the number of hardware objects
	 used for multiplexed transmission or for a hardware FIFO used by a FullCAN HTH.
	 */
	uint16 CanHwObjectCount;
	/*
	 Specifies whether the IdValue is of type standard identifier, extended
	 identifier or mixed mode.
	 */
	CanIdType CanIdType;
	/*
	 Holds the handle ID of HRH or HTH. The value of this parameter is unique in a
     given CAN Driver, and it should start with 0 and continue without any gaps.
     The HRH and HTH Ids share a common ID range.Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3
	 */
	uint8 CanObjectId;
	/*
	 Specifies if the HardwareObject is used as Transmit or as Receive object
	 */
	CanObjectType CanObjectType;
	/*
	 This parameter defines if or if not Can supports the trigger-transmit API for this handle.
	 */
	boolean CanTriggerTransmitEnable;
	/*
	 Reference to CAN Controller to which the HOH is associated to.
	 */
	CanController* CanControllerRef;
	/*
	 This container is only valid for HRHs and contains the configuration
	 (parameters) of one hardware filter.
	 */
	CanHwFilter	CanHwFilter ;
}CanHardwareObject;
/************************************************************************************
Name			:           	CanConfigSet
Parent Container: 				Can
Description		:				This container contains the configuration parameters and sub containers of the
								AUTOSAR Can module.
Type:                           Container
*************************************************************************************/
typedef struct
{
	/*
	 This container contains the configuration parameters of the CAN
	 controller(s).
	 */
	CanController CanController;
	/*
	 This container contains the configuration (parameters) of CAN
	 Hardware Objects.
	 */
	CanHardwareObject CanHardwareObject[Max_Num_HOH];
}CanConfigSet;
/************************************************************************************
Name			:           	CanGeneral
Parent Container: 				Can
Description		:				This container contains the parameters related each CAN Driver Unit.
Type:                           Container
*************************************************************************************/
typedef struct
{
	boolean Active;
}CanGeneral;
/************************************************************************************
Name			:           	Can
Parent Container: 				CAN
Description		:				This container holds the configuration of a single CAN Driver
Type:                           Structure
*************************************************************************************/
typedef struct
{
	//CanGeneral CanGeneral;
	CanConfigSet CanConfigSet;
}Can_ConfigType;
extern Can_ConfigType Can;
/*************************************************************************************
 	 	 	 	 	 	 	 	 APIS
************************************************************************************/
/***********************************************************************************
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
 ********************************************************************************/
void Can_Init (const Can_ConfigType* Config);
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
void Can_GetVersionInfo (Std_VersionInfoType* versioninfo);
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
void Can_DeInit (void);
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
Std_ReturnType Can_SetBaudrate (uint8 Controller,uint16 BaudRateConfigID);
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
Std_ReturnType Can_SetControllerMode (uint8 Controller,Can_ControllerStateType Transition);
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
void Can_DisableControllerInterrupts (uint8 Controller);
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
void Can_EnableControllerInterrupts (uint8 Controller);
/******************************************************************************
 * Service ID[hex]   	: 0x0b
 * Service name      	: Can_CheckWakeup
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Non Reentrant
 * Parameters (in)   	: Controller
                     	  Controller to be checked for a wakeup.
 * Parameters (inout)	: None
 * Parameters (out)  	: None
 * Return value      	: Std_ReturnType
  						  E_OK (API call has been accepted)
						  E_NOT_OK (API call has not been accepted)
 * Description       	: This function checks if a wakeup has occurred for the given controller.
******************************************************************************/
Std_ReturnType Can_CheckWakeup (uint8 Controller);
/******************************************************************************
 * Service ID[hex]		: 0x11
 * Service name			: Can_GetControllerErrorState
 * Sync/Async			: Synchronous
 * Reentrancy			: Non Reentrant
 * Parameters (in)		: Controller
 *                   	  CAN controller for which the status shall be changed
 * Parameters (out)		: ErrorStatePtr
 *                        Pointer to a memory location,
 *                        where the error state of the CAN controller will be stored.
 * Parameters (inout)	:  None
 * Return value			: Std_ReturnType
               	   	   	  E_OK (request accepted)
               	   	   	  E_NOT_OK (request not accepted)
 * Description:  This service obtains the error state of the CAN controller
******************************************************************************/
Std_ReturnType Can_GetControllerErrorState (uint8 ControllerId,Can_ErrorStateType* ErrorStatePtr);
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
Std_ReturnType Can_GetControllerMode (uint8 Controller,Can_ControllerStateType* ControllerModePtr);
/******************************************************************************
 * Service ID[hex]   	: 0x30
 * Service name      	: Can_GetControllerRxErrorCounter
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Non Reentrant for the same ControllerId
 * Parameters (in)   	: Controller
                     	  CAN controller, whose current Rx error counter shall be acquired.
 * Parameters (inout)	: None
 * Parameters (out)  	: RxErrorCounterPtr
						  Pointer to a memory location, where the current Rx error
						  counter of the CAN controller will be stored.
 * Return value      	: Std_ReturnType
  						  E_OK (Rx error counter available)
						  E_NOT_OK (Wrong ControllerId, or Rx error counter not available)
 * Description       	: Returns the Rx error counter for a CAN controller. This value might not be available
						  for all CAN controllers, in which case E_NOT_OK would be returned.
******************************************************************************/
Std_ReturnType Can_GetControllerRxErrorCounter (uint8 ControllerId,uint8* RxErrorCounterPtr);
/******************************************************************************
 * Service ID[hex]   	: 0x31
 * Service name      	: Can_GetControllerTxErrorCounter
 * Sync/Async        	: Synchronous
 * Reentrancy        	: Non Reentrant for the same ControllerId
 * Parameters (in)   	: Controller
                     	  CAN controller, whose current Tx error counter shall be acquired.
 * Parameters (inout)	: None
 * Parameters (out)  	: TxErrorCounterPtr
						  Pointer to a memory location, where the current Tx error
						  counter of the CAN controller will be stored.
 * Return value      	: Std_ReturnType
  						  E_OK (Tx error counter available)
						  E_NOT_OK (Wrong ControllerId, or Tx error counter not available)
 * Description       	: Returns the Tx error counter for a CAN controller. This value might not be available
						  for all CAN controllers, in which case E_NOT_OK would be returned.
******************************************************************************/
Std_ReturnType Can_GetControllerTxErrorCounter (uint8 ControllerId,uint8* TxErrorCounterPtr);
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
Std_ReturnType Can_Write (Can_HwHandleType Hth,const Can_PduType* PduInfo);
/******************************************************************************
 * Service ID[hex]: 0x08
 * Service name   : Can_MainFunction_Read
 * Mode           : Supervisor Mode (Privileged Mode)
 * Description    : This function performs the polling of RX indications when
                    CAN_RX_PROCESSING is set to POLLING.
 *******************************************************************************/
void Can_MainFunction_Read (void);
/*************************************************************************
 *************************************CallBack****************************
 ************************************************************************/
void MCAL_CAN_Mailbox_0_Empty_Callback(void);
void MCAL_CAN_Mailbox_1_Empty_Callback(void);
void MCAL_CAN_Mailbox_2_Empty_Callback(void);
void CanIf_TxConfirmation(PduIdType CanTxPduId);
void CanIf_RxIndication (const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr);
//void CanIf_RxIndication(Can_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, const uint8* CanSduPtr);
#define CanIf_ControllerModeType	Can_ControllerStateType
void CanIf_ControllerModeIndication(uint8 Controller, CanIf_ControllerModeType ControllerMode);
#endif /* CAN_H_ */
