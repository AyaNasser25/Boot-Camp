/*
 * TTC.c
 *
 * Created: 2/23/2019 2:18:23 PM
 *  Author: AVE-LAP-023
 */ 
#include "TTC.h"

static void set_callback_flag(void);

 extern TCB Task_1,Task_2;
  TCB task_arr[max_size];
 uint32 g_index ;
volatile uint8 g_flag;
/********************************************************************************************************
* Function name :-   schedulerInit                                                                      *          *
* function job :-    initialize scheduler by initializing all tasks                                     *                                           *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void schedulerInit(void){
	uint8 temp ;
	 scheduler_Add_Task(task1,3000);
	
	 scheduler_Add_Task(task2,4000);
	 
	 scheduler_Add_Task(task3,5000);
	timer_init(200);
	return ;
}

/* main function that handle tasks and run them according to requirements */
void Scheduler_Start (void)
{
	
	
	while(1){
		set_callback(set_callback_flag);
		if( g_flag == TRUE){
	pre_filled_arr(task_arr,g_index);
	g_flag = FALSE ;
		}
   
		}
}
/* function responible for calling tasks that inside task file */

void pre_filled_arr(TCB arr_fun[],uint32 size){
    /* - call task by their order */
	uint32 index;
	for(index = 0;index<size;index++){
	if(arr_fun[index].remaining_ticks == FALSE){
		arr_fun[index].ptr_task_fun();
		arr_fun[index].remaining_ticks = arr_fun[index].priodic_time ;
	}
	else {  } 
		arr_fun[index].remaining_ticks -- ; }
	
}

void set_callback_flag(void){
	g_flag = TRUE ;
}

/*****************************************************************************************************
* Function name :-                                                                                   *
* function job :-                                                                                    *
* function arguments :-                                                                              *
* function return :-                                                                                 *
*****************************************************************************************************/
uint8 scheduler_Add_Task(ptr_fun new_task,uint32 period)
{
	if( g_index < max_size ){
		task_arr[g_index].ptr_task_fun = new_task ;
		task_arr[g_index].priodic_time = period ;
		task_arr[g_index].remaining_ticks = period ;
		
		g_index++;
		
		return TRUE ;
	}
	return FALSE ;
}
