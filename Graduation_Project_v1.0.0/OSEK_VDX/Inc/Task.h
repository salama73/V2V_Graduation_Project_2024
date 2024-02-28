/************************************************
 * File Name   : Task.h
 *  Created on : 20/11/2023
 *  Author     : Salama mohamed
 ************************************************/
#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "Type.h"

typedef uint8_t TaskType ;

#define MaxTaskId	20



StatusType TerminateTask(void);
StatusType ActivateTask(TaskRefType* TaskName);
StatusType ChainTask(TaskRefType* TaskName);
StatusType Schedule(void);
StatusType GetTaskId(TaskRefType* TaskName);
StatusType GetTaskState(TaskRefType TaskName,TaskStateType State);
#endif /* INC_TASK_H_ */
