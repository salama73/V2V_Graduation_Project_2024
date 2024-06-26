/******************************************************************************
* @Module      :	 CAN
* @File Name   :	 Can_Cfg.h
* @Description :	 the Pre-compile configuration of the AUTOSAR Basic Software module CAN Driver.
* Author       :	 Salama Mohamed
*******************************************************************************/
/******************************************************************************
* Project				: Graduation_Project_2024
* Platform				: STM32F103C8
* Autosar Version		: 4.8.0
* SW Version		    : 1.0.0
******************************************************************************/
#ifndef CAN_CFG_H_
#define CAN_CFG_H_
/*****************************************************************************
							Source File Version Informations
*****************************************************************************/
#define CAN_VERSION_ID							    40
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION			4
#define CAN_CFG_AR_RELEASE_MINOR_VERSION			8
#define CAN_CFG_AR_RELEASE_PATCH_VERSION		    0
#define CAN_CFG_SW_RELEASE_MAJOR_VERSION			1
#define CAN_CFG_SW_RELEASE_MINOR_VERSION			0
#define CAN_CFG_SW_RELEASE_PATCH_VERSION		    0
#define VENDOR_ID								    100
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Std_Types.h"
/******************************************************************************
			Pre-compile configuration parameters of the PORT driver.
*******************************************************************************/
#define CanDevErrorDetect    						STD_ON
#define CONTROLLER_ZERO           				 	0U
#define Max_Num_HOH									((uint8)4)
#define Max_Num_Baud_Rate							((uint8)2)
#define BaudRateConfigID_0							((uint16)0)
#define BaudRateConfigID_1							((uint16)1)
#endif /* CAN_CFG_H_ */
