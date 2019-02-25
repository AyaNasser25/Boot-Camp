/*
 * task.c
 *
 * Created: 2/23/2019 2:49:40 PM
 *  Author: AVE-LAP-023
 */ 
#include "task.h"

 

		
	
/********************************************************************************************************
* Function name :-     task1                                                                            *
* function job :-    toggle led 0                                                                       *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/

void task1 (void){
	DIO_togglePin(led0);
	
}
/********************************************************************************************************
* Function name :-     task2                                                                            *
* function job :-    toggle led 1                                                                       *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/

void task2 (void){
	
	
	DIO_togglePin(led1);
	
	
}
/********************************************************************************************************
* Function name :-     task3                                                                            *
* function job :-    toggle led 2                                                                       *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void task3 (void){
	DIO_togglePin(led2);
	
	}
	

 