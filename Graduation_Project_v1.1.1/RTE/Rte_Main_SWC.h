/********************************************************************
 * Filename: Rte_Main_SWC.h
 * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_MAIN_SWC_H
#define RTE_MAIN_SWC_H

#include "Rte_Main_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_Main_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_Main_SWC * const Rte_Inst_Main_SWC;

/************************ application errors *************************/

#define RTE_E_CSI_Call_Subsystem_E_NOT_OK ((Std_ReturnType)0)
#define RTE_E_CSI_Call_Subsystem_E_OK ((Std_ReturnType)1)

/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		RP_CAN_Frame
 * Interface:	SRI_CAN_Frame
 * DataElement:	CAN_Frame
 * Runnable:	Main_SWC_Runnable
 *****************************************************/
extern const my_uint8* Rte_IRead_Main_SWC_Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame (void);
#ifndef IN_RTE_C
#define Rte_IRead_Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame() \
	Rte_IRead_Main_SWC_Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame()
#endif

/*****************************************************
 * Port: 		RP_Call_BSW
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_Call_RP_Call_BSW_Call_Subsystem(CAN_Frame) \
	Rte_Call_Main_SWC_RP_Call_BSW_Call_Subsystem(CAN_Frame)
#endif

/*****************************************************
 * Port: 		RP_Call_EEBL
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_Call_RP_Call_EEBL_Call_Subsystem(CAN_Frame) \
	Rte_Call_Main_SWC_RP_Call_EEBL_Call_Subsystem(CAN_Frame)
#endif

/*****************************************************
 * Port: 		RP_Call_DNPW
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_Call_RP_Call_DNPW_Call_Subsystem(CAN_Frame) \
	Rte_Call_Main_SWC_RP_Call_DNPW_Call_Subsystem(CAN_Frame)
#endif

/*****************************************************
 * Port: 		RP_Call_FCW
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_Call_RP_Call_FCW_Call_Subsystem(CAN_Frame) \
	Rte_Call_Main_SWC_RP_Call_FCW_Call_Subsystem(CAN_Frame)
#endif

/*****************************************************
 * Port: 		RP_Call_IMA
 * Interface:	CSI_Call_Subsystem
 * Operation:	Call_Subsystem
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_Call_RP_Call_IMA_Call_Subsystem(CAN_Frame) \
	Rte_Call_Main_SWC_RP_Call_IMA_Call_Subsystem(CAN_Frame)
#endif


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	Main_SWC_Runnable
 * DataElement: CAN_Frame
 *****************************************************/
extern void Main_SWC(void);


/******** ARUnit-specific function pointers for server call delegates *********/
typedef Std_ReturnType (*FunctionPtr_Main_SWC_RP_Call_BSW_Call_Subsystem)(const my_uint8* CAN_Frame);
typedef Std_ReturnType (*FunctionPtr_Main_SWC_RP_Call_EEBL_Call_Subsystem)(const my_uint8* CAN_Frame);
typedef Std_ReturnType (*FunctionPtr_Main_SWC_RP_Call_DNPW_Call_Subsystem)(const my_uint8* CAN_Frame);
typedef Std_ReturnType (*FunctionPtr_Main_SWC_RP_Call_FCW_Call_Subsystem)(const my_uint8* CAN_Frame);
typedef Std_ReturnType (*FunctionPtr_Main_SWC_RP_Call_IMA_Call_Subsystem)(const my_uint8* CAN_Frame);


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_MAIN_SWC_H */
