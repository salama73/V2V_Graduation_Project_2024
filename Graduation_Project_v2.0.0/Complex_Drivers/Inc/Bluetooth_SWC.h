/*****************************************************
 * SWC        : Bluetooth_SWC.h
 * Created on : 16/3/2024
 * Author	  : Salama Mohamed
 * CDD_SWC
 *****************************************************/
#ifndef HC_05_BLUETOOTH_H_
#define HC_05_BLUETOOTH_H_
#include"stm32_f103c6_USART.h"

void Bluetooth_Init(void);
void Bluetooth_TX_Byte(uint8* PTXBuffer) ;
void Bluetooth_TX_Str(uint8* PTXBuffer) ;
void Bluetooth_RX_Byte(uint8* PRXBuffer) ;
void Bluetooth_RX_Str(uint8* PRXBuffer) ;
void ISR_Bluetooth (void) ;
void USART1_IRQ_Call (void);

#endif /* HC_05_BLUETOOTH_H_ */
