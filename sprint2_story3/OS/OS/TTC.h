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
typedef void (*ptr_fun) (void);
	
	
typedef struct {
	ptr_fun ptr_task_fun ;
	uint32 priodic_time ;
	uint32 remaining_ticks ;
	uint8 task_periority ;
}TCB;





void schedulerInit(void);
void Scheduler_Start (void);
void pre_filled_arr(TCB arr_fun[],uint32 size);
uint8 scheduler_Add_Task(ptr_fun new_task,uint32 period, uint8 periority);





#endif /* TTC_H_ */