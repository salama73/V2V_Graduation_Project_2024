/******************************************************************************
* @Module      			: CAN
* @File Name  			: Can_GeneralTypes.h
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
#ifndef CAN_GENERALTYPES_H_
#define CAN_GENERALTYPES_H_
/*****************************************************************************
							Source File Version Informations
*****************************************************************************/
#define CAN_VERSION_ID										11
#define CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION			4
#define CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION			8
#define CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION		    0
#define CAN_GENERALTYPES_SW_RELEASE_MAJOR_VERSION			1
#define CAN_GENERALTYPES_SW_RELEASE_MINOR_VERSION			0
#define CAN_GENERALTYPES_SW_RELEASE_PATCH_VERSION		    0
/*****************************************************************************
							Includes
*****************************************************************************/
#include "ComStack_Types.h"
// AUTOSAR checking ComStack_Types.h
#if ((CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION)\
||  (CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION  != COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION)\
||  (CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION  != COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The Autosar version of Std_Types.h does not match the Can_GeneralTypes version"
#endif
/*****************************************************************************
							 Type definitions
 ****************************************************************************/
#define POLLING 	0U
#define	INTERRUPT 	1U
#define Transmi_mailbox_0	   	(uint8)0
#define Transmi_mailbox_1		(uint8)1
#define Transmi_mailbox_2		(uint8)2
#define Transmi_mailbox_Full	(uint8)3
#define CAN_RTR_Data_Frame							((uint8)0)
#define CAN_RTR_Remote_Frame						((uint8)1)
#define CAN_IDE_Standard							((uint8)0)
#define CAN_IDE_Extended							((uint8)1)
/*
 Represents the Identifier of an L-PDU. The two most significant bits specify the frame
 type:
 00 CAN message with Standard CAN ID
 01 CAN FD frame with Standard CAN ID
 10 CAN message with Extended CAN ID
 11 CAN FD frame with Extended CAN ID
 */
typedef uint32 Can_IdType;
/*
 This type unites PduId (swPduHandle), SduLength (length), SduData (sdu), and Can
 Id (id) for any CAN L-SDU.
 */
typedef struct
{
	Can_IdType id;
	uint8* sdu;
	PduIdType swPduHandle;
	uint8 length;
}Can_PduType;
/*
  Represents the hardware object handles of a CAN hardware unit. For CAN hardware
  units with more than 255 HW objects use extended range.
 */
typedef uint8 Can_HwHandleType;
/*
 This type defines a data structure which clearly provides an Hardware Object Handle
 including its corresponding CAN Controller and therefore CanDrv as well as the specific CanId.
 */
typedef struct
{
	//Standard/Extended CAN ID of CAN L-PDU
	Can_IdType CanId;
	//ID of the corresponding Hardware Object Range
	Can_HwHandleType Hoh;
	//ControllerId provided by CanIf clearly identify the corresponding controller
	uint8 ControllerId;
}Can_HwType;
/************************************************************************************
 	 	 	 	 	 	 	 	 Extension to Std_ReturnType
***********************************************************************************/
// transmit request could not be processed because no transmit object was available
#define CAN_BUSY		((Std_ReturnType)0x02U)
/************************************************************************************
 	 	 	 	 	 	 	 	Can_ErrorStateType
 	 	 	 	 	 	 	 	"Error states of a CAN controller."
***********************************************************************************/
typedef enum
{
	// The CAN controller takes fully part in communication.
	CAN_ERRORSTATE_ACTIVE,
	//The CAN controller takes part in communication, but does not send active error frames.
	CAN_ERRORSTATE_PASSIVE,
	//The CAN controller does not take part in communication.
	CAN_ERRORSTATE_BUSOFF
}Can_ErrorStateType;
/************************************************************************************
 	 	 	 	 	 	 	 	 Can_ControllerStateType
***********************************************************************************/
typedef enum
{
	//CAN controller state UNINIT.
	CAN_CS_UNINIT,
	//CAN controller state STARTED.
	CAN_CS_STARTED,
	// CAN controller state STOPPED.
	CAN_CS_STOPPED,
	// CAN controller state SLEEP.
	CAN_CS_SLEEP
}Can_ControllerStateType;
/************************************************************************************
 	 	 	 	 	 	 	 	 Can_ErrorType
 	 	 	 	 	 	 	 	 "The enumeration represents a superset of CAN
 	 	 	 	 	 	 	 	 Error Types which typical CAN HW is
								 able to report. That means not all CAN HW will be able
								 to support the complete set."
***********************************************************************************/
typedef enum
{
	 //A 0 was transmitted and a 1 was read back
	CAN_ERROR_BIT_MONITORING1=1,
	// A 1 was transmitted and a 0 was read back
	CAN_ERROR_BIT_MONITORING0,
	//The HW reports a CAN bit error but cannot report distinguish between CAN_ERROR_BIT_MONITORING1 and CAN_ERROR_BIT_MONITORING0
	CAN_ERROR_BIT,
	// Acknowledgement check failed
	CAN_ERROR_CHECK_ACK_FAILED,
	// Acknowledgement delimiter check failed
	CAN_ERROR_ACK_DELIMITER,
	// The sender lost in arbitration.
	CAN_ERROR_ARBITRATION_LOST,
	//CAN overload detected via an overload frame. Indicates that the receive buffers of a receiver are full.
	CAN_ERROR_OVERLOAD,
	// Violations of the fixed frame format
	CAN_ERROR_CHECK_FORM_FAILED,
	//tuffing bits not as expected
	CAN_ERROR_CHECK_STUFFING_FAILED,
	// CRC failed
	CAN_ERROR_CHECK_CRC_FAILED,
	//Bus lock (Bus is stuck to dominant level)
	CAN_ERROR_BUS_LOCK
}Can_ErrorType;
//buffer for data RX or TX
typedef struct{
    uint32 ID;
    uint8 DLC;
    uint8 SDU [8];
    uint8 RTR;
    uint8 IDE;
}MessageObject;
//state and information for hardware object handle
typedef struct{
   boolean Object_Free;
   uint8 CanObjectId;
   uint8 mailbox;
   PduIdType swPduHandle;
}Message_Object_Status;
Can_HwType RX_Message;
#endif /* CAN_GENERALTYPES_H_ */
