/*
 * Alarm.h
 *
 *  Created on: Mar 7, 2024
 *      Author: ELBOSTAN
 */

#ifndef INC_ALARM_H_
#define INC_ALARM_H_

#include "Type.h"

#define Max_Alarms 10
extern uint8 Alarms_Number;

typedef struct
{
	OS_Counters Counter;
	AlarmType Alarm_Id;
	TickType AlarmTime;
	TickType CycleTime;
}Alarm_Control;
extern Alarm_Control* Alarms[Max_Alarms];
#define DeclareAlarm(_AlarmIdentifier)	Alarm_Control Alarm_##_AlarmIdentifier

// format of the alarm-callback prototype
#define ALARMCALLBACK(AlarmCallbackRoutineName) void AlarmCallback_##AlarmCallbackRoutineName(void)

#define DefineAlarm(_AlarmIdentifier,_AlarmTime,_CycleTime,_CounterIdentifier)\
					{\
					 Alarm_##_AlarmIdentifier.Alarm_Id=_AlarmIdentifier;\
					 Alarm_##_AlarmIdentifier.AlarmTime=_AlarmTime;\
					 Alarm_##_AlarmIdentifier.CycleTime=_CycleTime;\
					 Alarm_##_AlarmIdentifier.Counter=SoftwareCounter_##_CounterIdentifier;\
					 Alarms[Alarms_Number]=&Alarm_##_AlarmIdentifier;\
					 Alarms_Number++;\
					}



StatusType GetAlarmBase(AlarmType AlarmID,AlarmBaseRefType Info);
StatusType CancelAlarm (AlarmType AlarmID);

#endif /* INC_ALARM_H_ */
