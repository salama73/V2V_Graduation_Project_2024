/******************************************
 * File Name   : Event.h
 * Created on  : 28/11/2023
 * Author     : Salama mohamed
 *****************************************/
#ifndef INC_EVENT_H_
#define INC_EVENT_H_

#include "Type.h"

StatusType SetEvent(TaskRefType* TaskName,EventMaskType Mask);
StatusType ClearEvent(EventMaskType Mask);
StatusType GetEvent(TaskRefType* TaskName,EventMaskType* Event);
StatusType WaitEvent(EventMaskType Mask);
#endif /* INC_EVENT_H_ */
