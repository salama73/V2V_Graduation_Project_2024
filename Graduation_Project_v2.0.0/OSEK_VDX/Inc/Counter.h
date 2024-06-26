/*
 * Counter.h
 *
 *  Created on: May 2, 2024
 *      Author: slamh
 */

#ifndef INC_COUNTER_H_
#define INC_COUNTER_H_

#define Max_Counters 10
extern uint8 Counters_Number;

extern OS_Counters Counters[Max_Counters];
extern uint32 Conters_Value[Max_Counters];

//OS_Counters Software_counter={2000,1,10};

#define DeclareCounter(_CounterIdentifier)	OS_Counters SoftwareCounter_##_CounterIdentifier

#define DefineCounter(_CounterIdentifier,_maxallowedvalue,_ticksperbase,_mincycle)\
					{\
					 SoftwareCounter_##_CounterIdentifier.Counter_Ifo.maxallowedvalue=_maxallowedvalue;\
					 SoftwareCounter_##_CounterIdentifier.Counter_Ifo.ticksperbase=_ticksperbase;\
					 SoftwareCounter_##_CounterIdentifier.Counter_Ifo.mincycle=_mincycle;\
					 Counters[Counters_Number]=SoftwareCounter_##_CounterIdentifier;\
					 Conters_Value[Counters_Number]=0;\
					 Counters_Number++;\
					}

#endif /* INC_COUNTER_H_ */
