/********************************************************************
 * Filename: Rte_EEBL_SWC.h
  * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_EEBL_SWC_H
#define RTE_EEBL_SWC_H

#include "Rte_EEBL_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_EEBL_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_EEBL_SWC * const Rte_Inst_EEBL_SWC;

/************************ application errors *************************/

#define RTE_E_CSI_Call_Subsystem_E_NOT_OK ((Std_ReturnType)0)
#define RTE_E_CSI_Call_Subsystem_E_OK ((Std_ReturnType)1)

/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		PP_LED_Warning
 * Interface:	SRI_LED_Warning
 * DataElement:	LED_Warning
 * Runnable:	EEBL_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning (my_uint8 LED_Warning);
#ifndef IN_RTE_C
#define Rte_IWrite_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning(RTEData) \
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning() \
	Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning()
#endif

/*****************************************************
 * Port: 		PP_Call_Subsystem
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 *****************************************************/
extern Std_ReturnType BSW_SWC(const my_uint8* CAN_Frame) ;

/*****************************************************
 * Port: 		PP_Motor_Speed
 * Interface:	SRI_Motor_Speed
 * DataElement:	Motor_Speed
 * Runnable:	EEBL_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed (my_uint8 Motor_Speed);
#ifndef IN_RTE_C
#define Rte_IWrite_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed(RTEData) \
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed() \
	Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed()
#endif

/*****************************************************
 * Port: 		PP_LCD
 * Interface:	SRI_LCD_Warning
 * DataElement:	LCD_Warning
 * Runnable:	EEBL_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning (my_uint8 LCD_Warning);
#ifndef IN_RTE_C
#define Rte_IWrite_EEBL_SWC_Runnable_PP_LCD_LCD_Warning(RTEData) \
	Rte_IWrite_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_EEBL_SWC_Runnable_PP_LCD_LCD_Warning() \
	Rte_IWriteRef_EEBL_SWC_EEBL_SWC_Runnable_PP_LCD_LCD_Warning()
#endif


/**************** event triggered runnable entities *******************/


/******** ARUnit-specific function pointers for server call delegates *********/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_EEBL_SWC_H */
