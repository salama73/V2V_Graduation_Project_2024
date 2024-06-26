/**************************************************************
 * File name  : CanIf.c
 * Created on : 5/10/2023
 * Author     : Salama Mohamed
 ****************************************************************/
#include "CanIf_Cbk.h"

uint8 Data_RX[8]={0};
uint8 DLC_RX=0;
Can_HwType RX_Mailbox;
PduInfoType RX_PduInfoPtr;
Can_IdType ID=0;
Can_HwHandleType HrH=0;
/*
void CanIf_RxIndication (const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr)
{
	for(int i=0;i<8;i++)
	{
		Data_RX[i]=PduInfoPtr->SduDataPtr[i];
	}
	DLC_RX=PduInfoPtr->SduLength;
	ID=Mailbox->CanId;
	HrH=Mailbox->Hoh;
	RX_Mailbox.ControllerId=Mailbox->ControllerId;
	Rte_IWrite_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame(Data_RX);
}
*/
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{

}

void CanIf_ControllerModeIndication(uint8 Controller, CanIf_ControllerModeType ControllerMode)
{
}
