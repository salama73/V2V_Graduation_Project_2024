/**
 * @file main.c
 * @author Salama Mohamed salamamohamedabdelaal@gmail.com
 * @brief  This main file initializes an AUTOSAR project, performing initialization for all stacks,
 		   including  CAN stack and other necessary modules like OS kernel.
		   It ensures that all components are properly initialized before starting the main application.
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 *
 */
#include "stm32f103x6.h"
#include "Can.h"
#include "Port.h"
#include "Pwm.h"
#include "Dio.h"
#include "stm32_f103c6_CAN.h"
#include "Icu.h"
#include"stm32_f103c6_USART.h"
#include "Bluetooth_SWC.h"
#include "Rte_Type.h"
#include "delay.h"
#include "Ecum.h"
#include "Alarm.h"
#include "Counter.h"

uint8 Data[8]={0x02,0x95,0X40,0x1,0x1,0x2f,0x6f,0x8f};
Can_HwHandleType Hth=0;
Can_PduType PduInfo;

extern DeclareTask(Task1_Led_ON);
extern DeclareTask(Task2_Led_OFF);
extern DeclareTask(Task1);

/**
 * @brief This function configures a CAN filter to accept or reject incoming messages based on defined criteria.
 * @return None 
 */
void Can_Filter(void)
{
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
}
/**
 * @brief  The main function initializes the ECU Manager (EcuM) module, which is responsible
 		   for managing the startup and shutdown behavior of the electronic control unit (ECU).
 		   After initialization, the function enters an infinite loop, where it remains
           indefinitely, allowing the ECU to perform its designated tasks.
 * @return int 
 */
DeclareCounter(0);
DeclareAlarm(0);
DeclareAlarm(1);
DeclareAlarm(2);
AlarmBaseType Info_0;
//DeclareCounter(0);

void AlarmCallback_Alarm0(void)
{
	SetEvent(&Task1, 0x01);
	//ActivateTask(&Task1_Led_ON);
}
void AlarmCallback_Alarm1(void)
{
	//SetEvent(&Task2_Led_OFF, 0xf1);
	SetEvent(&Task1, 0x08);
	//ActivateTask(&Task2_Led_OFF);
}
void AlarmCallback_Alarm2(void)
{
	//SetEvent(&Task2_Led_OFF, 0xf1);
	SetEvent(&Task1, 0x02);
	//ActivateTask(&Task2_Led_OFF);
}
int main(void)
{
	//Task1_Entry();
	DefineCounter(0,2000,1,10);
	DefineAlarm(0,20,250,0);
	DefineAlarm(1,15,250,0);
	DefineAlarm(2,25,50,0);
	//DefineAlarm(1,50,999,0);
	PduInfo.id=0x15;
	PduInfo.sdu=Data;
	PduInfo.swPduHandle=5;
	PduInfo.length=8;
	EcuM_Init();
    //Can_Init(&Can);
    //Configuration Pdu
	//Can_Write(Hth,&PduInfo);
	while(1)
	{
		//delay_ms(1000);
		//Can_Write(Hth,&PduInfo);
	}
}
