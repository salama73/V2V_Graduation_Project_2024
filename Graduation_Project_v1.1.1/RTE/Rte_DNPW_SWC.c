/********************************************************************
 * Filename: Rte_DNPW_SWC_.c
 * Author	  : Andrew Nasser
 ********************************************************************/

#include "string.h"
#include "Rte_DNPW_SWC.h"


extern Rte_DE_my_uint8 LED_SWC_Runnable_RP_LED_Warning_LED_Warning;
extern Rte_DE_my_uint8 Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed;
extern Rte_DE_my_uint8 LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning;


const Rte_CDS_DNPW_SWC Rte_Instance_DNPW_SWC = {
&LED_SWC_Runnable_RP_LED_Warning_LED_Warning,
&Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed,
&LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning
};

const Rte_CDS_DNPW_SWC * const Rte_Inst_DNPW_SWC = &Rte_Instance_DNPW_SWC;




void Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning (my_uint8 LED_Warning)
{
	(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning->value = LED_Warning;
}
my_uint8* Rte_IWriteRef_DNPW_SWC_DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning(void)
{
	return &(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning->value;
}
void Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed (my_uint8 Motor_Speed)
{
	(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed->value = Motor_Speed;
}
my_uint8* Rte_IWriteRef_DNPW_SWC_DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(void)
{
	return &(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed->value;
}
void Rte_IWrite_DNPW_SWC_DNPW_SWC_Runnable_PP_LCD_LCD_Warning (my_uint8 LCD_Warning)
{
	(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_LCD_LCD_Warning->value = LCD_Warning;
}
my_uint8* Rte_IWriteRef_DNPW_SWC_DNPW_SWC_Runnable_PP_LCD_LCD_Warning(void)
{
	return &(Rte_Inst_DNPW_SWC)->DNPW_SWC_Runnable_PP_LCD_LCD_Warning->value;
}
