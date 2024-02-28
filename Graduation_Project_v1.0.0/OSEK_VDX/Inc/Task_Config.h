/************************************************
 * File Name   : Task_Config.h
 *  Created on : 27/11/2023
 *  Author     : Salama mohamed
 ************************************************/
#ifndef INC_TASK_CONFIG_H_
#define INC_TASK_CONFIG_H_

#include "Type.h"
//To refer to a task the constructional element should be used to declare the task before references to it
#define DeclareTask(TaskName)	TaskRefType TaskName
//
#define DefineTask(_TaskName, _Stack_Size,_AutoStart,_priority,_TaskSchedlerType,_TaskType) \
    { \
        _TaskName.P_TaskEntry = _TaskName##_Entry; \
        _TaskName.Stack_Size = _Stack_Size; \
        _TaskName.AutoStart = _AutoStart; \
        strcpy(_TaskName.Task_Name,#_TaskName); \
        _TaskName.priority = _priority; \
        _TaskName.TaskSchedlerType = _TaskSchedlerType; \
        MYRTOS_CreateTask(&_TaskName);\
        _TaskName.TaskType=_TaskType;\
    }
//
#define TASK(TaskName) void TaskName##_Entry(void)
/*
 Various requirements of the application software for the system and various capabilities of a
 specific system
 */
//only basic tasks, limited to one activation request per task and one task per priority
#define BCC1	0
//like BCC1, plus more than one task per priority possible and multiple requesting of task activation allowed
#define BCC2	1
//like BCC1, plus extended tasks
#define ECC1	2
//like ECC1, plus more than one task per priority possible and multiple requesting of task activation allowed for basic tasks
#define ECC2	3
#define Conformance_Classe ECC1
#endif /* INC_TASK_CONFIG_H_ */
