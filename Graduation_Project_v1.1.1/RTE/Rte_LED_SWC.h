/********************************************************************
 * Filename: Rte_LED_SWC.h
 * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_LED_SWC_H
#define RTE_LED_SWC_H

#include "Rte_LED_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_LED_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_LED_SWC * const Rte_Inst_LED_SWC;

/************************ application errors *************************/


/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		RP_LED_Warning
 * Interface:	SRI_LED_Warning
 * DataElement:	LED_Warning
 * Runnable:	LED_SWC_Runnable
 *****************************************************/
extern my_uint8 Rte_IRead_LED_SWC_LED_SWC_Runnable_RP_LED_Warning_LED_Warning (void);
#ifndef IN_RTE_C
#define Rte_IRead_LED_SWC_Runnable_RP_LED_Warning_LED_Warning() \
	Rte_IRead_LED_SWC_LED_SWC_Runnable_RP_LED_Warning_LED_Warning()
#endif


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	LED_SWC_Runnable
 * DataElement: LED_Warning
 *****************************************************/
extern void LED_SWC(void);


/******** ARUnit-specific function pointers for server call delegates *********/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_LED_SWC_H */
