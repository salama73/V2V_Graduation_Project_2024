/********************************************************************
 * Filename: Rte_Motor_SWC_.c
 * Author	  : Andrew Nasser
 ********************************************************************/

#include "string.h"
#include "Rte_Motor_SWC.h"


Rte_DE_my_uint8 Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed;


const Rte_CDS_Motor_SWC Rte_Instance_Motor_SWC = {
&Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed
};

const Rte_CDS_Motor_SWC * const Rte_Inst_Motor_SWC = &Rte_Instance_Motor_SWC;




my_uint8 Rte_IRead_Motor_SWC_Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed (void)
{
	return (Rte_Inst_Motor_SWC)->Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed->value;
}
