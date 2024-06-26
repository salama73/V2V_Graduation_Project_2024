/*
 * Alarm.c
 *
 *  Created on: Mar 7, 2024
 *      Author: ELBOSTAN
 */

#include "Alarm.h"

Alarm_Control* Alarms[Max_Alarms]={0};
uint8 Alarms_Number=0;

StatusType GetAlarmBase(AlarmType AlarmID,AlarmBaseRefType Info)
{
	StatusType Status=E_OK;
	if(AlarmID>Alarms_Number)
	{
		Status=E_OS_ID;
		return Status;
	}
	else
	{
		for(uint8 index=0;index<Max_Alarms;index++)
		{
			if(Alarms[index]->Alarm_Id==AlarmID)
			{
				Info->maxallowedvalue=Alarms[index]->Counter.Counter_Ifo.maxallowedvalue;
				Info->mincycle=Alarms[index]->Counter.Counter_Ifo.mincycle;
				Info->ticksperbase=Alarms[index]->Counter.Counter_Ifo.ticksperbase;
				break;
			}
			else
			{
				//
			}
		}
	}
	return Status;
}

StatusType CancelAlarm (AlarmType AlarmID)
{
	StatusType Status=E_OK;
	if(AlarmID>Alarms_Number)
	{
		Status=E_OS_ID;
		return Status;
	}
	else
	{
		for(uint8 index=0;index<Alarms_Number;index++)
		{
			if(Alarms[index]->Alarm_Id==AlarmID)
			{
				Alarms[index]=NULL_PTR;
				for(uint8 i=index;i<index-1;i++)
				{
					Alarms[index]=Alarms[index+1];
				}
				Alarms[Alarms_Number-1]=NULL_PTR;
				break;
			}

			else
			{
				//
			}
		}
	}
	return Status;
}
