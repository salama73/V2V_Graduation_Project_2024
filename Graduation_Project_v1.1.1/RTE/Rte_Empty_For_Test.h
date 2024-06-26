/********************************************************************
 * Filename: Rte_Empty_For_Test.h
  * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_EMPTY_FOR_TEST_H
#define RTE_EMPTY_FOR_TEST_H

#include "Rte_Empty_For_Test_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_Empty_For_Test * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_Empty_For_Test * const Rte_Inst_Empty_For_Test;

/************************ application errors *************************/


/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		PP_CAN_Frame
 * Interface:	SRI_CAN_Frame
 * DataElement:	CAN_Frame
 * Runnable:	Empty_For_Test_Runnable
 *****************************************************/
extern void Rte_IWrite_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame (const my_uint8* CAN_Frame);
#ifndef IN_RTE_C
#define Rte_IWrite_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame(RTEData) \
	Rte_IWrite_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame(RTEData)
#endif
extern my_uint8* Rte_IWriteRef_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame(void);
#ifndef IN_RTE_C
#define Rte_IWriteRef_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame() \
	Rte_IWriteRef_Empty_For_Test_Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame()
#endif


/**************** event triggered runnable entities *******************/


/******** ARUnit-specific function pointers for server call delegates *********/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_EMPTY_FOR_TEST_H */
