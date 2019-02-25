/*
 * TTC.h
 *
 * Created: 2/23/2019 2:19:01 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef TTC_H_
#define TTC_H_
#include "timer.h"
#include "task.h"

#define  max_size 3

	
/* struct that contains :
 * element 1: pointer to task function (void/void).
 * element 2: task periodicity (in OS_ticks unit) (Never changes at runtime)
 * element 3: runtime processing variable to detect remaining ticks before task execution at runtime
 */
	
typedef struct {
	ptr_fun ptr_task_fun ;
	uint32 priodic_time ;
	uint32 remaining_ticks ;
	uint8 task_periority ;
}TCB;




/********************************************************************************************************
* Function name :-   schedulerInit                                                                      *
* function job :-    initialize scheduler by initializing all tasks                                     *                                           *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void schedulerInit(void);
/********************************************************************************************************
* Function name :-   scheduler_start                                                                    *
* function job :-    initialize scheduler and run all task according to their order  it contain super loop                                   *                                           *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void Scheduler_Start (void);
/********************************************************************************************************
* Function name :- pre_filled_arr                                                                       *
* function job :-  function that responsible for calling tasks with specified time                      *                                           *
* function arguments :-    array of struct and its size                                                 *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void pre_filled_arr(TCB arr_fun[],uint32 size);
/*****************************************************************************************************
* Function name :-  scheduler_Add_Task                                                               *
* function job :-    its responsible for adding task to OS. it fills array of struct with new tasks  *
* function arguments :- pointer to function(task) , time of periodicity , task periority             *
* function return :-   true if task added successfully and false if it exceed max siz                *
*****************************************************************************************************/
uint8 scheduler_Add_Task(ptr_fun new_task,uint32 period, uint8 periority);
/********************************************************************************************************
* Function name :-     scheduler_Remove_Task                                                                        *
* function job :-   remove task during run time according to specific event                             *
* function arguments :-     pointer to function                                                         *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void scheduler_Remove_Task(ptr_fun task_remove);



#endif /* TTC_H_ */