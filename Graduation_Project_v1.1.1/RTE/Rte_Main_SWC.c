/********************************************************************
 * Filename: Rte_Main_SWC_.c
 * Author	  : Andrew Nasser
 ********************************************************************/

#include "string.h"
#include "Rte_Main_SWC.h"


Rte_DE_CAN_FRAME Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame;


const Rte_CDS_Main_SWC Rte_Instance_Main_SWC = {
&Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame
};

const Rte_CDS_Main_SWC * const Rte_Inst_Main_SWC = &Rte_Instance_Main_SWC;


Std_ReturnType Main_SWC_RP_Call_BSW_Call_Subsystem_Buffer_retcode = RTE_E_OK;
Std_ReturnType Main_SWC_RP_Call_EEBL_Call_Subsystem_Buffer_retcode = RTE_E_OK;
Std_ReturnType Main_SWC_RP_Call_DNPW_Call_Subsystem_Buffer_retcode = RTE_E_OK;
Std_ReturnType Main_SWC_RP_Call_FCW_Call_Subsystem_Buffer_retcode = RTE_E_OK;
Std_ReturnType Main_SWC_RP_Call_IMA_Call_Subsystem_Buffer_retcode = RTE_E_OK;

FunctionPtr_Main_SWC_RP_Call_BSW_Call_Subsystem Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem_Delegate = 0;
FunctionPtr_Main_SWC_RP_Call_EEBL_Call_Subsystem Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem_Delegate = 0;
FunctionPtr_Main_SWC_RP_Call_DNPW_Call_Subsystem Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem_Delegate = 0;
FunctionPtr_Main_SWC_RP_Call_FCW_Call_Subsystem Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem_Delegate = 0;
FunctionPtr_Main_SWC_RP_Call_IMA_Call_Subsystem Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem_Delegate = 0;

const my_uint8* Rte_IRead_Main_SWC_Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame (void)
{
	return (Rte_Inst_Main_SWC)->Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame->value;
}
Std_ReturnType Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem (const my_uint8* CAN_Frame)
{
	Std_ReturnType __result = Main_SWC_RP_Call_BSW_Call_Subsystem_Buffer_retcode;
	if ( Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem_Delegate != 0 ) {
		__result = Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem_Delegate(CAN_Frame);
	}
	__result=BSW_SWC(CAN_Frame);
	return __result;
}
Std_ReturnType Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem (const my_uint8* CAN_Frame)
{
	Std_ReturnType __result = Main_SWC_RP_Call_EEBL_Call_Subsystem_Buffer_retcode;
	if ( Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem_Delegate != 0 ) {
		__result = Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem_Delegate(CAN_Frame);
	}
	__result=EEBL_SWC(CAN_Frame);
	return __result;
}
Std_ReturnType Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem (const my_uint8* CAN_Frame)
{
	Std_ReturnType __result = Main_SWC_RP_Call_DNPW_Call_Subsystem_Buffer_retcode;
	if ( Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem_Delegate != 0 ) {
		__result = Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem_Delegate(CAN_Frame);
	}
	__result=DNPW_SWC(CAN_Frame);
	return __result;
}
Std_ReturnType Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem (const my_uint8* CAN_Frame)
{
	Std_ReturnType __result = Main_SWC_RP_Call_FCW_Call_Subsystem_Buffer_retcode;
	if ( Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem_Delegate != 0 ) {
		__result = Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem_Delegate(CAN_Frame);
	}
	__result=FCW_SWC(CAN_Frame);
	return __result;
}
Std_ReturnType Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem (const my_uint8* CAN_Frame)
{
	Std_ReturnType __result = Main_SWC_RP_Call_IMA_Call_Subsystem_Buffer_retcode;
	if ( Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem_Delegate != 0 ) {
		__result = Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem_Delegate(CAN_Frame);
	}
	__result=IMA_SWC(CAN_Frame);
	return __result;
}
