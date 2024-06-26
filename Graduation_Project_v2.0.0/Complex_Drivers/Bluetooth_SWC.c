/*****************************************************
 * SWC        : Bluetooth_SWC.c
 * Created on : 16/3/2024
 * Author	  : Salama Mohamed
 * CDD_SWC
 *****************************************************/
#include "Bluetooth_SWC.h"
#include "Dio.h"
#include "RC_Car.h"
#include "Can.h"

#define master_1
extern uint8 Data[8];
extern Can_HwHandleType Hth;
extern Can_PduType PduInfo;

uint16 Andrew_Nasser();


void Bluetooth_Init(void)
{
	static USART_config_t Config;
	Config.BAUDRATE=USART_BAUDRATE_9600 ;
	Config.HWFLOWCTL=USART_HWFLOWCTL_Disable;
	Config.IRQ_EN=USART_IRQ_ENABLE_RXNE;
	Config.MODE=USART_MODE_TX_RX;
	Config.NUM_DATA_BIT=USART_NUM_DATA_BIT_8;
	Config.NUM_STOP_BIT=USART_NUM_STOP_BIT_1;
	Config.PARITY=USART_PARITY_Disable;
	Config.P_IRQ_CALL=USART1_IRQ_Call;
	MCAL_USART_Init(USART1, &Config);
}

/**************************************************************************/
unsigned char DATA  ;
void MCAL_GPIO_TogglePin(void)
{
	static uint8 x=0;
	if(x==0)
	{
		Dio_WriteChannel(channel_45,STD_LOW);
		x=1;
	}
	else if(x==1)
	{
		Dio_WriteChannel(channel_45,STD_HIGH);
		x=0;
	}
}

void Bluetooth_RX_Byte(uint8* PRXBuffer)
{
	MCAL_USART_ReceiveData(USART1,PRXBuffer,Disable);
}

uint16 zz=0;
#ifdef master_2
void USART1_IRQ_Call (void)
{
	 MCAL_GPIO_TogglePin();
	 Bluetooth_RX_Byte(&DATA);
	 switch (DATA)
	 {
	 case '1':
		 Data[0]=1;
		 Data[1]=1;
		 Can_Write(Hth,&PduInfo);
		 break;
	 case '2':
		 Data[0]=2;
		 Data[1]=90;
		 Data[2]=40;
		 Data[3]=1;
		 Data[4]=1;
		 Can_Write(Hth,&PduInfo);
		 break;
	 case '3':
		 Data[0]=3;
		 Data[1]=10;
		 Data[2]=40;
		 Data[3]=40;
		 Data[4]=60;
		 Can_Write(Hth,&PduInfo);
		 break;
	 case '4':
		 Data[0]=4;
		 Data[1]=150;
		 Can_Write(Hth,&PduInfo);
		 break;
	 case '5':
		 Data[0]=5;
		 Data[1]=10;
		 Can_Write(Hth,&PduInfo);
		 break;

	 }
}
#endif
#ifdef master_1
void USART1_IRQ_Call (void)
{
	 MCAL_GPIO_TogglePin();
	 Bluetooth_RX_Byte(&DATA);
	 switch (DATA)
	 {
	 case '0':
	 case '1':
	 case '2':
	 case '3':
	 case '4':
	 case '5':
		 Set_Speed(DATA-0x30);
		 break;
	case 'F':
		Forward_Dir();
		break;
	case 'B':
		Back_Dir();
		break;
	case 'L':
		Left_Dir();
		break;
	case 'R':
		Right_Dir();
		break;
	case 'S':
		Stop_Car();
		break;
	default:
		break;
	}
}
#endif
/**************************************************************************/
