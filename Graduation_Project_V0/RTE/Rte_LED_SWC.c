/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_LED_SWC_.c
 * Generated on: Wed Feb 7 23:44:23 GMT+02:00
 ********************************************************************/

#include "string.h"
#include "Rte_LED_SWC.h"


extern Rte_DE_my_uint8 BSW_SWC_Runnable_PP_LED_Warning_LED_Warning;


const Rte_CDS_LED_SWC Rte_Instance_LED_SWC = {
&BSW_SWC_Runnable_PP_LED_Warning_LED_Warning
};

const Rte_CDS_LED_SWC * const Rte_Inst_LED_SWC = &Rte_Instance_LED_SWC;




my_uint8 Rte_IRead_LED_SWC_LED_SWC_Runnable_RP_LED_Warning_LED_Warning (void)
{
	return (Rte_Inst_LED_SWC)->LED_SWC_Runnable_RP_LED_Warning_LED_Warning->value;
}
