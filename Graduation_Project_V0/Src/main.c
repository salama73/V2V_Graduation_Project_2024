/******************************************************************************
* @File Name   			: main.c
* Author       			: Salama Mohamed
*******************************************************************************/
#include "stm32f103x6.h"
#include "Can.h"
#include "Port.h"
#include "Pwm.h"
#include "Dio.h"

extern Pwm_ConfigType PWM_Config;
extern Can_ConfigType Can;
extern const Port_ConfigType Port;
extern uint8 COM_Data[8];
uint8 Data[8]={5,0X01,0X00,0X00,0X00,0X00,0X00,0X00};
Can_HwHandleType Hth=0;
Can_PduType PduInfo;

void delay_ms(uint8 ms)
{
	for(int i=0 ;i<ms;i++)
		for(int x=0;x<50;x++);
}

void ECUM_Init(void);

int main(void)
{
	RCC_GPIOA_CLK_Enable();
	RCC_TIM2_CLK_Enable();
	RCC_GPIOB_CLK_Enable();
	RCC_GPIOC_CLK_Enable();
	Port_Init(&Port);
	Pwm_Init(&PWM_Config);
    Can_Init(&Can);
    //Configuration Pdu
	PduInfo.id=0x000007ff;
	PduInfo.sdu=Data;
	PduInfo.swPduHandle=5;
	PduInfo.length=8;
	//Configuration Filter Bank 0
	CAN_Filter_Config_t Filter_Config;
	Filter_Config.Filter_Bank=CAN_Filter_Bank_0;
	Filter_Config.Filter_FIFO_Assignment=CAN_Filter_FIFO_Assignment_FIFO0;
	Filter_Config.Filter_ID=0XFFFFFFFF;
	Filter_Config.Filter_Mask_ID=0X00000000;
	Filter_Config.Filter_Mode=CAN_Filter_Mode_Mask;
	Filter_Config.Filter_Scale=CAN_Filter_Scale_32;
	MCAL_CAN_Config_Filter(&Filter_Config);
	Can_SetControllerMode(CONTROLLER_ZERO,CAN_CS_STARTED);

	ECUM_Init();

	while(1)
	{
		
	}
}
