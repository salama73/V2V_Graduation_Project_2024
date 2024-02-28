/******************************************************
 *  File Name    : stm32_f103c6_CAN.c
 *  Created on   : 6/9/2023
 *  Author       : Salama mohamed
 *******************************************************/
#include "stm32_f103c6_CAN.h"

/**================================================================
* @Fn				-MCAL_CAN_Config_Filter
* @brief		  	-Initializes the CAN Filters to the specified parameters in the Filter_Config
* 					 @ ref  CAN_Filter_Bank_Define  and @ ref  CAN_Filter_Mode_Define and @ ref  CAN_Filter_Scale_Define and ....
* @param [in] 		-Filter_Config: configuration information for the specified Can Filter
* @retval 			-Can_Status_t	status of Can hardware (CAN_OK,CAN_ERROR,...)
* Note				-None
*/
void MCAL_CAN_Config_Filter(CAN_Filter_Config_t* Filter_Config)
{
	// Current Filter Bank
	CAN_Filter_Bank_TypeDef* Current_Bank ;
	switch (Filter_Config->Filter_Bank)
	{
		case CAN_Filter_Bank_0:
			Current_Bank=CAN_FBank_0;
			break;
		case CAN_Filter_Bank_1:
			Current_Bank=CAN_FBank_1;
			break;
		case CAN_Filter_Bank_2:
			Current_Bank=CAN_FBank_2;
			break;
		case CAN_Filter_Bank_3:
			Current_Bank=CAN_FBank_3;
			break;
		case CAN_Filter_Bank_4:
			Current_Bank=CAN_FBank_4;
			break;
		case CAN_Filter_Bank_5:
			Current_Bank=CAN_FBank_5;
			break;
		case CAN_Filter_Bank_6:
			Current_Bank=CAN_FBank_6;
			break;
		case CAN_Filter_Bank_7:
			Current_Bank=CAN_FBank_7;
			break;
		case CAN_Filter_Bank_8:
			Current_Bank=CAN_FBank_8;
			break;
		case CAN_Filter_Bank_9:
			Current_Bank=CAN_FBank_9;
			break;
		case CAN_Filter_Bank_10:
			Current_Bank=CAN_FBank_10;
			break;
		case CAN_Filter_Bank_11:
			Current_Bank=CAN_FBank_11;
			break;
		case CAN_Filter_Bank_12:
			Current_Bank=CAN_FBank_12;
			break;
		case CAN_Filter_Bank_13:
			Current_Bank=CAN_FBank_13;
			break;
		default:
			break;
	}
	// To configure a filter bank it must be deactivated by clearing the FACT bit in the CAN_FAR register
	// Initialization mode for the filters
	CAN_FMR |=(1<<0);
	//Filter x is not active
	CAN_FA1R &=~(1<<Filter_Config->Filter_Bank);
	// The filter scale is configured by means of the corresponding FSCx bit in the CAN_FS1R register
	switch (Filter_Config->Filter_Scale)
	{
		case CAN_Filter_Scale_16:
			CAN_FS1R &=~(1<<Filter_Config->Filter_Bank);
			// configure filter bank
			Current_Bank->CAN_FiR1=(Filter_Config->Filter_ID &(0xffff))|((Filter_Config->Filter_Mask_ID &(0xffff))<<16);
			Current_Bank->CAN_FiR2=((Filter_Config->Filter_ID &(0xffff0000))>>16)|(Filter_Config->Filter_Mask_ID &(0xffff0000));
			break;
		case CAN_Filter_Scale_32:
			CAN_FS1R |=(1<<Filter_Config->Filter_Bank);
			// configure filter bank
			Current_Bank->CAN_FiR1=Filter_Config->Filter_ID;
			Current_Bank->CAN_FiR2=Filter_Config->Filter_Mask_ID;
			break;
		default:
			break;
	}
	//The identifier list or identifier mask mode is configured by means of the FBMx bits in the CAN_FM1R register.
	switch (Filter_Config->Filter_Mode)
	{
		case CAN_Filter_Mode_Mask:
			CAN_FM1R &=~(1<<Filter_Config->Filter_Bank);
			break;
		case CAN_Filter_Mode_List:
			CAN_FM1R |=(1<<Filter_Config->Filter_Bank);
			break;
		default:
			break;
	}
	//The message passing through this filter will be stored in the specified FIFO
	switch (Filter_Config->Filter_FIFO_Assignment)
	{
		case CAN_Filter_FIFO_Assignment_FIFO0:
			CAN_FFA1R &=~(1<<Filter_Config->Filter_Bank);
			break;
		case CAN_Filter_FIFO_Assignment_FIFO1:
			CAN_FFA1R |=(1<<Filter_Config->Filter_Bank);
			break;
		default:
			break;
	}
	// Filter Bank active mode
	CAN_FMR &=~(1<<0);
	//Filter x is not active
	CAN_FA1R |=(1<<Filter_Config->Filter_Bank);
}
