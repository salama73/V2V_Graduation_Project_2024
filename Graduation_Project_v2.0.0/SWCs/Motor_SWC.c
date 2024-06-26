/*****************************************************
 * SWC        : Motor_SWC.C
 * Created on : 28/2/2024
 * Author	  : Salama Mohamed
 *****************************************************
 * Port       : RP_Motor_Speed
 * Interface  :	SRI_Motor_Speed
 * DataElement:	Motor_Speed
 * Runnable	  :	Motor_SWC_Runnable
 ***********event triggered runnable entities*********
 * Runnable	  : Motor_SWC_Runnable
 * DataElement: Motor_Speed
 *****************************************************/
/******************************************************
 *********************Include**************************
 ******************************************************/
#include "Rte_Motor_SWC.h"
#include "Pwm.h"
#define Stop                 0
#define LOW_Speed            1
#define HIGH_Speed           2
#define Super_Speed          3
/*******************************************************
 **********************Runnable*************************
 *******************************************************/
void Motor_SWC(void)
{
	uint8 Speed;
	uint16 Dutycycle;
	Speed=Rte_IRead_Motor_SWC_Motor_SWC_Runnable_RP_Motor_Speed_Motor_Speed();
	Dutycycle=Speed*6553;
	Pwm_SetDutyCycle(PwmChannelId_0,Dutycycle);
	Pwm_SetDutyCycle(PwmChannelId_1,Dutycycle);
	Pwm_SetDutyCycle(PwmChannelId_2,Dutycycle);
	Pwm_SetDutyCycle(PwmChannelId_3,Dutycycle);
}
