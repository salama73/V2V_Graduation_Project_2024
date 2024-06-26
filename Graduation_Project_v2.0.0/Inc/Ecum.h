/**
 * @file Ecum.h
 * @author Salama Mohamed salamamohamedabdelaal@gmail.com
 * @brief  Initializes and de-initializes the OS, the SchM and the BswM as well as some
		   basic software driver modules
 * @version v1.0.0
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 *
 */
#ifndef ECUM_H_
#define ECUM_H_

#include "Port.h"
#include "Can.h"
#include "Pwm.h"
#include "Icu.h"
#include "stm32f103x6.h"
#include "Bluetooth_SWC.h"
#include "Task_Config.h"

void EcuM_Init (void);
void Can_Filter(void);

#endif /* ECUM_H_ */
