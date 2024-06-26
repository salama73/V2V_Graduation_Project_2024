/*****************************************************
 * SWC        : Cortex_M3_NVIC.h
 * Created on : 10/9/2023
 * Author	  : Salama Mohamed
 *****************************************************/
#ifndef INC_CORTEX_M3_NVIC_H_
#define INC_CORTEX_M3_NVIC_H_

#include "stm32f103x6.h"

typedef enum
{
	IRQ_DISABLE,
	IRQ_ENABLE
}IRQ_STATE;

void MCAL_NVIC_Enable_IRQ(uint8 IRQ_Position);
void MCAL_NVIC_Disable_IRQ(uint8 IRQ_Position);
IRQ_STATE MCAL_NVIC_Get_State_IRQ(uint8 IRQ_Position);
void MCAL_Set_Pending_IRQ(uint8 IRQ_Position);
void MCAL_Clear_Pending_IRQ(uint8 IRQ_Position);
void MCAL_Set_Priority_IRQ(uint8 IRQ_Position,uint8 Priority);
#endif /* INC_CORTEX_M3_NVIC_H_ */
