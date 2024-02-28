/******************************************************
 *  File Name    : stm32_f103c6_CAN.h
 *  Created on   : 6/9/2023
 *  Author       : Salama mohamed
 *******************************************************/
#ifndef INC_STM32_F103C6_CAN_H_
#define INC_STM32_F103C6_CAN_H_
/*
 **************************************************************
 *************************Include File ************************
 **************************************************************
 */
#include "stm32f103x6.h"
/**************************************************************/
typedef struct
{
	uint32 Filter_ID;                   // Specifies the filter identification number
                                          // this parameter must be set from range 0X00000000 to 0XFFFFFFFF in 32 bit scale
										  // in 16 bit scale must contain 2 id from range 0X0000 to 0XFFFF (0X073F085F) ID1=0X073F ID2=0X085F

	uint32 Filter_Mask_ID;              // Specifies the filter mask number or identification number,
                                          // this parameter must be set from range 0X00000000 to 0XFFFFFFFF in 32 bit scale
										  // in 16 bit scale must contain 2 Mask from range 0X0000 to 0XFFFF (0X073F085F) mask1=0X073F mask2=0X085F

	uint32 Filter_FIFO_Assignment;      // Specifies the FIFO which will be assigned to the filter.
                                          // this parameter must be set based on  @ ref CAN_Filter_FIFO_Assignment_Define

	uint32 Filter_Bank;                 // Specifies the filter bank which will be initialized from 0 to 13
										  // this parameter must be set based on  @ ref CAN_Filter_Bank_Define

	uint32 Filter_Mode;                 // Specifies the filter mode to be initialized.
                                          // this parameter must be set based on  @ ref CAN_Filter_Mode_Define

	uint32 Filter_Scale;                // Specifies the filter scale.
                                          // this parameter must be set based on  @ ref CAN_Filter_Scale_Define
} CAN_Filter_Config_t;
//-----------------------------
//Macros Configuration References
//-----------------------------
//@ ref CAN_Filter_FIFO_Assignment_Define
#define CAN_Filter_FIFO_Assignment_FIFO0			((uint8)0)
#define CAN_Filter_FIFO_Assignment_FIFO1			((uint8)1)
//@ ref CAN_Filter_Bank_Define
#define CAN_Filter_Bank_0							((uint8)0)
#define CAN_Filter_Bank_1							((uint8)1)
#define CAN_Filter_Bank_2							((uint8)2)
#define CAN_Filter_Bank_3							((uint8)3)
#define CAN_Filter_Bank_4							((uint8)4)
#define CAN_Filter_Bank_5							((uint8)5)
#define CAN_Filter_Bank_6							((uint8)6)
#define CAN_Filter_Bank_7							((uint8)7)
#define CAN_Filter_Bank_8							((uint8)8)
#define CAN_Filter_Bank_9							((uint8)9)
#define CAN_Filter_Bank_10							((uint8)10)
#define CAN_Filter_Bank_11							((uint8)11)
#define CAN_Filter_Bank_12							((uint8)12)
#define CAN_Filter_Bank_13							((uint8)13)
//@ ref CAN_Filter_Mode_Define
#define CAN_Filter_Mode_Mask						((uint8)0)
#define CAN_Filter_Mode_List						((uint8)1)
//@ ref CAN_Filter_Scale_Define
#define CAN_Filter_Scale_16							((uint8)0)
#define CAN_Filter_Scale_32							((uint8)1)
/***********************************************************************
* *******************************APIS***********************************
* *********************************************************************/
void MCAL_CAN_Config_Filter(CAN_Filter_Config_t* Filter_Config);
#endif /* INC_STM32_F103C6_CAN_H_ */
