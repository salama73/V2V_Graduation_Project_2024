/******************************************************************************
* @Module      :	 CAN
* @File Name   :	 Can_PBcfg.c
* @Description :	the Post-build configuration of the AUTOSAR Basic Software module CAN Driver.
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
#define CAN_VERSION_ID							    40
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION			4
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION			8
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION		    0
#define CAN_PBCFG_SW_RELEASE_MAJOR_VERSION			1
#define CAN_PBCFG_SW_RELEASE_MINOR_VERSION			0
#define CAN_PBCFG_SW_RELEASE_PATCH_VERSION		    0
#define VENDOR_ID								    100
/*****************************************************************************
							Includes
*****************************************************************************/
#include "Can.h"
Can_ConfigType Can =
{
	{
		{
			INTERRUPT,
			TRUE,
			0X40006400UL,
			CONTROLLER_ZERO,
			INTERRUPT,
			INTERRUPT,
			INTERRUPT,
			TRUE,
			.CanControllerBaudrateConfig =
			{
				{
					.CanControllerBaudRate = 1000U,
					.CanControllerSyncJumpWidth = 2U,
					.CanControllerPropSeg = 1U,
					.CanControllerSeg1 = 6U,
					.CanControllerSeg2 = 1U,
					.CanControllerBaudRateConfigID =(uint16)0,
				},
				{
					.CanControllerBaudRate = 500U,
					.CanControllerSyncJumpWidth = 4U,
					.CanControllerPropSeg = 1U,
					.CanControllerSeg1 = 2U,
					.CanControllerSeg2 = 1U,
					.CanControllerBaudRateConfigID =(uint16)1,
				}
			},
			&Can.CanConfigSet.CanController.CanControllerBaudrateConfig[1],
		},

		{
			{
				FULL,
				1U,
				STANDARD,
				0U,
				TRANSMIT,
				FALSE,
				&Can.CanConfigSet.CanController
			},
			{
					FULL,
					1U,
					STANDARD,
					1U,
					TRANSMIT,
					FALSE,
					&Can.CanConfigSet.CanController
			},
            {
    				FULL,
    				1U,
    				STANDARD,
    				2U,
					RECEIVE,
    				FALSE,
    				&Can.CanConfigSet.CanController,
					{
						0x000006FF,
						0x0U
					},
			},
            {
    				FULL,
    				1U,
    				STANDARD,
    				3U,
					RECEIVE,
    				FALSE,
    				&Can.CanConfigSet.CanController,
					{
	                    0x000007FF,
						0x0U
					},
			}
		}
	}
};
