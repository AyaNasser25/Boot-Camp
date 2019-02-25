/*
 * TTC.c
 *
 * Created: 2/23/2019 2:18:23 PM
 *  Author: AVE-LAP-023
 */ 
#include "TTC.h"

static void set_callback_flag(void);
static void sort_arr(TCB arr[],uint8 size);

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
	 scheduler_Add_Task(task1,2000,30);
	
	 scheduler_Add_Task(task2,2000,1);
	 
	 scheduler_Add_Task(task3,4000,2);
	 
	 sort_arr(task_arr,g_index);
	 
	timer_init(200);
	return ;
}

/* main function that handle tasks and run them according to requirements */
void Scheduler_Start (void)
{
	
	
	while(1){
		set_callback(set_callback_flag);
		if( g_flag == TRUE){
			g_flag = FALSE ;
	pre_filled_arr(task_arr,g_index);
	
		}
   
		}
}
/* function responible for calling tasks that inside task file */

void pre_filled_arr(TCB arr_fun[],uint32 size){
    /* - call task by their order */
	uint32 index,perior;
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
uint8 scheduler_Add_Task(ptr_fun new_task,uint32 period,uint8 periority)
{
	if( g_index < max_size ){
		task_arr[g_index].ptr_task_fun = new_task ;
		task_arr[g_index].priodic_time = period ;
		task_arr[g_index].remaining_ticks = period ;
		task_arr[g_index].task_periority = periority ;
		g_index++;
		
		return TRUE ;
	}
	return FALSE ;
}
/********************************************************************************************************
* Function name :-   sort arr                                                                           *
* function job :-   sorting array of struct by periority                                                *
* function arguments :-      array of struct & its size                                                 *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void sort_arr(TCB arr[],uint8 size)
{
	uint8 i,j;
	TCB temp;
	for(i=0;i<size;i++){
		for(j = i+1; j<size;j++){
			if(arr[j].task_periority <arr[i].task_periority){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp ;
			}
		}
	}
	
}