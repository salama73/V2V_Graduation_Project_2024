/*
 * stm32_f103c6_RCC.h
 *  Created on: ٠٤‏/٠٩‏/٢٠٢٢
 *  Author: Salama mohamed
 */

#ifndef INC_STM32_F103C6_RCC_H_
#define INC_STM32_F103C6_RCC_H_

#include "stm32f103x6.h"

#define  HSI_oscillator_clock		(uint32)8000000
#define  HSE_oscillator_clock		(uint32)16000000

uint32 MCAL_Get_SYSCLC_FREQ(void);
uint32 MCAL_Get_HCLC_FREQ(void)  ;
uint32 MCAL_Get_PCLC1_FREQ(void) ;
uint32 MCAL_Get_PCLC2_FREQ(void) ;

#endif /* INC_STM32_F103C6_RCC_H_ */
