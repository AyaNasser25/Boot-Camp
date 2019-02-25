/*
 * task.c
 *
 * Created: 2/23/2019 2:49:40 PM
 *  Author: AVE-LAP-023
 */ 
#include "task.h"

 

		
	

/* task one runs periodically every 3 sec it toggle led0 every 3 sec */	
void task1 (void){
	DIO_togglePin(led0);
	
}
/* task one runs periodically every 4 sec it toggle led1 every 4 sec */	
void task2 (void){
	
	
	DIO_togglePin(led1);
	
	
}
/* task that toggle led 2 every 5 sec */
void task3 (void){
	DIO_togglePin(led2);
	
	}
	

 