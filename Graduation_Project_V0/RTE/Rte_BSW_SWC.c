/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_BSW_SWC_.c
 * Generated on: Wed Feb 7 23:44:23 GMT+02:00
 ********************************************************************/

#include "string.h"
#include "Rte_BSW_SWC.h"
#include "Task_Config.h"
#include "Event.h"

extern DeclareTask(Task3);
DeclareTask(Task4);

Rte_DE_my_uint8 BSW_SWC_Runnable_PP_LED_Warning_LED_Warning;
Rte_DE_my_uint8 BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed;


const Rte_CDS_BSW_SWC Rte_Instance_BSW_SWC = {
&BSW_SWC_Runnable_PP_LED_Warning_LED_Warning,
&BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed
};

const Rte_CDS_BSW_SWC * const Rte_Inst_BSW_SWC = &Rte_Instance_BSW_SWC;




void Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning (my_uint8 LED_Warning)
{
	(Rte_Inst_BSW_SWC)->BSW_SWC_Runnable_PP_LED_Warning_LED_Warning->value = LED_Warning;
	SetEvent(&Task3,0X0F);
}
my_uint8* Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(void)
{
	return &(Rte_Inst_BSW_SWC)->BSW_SWC_Runnable_PP_LED_Warning_LED_Warning->value;
}
void Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed (my_uint8 Motor_Speed)
{
	(Rte_Inst_BSW_SWC)->BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed->value = Motor_Speed;
	SetEvent(&Task4,0X1F);
}
my_uint8* Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(void)
{
	return &(Rte_Inst_BSW_SWC)->BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed->value;
}