/********************************************************************
 * Filename: Rte_Type.h
  * Author	  : Andrew Nasser
 ********************************************************************/

#ifndef RTE_TYPE_H
#define RTE_TYPE_H


#include "Rte.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**************************** datatypes ******************************/

typedef unsigned char my_uint8;
typedef my_uint8 CAN_FRAME[8];


/********************* mode declaration groups ***********************/


/********************** per instance memories ************************/


/******************* implicit buffer declaration *********************/

typedef struct {
	my_uint8 value;
} Rte_DE_my_uint8;

typedef struct {
	CAN_FRAME value;
} Rte_DE_CAN_FRAME;


/******************** component data structures **********************/

/*********************************************************************
 * component data structure for SWC: Main_SWC 
 *********************************************************************/
typedef struct Rte_CDS_Main_SWC
{
	/* Data Handles section*/
	Rte_DE_CAN_FRAME *Main_SWC_Runnable_RP_CAN_Frame_CAN_Frame;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_Main_SWC;

/*********************************************************************
 * component data structure for SWC: Empty_For_Test 
 *********************************************************************/
typedef struct Rte_CDS_Empty_For_Test
{
	/* Data Handles section*/
	Rte_DE_CAN_FRAME *Empty_For_Test_Runnable_PP_CAN_Frame_CAN_Frame;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_Empty_For_Test;

/*********************************************************************
 * component data structure for SWC: BSW_SWC 
 *********************************************************************/
typedef struct Rte_CDS_BSW_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *BSW_SWC_Runnable_PP_LED_Warning_LED_Warning;
	Rte_DE_my_uint8 *BSW_SWC_Runnable_PP_Motor_Speed_Motor_Speed;
	Rte_DE_my_uint8 *BSW_SWC_Runnable_PP_LCD_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_BSW_SWC;

/*********************************************************************
 * component data structure for SWC: LED_SWC 
 *********************************************************************/
typedef struct Rte_CDS_LED_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *LED_SWC_Runnable_RP_LED_Warning_LED_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_LED_SWC;

/*********************************************************************
 * component data structure for SWC: Motor_SWC 
 *********************************************************************/
typedef struct Rte_CDS_Motor_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_Motor_SWC;

/*********************************************************************
 * component data structure for SWC: EEBL_SWC 
 *********************************************************************/
typedef struct Rte_CDS_EEBL_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *EEBL_SWC_Runnable_PP_LED_Warning_LED_Warning;
	Rte_DE_my_uint8 *EEBL_SWC_Runnable_PP_Motor_Speed_Motor_Speed;
	Rte_DE_my_uint8 *EEBL_SWC_Runnable_PP_LCD_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_EEBL_SWC;

/*********************************************************************
 * component data structure for SWC: DNPW_SWC 
 *********************************************************************/
typedef struct Rte_CDS_DNPW_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *DNPW_SWC_Runnable_PP_LED_Warning_LED_Warning;
	Rte_DE_my_uint8 *DNPW_SWC_Runnable_PP_Motor_Speed_Motor_Speed;
	Rte_DE_my_uint8 *DNPW_SWC_Runnable_PP_LCD_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_DNPW_SWC;

/*********************************************************************
 * component data structure for SWC: FCW_SWC 
 *********************************************************************/
typedef struct Rte_CDS_FCW_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *FCW_SWC_Runnable_PP_LED_Warning_LED_Warning;
	Rte_DE_my_uint8 *FCW_SWC_Runnable_PP_Motor_Speed_Motor_Speed;
	Rte_DE_my_uint8 *FCW_SWC_Runnable_PP_LCD_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_FCW_SWC;

/*********************************************************************
 * component data structure for SWC: IMA_SWC 
 *********************************************************************/
typedef struct Rte_CDS_IMA_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *IMA_SWC_Runnable_PP_LED_Warning_LED_Warning;
	Rte_DE_my_uint8 *IMA_SWC_Runnable_PP_Motor_Speed_Motor_Speed;
	Rte_DE_my_uint8 *IMA_SWC_Runnable_PP_LCD_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_IMA_SWC;

/*********************************************************************
 * component data structure for SWC: LCD_SWC 
 *********************************************************************/
typedef struct Rte_CDS_LCD_SWC
{
	/* Data Handles section*/
	Rte_DE_my_uint8 *LCD_SWC_Runnable_RP_LCD_Warning_LCD_Warning;
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
} Rte_CDS_LCD_SWC;

/*********************************************************************
 * component data structure for SWC: Composition_SWC 
 *********************************************************************/
typedef struct Rte_CDS_Composition_SWC
{
	/* Data Handles section*/
	/* Per-Instance Memory Handles section*/
	/* Inter-runnable Variable Handles section*/
	/* Calibration Parameter Handles section*/
	/* Exclusive-area Handles section*/
	/* Port API Handles section*/
	/* Inter Runnable Variable API Handles section*/
	uint8 _dummy;
} Rte_CDS_Composition_SWC;


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_TYPE_H */
