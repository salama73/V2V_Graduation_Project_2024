/*****************************************************
 * SWC        : Main_SWC.c
 * Created on : 27/2/2024
 * Author	  : Salama Mohamed
 *****************************************************
 * Port: 		RP_CAN_Frame
 * Interface:	SRI_CAN_Frame
 * DataElement:	CAN_Frame
 * Runnable:	Main_SWC_Runnable
 ******************************************************
 * Port: 		RP_Call_Subsystem
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 ******************************************************
 ************ event triggered runnable entities *******
 * Runnable: 	Main_SWC_Runnable
 * DataElement: CAN_Frame
 *****************************************************/
/******************************************************
 *********************Include**************************
 ******************************************************/
#include <Rte_Main_SWC.h>
#include "Event.h"
/*******************************************************
 **********************Definitions**********************
 *******************************************************/
const uint8* Frame=NULL_PTR;
/*******************************************************
 **********************Runnable*************************
 *******************************************************/
void Main_SWC(void)
{
	Frame=Rte_IRead_Main_SWC_Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame();
	switch(Frame[0])
	{
	case 1:
		Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem(Frame);
		break;
	case 2:
		Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem(Frame);
		break;
	case 3:
		Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem(Frame);
		break;
	case 4:
		Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem(Frame);
		break;
	case 5:
		Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem(Frame);
		break;
	default:
		break;
	}
}
