/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_BSW_SWC.h
 * Generated on: Sat Mar 9 24:41:11 GMT+02:00
 ********************************************************************/

#ifndef RTE_BSW_SWC_H
#define RTE_BSW_SWC_H

#include "Rte_BSW_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_BSW_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_BSW_SWC * const Rte_Inst_BSW_SWC;

/************************ application errors *************************/

#define RTE_E_CSI_Call_Subsystem_E_NOT_OK ((Std_ReturnType)0)
#define RTE_E_CSI_Call_Subsystem_E_OK ((Std_ReturnType)1)
#define RTE_E_CSI_Get_Distance_E_NOT_OK ((Std_ReturnType)0)
#define RTE_E_CSI_Get_Distance_E_OK ((Std_ReturnType)1)

/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		PP_LED_Warning
 * Interface:	SRI_LED_Warning
 * DataElement:	LED_Warning
 * Runnable:	BSW_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning (my_uint8 LED_Warning);
#ifndef IN_RTE_C
#define Rte_IWrite_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(RTEData) \
	Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning() \
	Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_LED_Warning_LED_Warning()
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
 * Runnable:	BSW_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed (my_uint8 Motor_Speed);
#ifndef IN_RTE_C
#define Rte_IWrite_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(RTEData) \
	Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed() \
	Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed()
#endif

/*****************************************************
 * Port: 		PP_LCD
 * Interface:	SRI_LCD_Warning
 * DataElement:	LCD_Warning
 * Runnable:	BSW_SWC_Runnable
 *****************************************************/
extern void Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LCD_LCD_Warning (my_uint8 LCD_Warning);
#ifndef IN_RTE_C
#define Rte_IWrite_BSW_SWC_Runnable_PP_LCD_LCD_Warning(RTEData) \
	Rte_IWrite_BSW_SWC_BSW_SWC_Runnable_PP_LCD_LCD_Warning(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_LCD_LCD_Warning(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_BSW_SWC_Runnable_PP_LCD_LCD_Warning() \
	Rte_IWriteRef_BSW_SWC_BSW_SWC_Runnable_PP_LCD_LCD_Warning()
#endif

/*****************************************************
 * Port: 		RP_Get_Distance
 * Interface:	CSI_Get_Distance
 * Operation:	Call_Ultrasonic
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_BSW_SWC_RP_Get_Distance_Call_Ultrasonic (my_uint16* Distance);
#ifndef IN_RTE_C
#define Rte_Call_RP_Get_Distance_Call_Ultrasonic(Distance) \
	Rte_Call_BSW_SWC_RP_Get_Distance_Call_Ultrasonic(Distance)
#endif
/**************** event triggered runnable entities *******************/


/******** ARUnit-specific function pointers for server call delegates *********/
/******** ARUnit-specific function pointers for server call delegates *********/
typedef Std_ReturnType (*FunctionPtr_BSW_SWC_RP_Get_Distance_Call_Ultrasonic)(my_uint16* Distance);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_BSW_SWC_H */
