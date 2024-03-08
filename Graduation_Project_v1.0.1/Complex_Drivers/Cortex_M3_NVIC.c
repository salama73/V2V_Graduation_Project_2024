/*****************************************************
 * SWC        : Cortex_M3_NVIC.c
 * Created on : 10/9/2023
 * Author	  : Salama Mohamed
 *****************************************************/
#include <Cortex_M3_NVIC.h>

void MCAL_NVIC_Enable_IRQ(uint8 IRQ_Position)
{
	//Each bit in the register corresponds to one of 32 interrupts.
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
		Set_Enable_Registe->ISER0|=1<<IRQ_Position;
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
		Set_Enable_Registe->ISER1|=1<<IRQ_Position;
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
		Set_Enable_Registe->ISER2|=1<<IRQ_Position;
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
		Set_Enable_Registe->ISER3|=1<<IRQ_Position;
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
		Set_Enable_Registe->ISER4|=1<<IRQ_Position;
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
		Set_Enable_Registe->ISER5|=1<<IRQ_Position;
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
		Set_Enable_Registe->ISER6|=1<<IRQ_Position;
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
		Set_Enable_Registe->ISER7|=1<<IRQ_Position;
	}
	else
	{
		//Error
	}
}
void MCAL_NVIC_Disable_IRQ(uint8 IRQ_Position)
{
	//Each bit in the register corresponds to one of 32 interrupts.
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
		Clear_Enable_Register->ICER0|=1<<IRQ_Position;
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
		Clear_Enable_Register->ICER1|=1<<IRQ_Position;
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
		Clear_Enable_Register->ICER2|=1<<IRQ_Position;
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
		Clear_Enable_Register->ICER3|=1<<IRQ_Position;
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
		Clear_Enable_Register->ICER4|=1<<IRQ_Position;
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
		Clear_Enable_Register->ICER5|=1<<IRQ_Position;
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
		Clear_Enable_Register->ICER6|=1<<IRQ_Position;
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
		Clear_Enable_Register->ICER7|=1<<IRQ_Position;
	}
	else
	{
		//Error
	}
}
IRQ_STATE MCAL_NVIC_Get_State_IRQ(uint8 IRQ_Position)
{
	IRQ_STATE State;
	//Each bit in the register corresponds to one of 32 interrupts.
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
		if(Set_Enable_Registe->ISER0&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
		if(Set_Enable_Registe->ISER1&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
		if(Set_Enable_Registe->ISER2&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
		if(Set_Enable_Registe->ISER3&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
		if(Set_Enable_Registe->ISER4&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
		if(Set_Enable_Registe->ISER5&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
		if(Set_Enable_Registe->ISER6&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
		if(Set_Enable_Registe->ISER7&(1<<IRQ_Position))
		{
			State=IRQ_ENABLE;
		}
		else
		{
			State=IRQ_DISABLE;
		}
	}
	else
	{
		//Error
	}
	return State;
}

void MCAL_Set_Pending_IRQ(uint8 IRQ_Position)
{
	//Each bit in the register corresponds to one of 32 interrupts.
	//force interrupts into the pending state
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
		Set_Pending_Register->ISPR0|=1<<IRQ_Position;
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
		Set_Pending_Register->ISPR1|=1<<IRQ_Position;
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
		Set_Pending_Register->ISPR2|=1<<IRQ_Position;
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
		Set_Pending_Register->ISPR3|=1<<IRQ_Position;
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
		Set_Pending_Register->ISPR4|=1<<IRQ_Position;
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
		Set_Pending_Register->ISPR5|=1<<IRQ_Position;
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
		Set_Pending_Register->ISPR6|=1<<IRQ_Position;
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
		Set_Pending_Register->ISPR7|=1<<IRQ_Position;
	}
	else
	{
		//Error
	}
}

void MCAL_Clear_Pending_IRQ(uint8 IRQ_Position)
{
	//Each bit in the register corresponds to one of 32 interrupts.
	//force interrupts into the pending state
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
		Clear_Pending_Register->ICPR0|=1<<IRQ_Position;
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
		Clear_Pending_Register->ICPR1|=1<<IRQ_Position;
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
		Clear_Pending_Register->ICPR2|=1<<IRQ_Position;
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
		Clear_Pending_Register->ICPR3|=1<<IRQ_Position;
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
		Clear_Pending_Register->ICPR4|=1<<IRQ_Position;
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
		Clear_Pending_Register->ICPR5|=1<<IRQ_Position;
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
		Clear_Pending_Register->ICPR6|=1<<IRQ_Position;
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
		Clear_Pending_Register->ICPR7|=1<<IRQ_Position;
	}
	else
	{
		//Error
	}
}

void MCAL_Set_Priority_IRQ(uint8 IRQ_Position,uint8 Priority)
{
	/*
	 Use the Interrupt Priority Registers to assign a priority from 0 to 255 to each of the
	 available interrupts. 0 is the highest priority, and 255 is the lowest.
	 */
	//Each bit in the register corresponds to one of 32 interrupts.
	volatile uint8 *Current_Register=NULL_PTR;
	uint32 Position;
	Position=(IRQ_Position/4)*4;
	if(IRQ_Position<32)
	{
		IRQ_Position-=0;
	}
	else if(IRQ_Position<64)
	{
		IRQ_Position-=32;
	}
	else if(IRQ_Position<96)
	{
		IRQ_Position-=64;
	}
	else if(IRQ_Position<127)
	{
		IRQ_Position-=96;
	}
	else if(IRQ_Position<160)
	{
		IRQ_Position-=127;
	}
	else if(IRQ_Position<192)
	{
		IRQ_Position-=160;
	}
	else if(IRQ_Position<223)
	{
		IRQ_Position-=192;
	}
	else if(IRQ_Position<256)
	{
		IRQ_Position-=223;
	}
	else
	{
		//Error
	}
	switch (IRQ_Position)
	{
		case 0:
		case 4:
		case 8:
		case 12:
		case 16:
		case 20:
		case 24:
		case 28:
			Current_Register=(volatile uint8*)(0XE000E400+Position);
			*Current_Register|=Priority;
			break;
		case 1:
		case 5:
		case 9:
		case 13:
		case 17:
		case 21:
		case 25:
		case 29:
			Current_Register=(volatile uint8*)(0XE000E400+Position+1);
			*Current_Register|=Priority;
			break;
		case 2:
		case 6:
		case 10:
		case 14:
		case 18:
		case 22:
		case 26:
		case 30:
			Current_Register=(volatile uint8*)(0XE000E400+Position+2);
			*Current_Register|=Priority;
			break;
		case 3:
		case 7:
		case 11:
		case 15:
		case 19:
		case 23:
		case 27:
		case 31:
			Current_Register=(volatile uint8*)(0XE000E400+Position+3);
			*Current_Register|=Priority;
			break;
		default:
			break;
	}
}
