/********************************************************************
 * Filename: Rte_LCD_SWC.h
 * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_LCD_SWC_H
#define RTE_LCD_SWC_H

#include "Rte_LCD_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_LCD_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_LCD_SWC * const Rte_Inst_LCD_SWC;

/************************ application errors *************************/


/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		RP_LCD_Warning
 * Interface:	SRI_LED_Warning
 * DataElement:	LCD_Warning
 * Runnable:	LCD_SWC_Runnable
 *****************************************************/
extern my_uint8 Rte_IRead_LCD_SWC_LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning (void);
#ifndef IN_RTE_C
#define Rte_IRead_LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning() \
	Rte_IRead_LCD_SWC_LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning()
#endif


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	LCD_SWC_Runnable
 * DataElement: LCD_Warning
 *****************************************************/
extern void LCD_SWC(void);


/******** ARUnit-specific function pointers for server call delegates *********/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_LCD_SWC_H */
