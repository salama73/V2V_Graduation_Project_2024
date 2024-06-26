/********************************************************************
 * Filename: Rte_Motor_SWC.h
 * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_MOTOR_SWC_H
#define RTE_MOTOR_SWC_H

#include "Rte_Motor_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_Motor_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_Motor_SWC * const Rte_Inst_Motor_SWC;

/************************ application errors *************************/


/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		RP_Motor_Speed
 * Interface:	SRI_Motor_Speed
 * DataElement:	Motor_Speed
 * Runnable:	Motor_SWC_Runnable
 *****************************************************/
extern my_uint8 Rte_IRead_Motor_SWC_Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed (void);
#ifndef IN_RTE_C
#define Rte_IRead_Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed() \
	Rte_IRead_Motor_SWC_Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed()
#endif


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	Motor_SWC_Runnable
 * DataElement: Motor_Speed
 *****************************************************/
extern void Motor_SWC(void);


/******** ARUnit-specific function pointers for server call delegates *********/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_MOTOR_SWC_H */
