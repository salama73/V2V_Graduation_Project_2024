/**
 * @file Ecum.c
 * @author Salama Mohamed salamamohamedabdelaal@gmail.com
 * @brief  Initializes and de-initializes the OS, the SchM and the BswM as well as some
		   basic software driver modules
 * @version v1.0.0
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 */

#include "Ecum.h"

extern Pwm_ConfigType PWM_Config;
extern Can_ConfigType Can;
extern const Port_ConfigType Port;
extern Icu_ConfigType ICU_Config;
/**
 * @brief Initializes the ECU state manager and carries out the startup procedure. The function will never
		  return (it calls StartOS)
* @verbatim
 * ############################################################################
*  # Service ID [hex]	:	0x01
*  # Service Name		:	EcuM_Init
*  # Sync/Async			:	Synchronous
*  # Reentrancy			:	Reentrant
*  # Parameters (in)	:	None
*  # Parameters (inout):	None
*  # Parameters (out)	:	None
*  # Return value		:	None
*  # Description		:	Initializes the ECU state manager and carries out the startup procedure. The function will never return.
 * ############################################################################
 * @return None
 */
void EcuM_Init (void)
{
	RCC_GPIOA_CLK_Enable();
	RCC_TIM2_CLK_Enable();
	RCC_TIM3_CLK_Enable();
	RCC_GPIOB_CLK_Enable();
	RCC_GPIOC_CLK_Enable();
	RCC_USART1_CLK_Enable();
	RCC_TIM4_CLK_Enable();
	Port_Init(&Port);
	Bluetooth_Init();
	Icu_Init(&ICU_Config);
	Pwm_Init(&PWM_Config);
	Can_Init(&Can);
	Can_Filter();
	Os_Init();
}
