/*
 * TTC.c
 *
 * Created: 2/23/2019 2:18:23 PM
 *  Author: AVE-LAP-023
 */ 
#include "TTC.h"

static void set_callback_flag(void); /*prototype of function that set flag which indicate time tick*/

static void sort_arr(TCB arr[],uint8 size); /*prototype of function that sort array of sturcture according to periority
*/

  TCB task_arr[max_size]; /* array of struct of os tasks */
 uint32 g_index ;     /* global valuable that indicate no. of tasks that initialized in scheduler*/ 
volatile uint8 g_flag; /* flag to indicate that timer has reached to the desired time (call back isr function)*/
/********************************************************************************************************
* Function name :-   schedulerInit                                                                      *          
* function job :-    initialize scheduler by initializing all tasks                                     *                                           *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void schedulerInit(void){
	
	 scheduler_Add_Task(task1,sec_2,periority_2);
	
	 scheduler_Add_Task(task2,sec_2,periority_0);
	 
	 scheduler_Add_Task(task3,sec_4,periority_1);
	 
	 sort_arr(task_arr,g_index);
	 
	timer_init(OCR_1ms);
	return ;
}

/********************************************************************************************************
* Function name :-   scheduler_start                                                                    *
* function job :-    initialize scheduler and run all task according to their order  it contain super loop                                   *                                           *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/

void Scheduler_Start (void)
{
	/* contains super loop that runs all timer and handle all event */
	
	while(TRUE){
		/* calling that function to get timer tick */
		set_callback(set_callback_flag);
		/* if flag is true it indicate that timer count 1 ms then call tasks */
		if( g_flag == TRUE){
			/* change flag value to zero again to know next tick */
			g_flag = FALSE ;
			/* detect if switch is pressed */
			if(DIO_ReadPin(but1)){
				/* if switch is pressed then remove desired task */
				while(DIO_ReadPin(but1));
				scheduler_Remove_Task(task1);
				g_index -- ;
				
			}
			/* if switch not pressed continue normal operation */
			else { }
				/* call function that call all tasks with spesific time */
	pre_filled_arr(task_arr,g_index);
	
		}
   
		}
}
/********************************************************************************************************
* Function name :- pre_filled_arr                                                                       *
* function job :-  function that responsible for calling tasks with specified time                      *                                           *
* function arguments :-    array of struct and its size                                                 *
* function return :-            N/A                                                                     *
********************************************************************************************************/
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
* Function name :-  scheduler_Add_Task                                                               *              
* function job :-    its responsible for adding task to OS. it fills array of struct with new tasks  *
* function arguments :- pointer to function(task) , time of periodicity , task periority             *
* function return :-   true if task added successfully and false if it exceed max siz                *
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
/********************************************************************************************************
* Function name :-     scheduler_Remove_Task                                                                        *
* function job :-   remove task during run time according to specific event                             *
* function arguments :-     pointer to function                                                         *
* function return :-            N/A                                                                     *
********************************************************************************************************/

void scheduler_Remove_Task(ptr_fun task_remove)
{
	uint32 count_task,j;
	for(count_task= FALSE;count_task<max_size;count_task++){
		if(task_arr[count_task].ptr_task_fun == task_remove){
			break ;
		}
	}
	for(j=count_task;j<max_size;j++){
		task_arr[j]=task_arr[j+1];
		
	}
}