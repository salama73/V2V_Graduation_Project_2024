/********************************************************************
 * Filename: Rte_Empty_For_Test_.c
 * Author	  : Andrew Nasser
 ********************************************************************/

#include "string.h"
#include "Rte_Empty_For_Test.h"
#include "Task_Config.h"
#include "Event.h"

extern DeclareTask(Task1);

Rte_DE_CAN_FRAME Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame;


const Rte_CDS_Empty_For_Test Rte_Instance_Empty_For_Test = {
&Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame
};

const Rte_CDS_Empty_For_Test * const Rte_Inst_Empty_For_Test = &Rte_Instance_Empty_For_Test;




void Rte_IWrite_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame (const my_uint8* CAN_Frame)
{
	memcpy((Rte_Inst_Empty_For_Test)->Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame->value, CAN_Frame, sizeof(my_uint8)*8);
	SetEvent(&Task1, 0xff);
}
my_uint8* Rte_IWriteRef_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame(void)
{
	return (Rte_Inst_Empty_For_Test)->Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame->value;
}
