/**************************************************************
 * File name  : CanIf_cbk.h
 * Created on : 5/10/2023
 * Author     : Salama Mohamed
 ****************************************************************/
#ifndef CANIF_CBK_H_
#define CANIF_CBK_H_

#include "Can.h"
void CanIf_RxIndication (const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr);
#endif /* CANIF_CBK_H_ */
