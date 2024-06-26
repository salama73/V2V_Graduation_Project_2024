/********************************************************************
 * Filename: Rte_LCD_SWC_.c
  * Author	  : Andrew Nasser
 ********************************************************************/

#include "string.h"
#include "Rte_LCD_SWC.h"


Rte_DE_my_uint8 LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning;


const Rte_CDS_LCD_SWC Rte_Instance_LCD_SWC = {
&LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning
};

const Rte_CDS_LCD_SWC * const Rte_Inst_LCD_SWC = &Rte_Instance_LCD_SWC;




my_uint8 Rte_IRead_LCD_SWC_LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning (void)
{
	return (Rte_Inst_LCD_SWC)->LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning->value;
}
