/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte.h
 * Generated on: Fri Mar 8 18:11:48 PST
 ********************************************************************/

#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"

#ifdef _WIN32
#define DECLSPEC_EXPORT __declspec(dllexport)
#else
#define DECLSPEC_EXPORT
#endif /* _WIN32 */


/* Predifined values for Std_ReturnType */
#define RTE_E_OK 				0
#define RTE_E_INVALID 			1
#define RTE_E_COMMS_ERROR 		128
#define RTE_E_TIMEOUT 			129
#define RTE_E_LIMIT 			130
#define RTE_E_NO_DATA 			131
#define RTE_E_TRANSMIT_ACK 		132
#define RTE_E_LOST_DATA 		64
#define RTE_E_MAX_AGE_EXCEEDED 	64

#endif /* RTE_H */
