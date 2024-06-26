/******************************************************************************
* @Module      			: COM_Stack
* @File Name   			: ComStack_Types.h
* @Description			: This document specifies the AUTOSAR communication stack type header file. It
						  contains all types that are used across several modules of the communication stack
						  of the basic software and all types of all basic software modules that are platform and
						  compiler independent.
* Author       			: Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#ifndef COMSTACK_TYPES_H_
#define COMSTACK_TYPES_H_
/*****************************************************************************
							Source File Version Informations
*****************************************************************************/
#define COMSTACK_TYPES_VERSION_ID							50
#define COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION				4
#define COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION				8
#define COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION		   		0
#define COMSTACK_TYPES_SW_RELEASE_MAJOR_VERSION				1
#define COMSTACK_TYPES_SW_RELEASE_MINOR_VERSION				0
#define CCOMSTACK_TYPES_SW_RELEASE_PATCH_VERSION		    0
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Std_Types.h"
// AUTOSAR checking Std_Version
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION)\
||  (STD_TYPES_AR_RELEASE_MINOR_VERSION  != COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION)\
||  (STD_TYPES_AR_RELEASE_PATCH_VERSION  != COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The Autosar version of Std_Types.h does not match the COM version"
#endif
/*****************************************************************************
							 Type definitions
 ****************************************************************************/
/*
 The size of this global type depends on the maximum number of PDUs
 used within one software module.
 */
/*
 [SWS_Comtype_00006] Variables of this type serve as a unique identifier of a PDU
 within a software module or a set thereof, and also for interaction of two software
 modules where the PduId of the corresponding target module is being used for
 referencing.
 */
typedef uint8	PduIdType;
/*
 The size of this global type depends on the maximum length of PDUs
 to be sent by an ECU.
 */
typedef	uint8  PduLengthType;
/*
 Variables of this type shall be used to store the basic information about a PDU of any
 type, namely a pointer variable pointing to its SDU (payload), a pointer to Meta Data of
 the PDU, and the corresponding length of the SDU in bytes.
 */
typedef struct
{
	/*
	 Pointer to the SDU (i.e. payload data) of the PDU. The type of this pointer
     depends on the memory model being used at compile time.
	 */
	uint8*                            SduDataPtr;
	//Length of the SDU in bytes.
	PduLengthType                     SduLength;
}PduInfoType;
#endif /* COMSTACK_TYPES_H_ */
