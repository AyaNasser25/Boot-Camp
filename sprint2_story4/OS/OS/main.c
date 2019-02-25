/*
 * OS.c
 *
 * Created: 2/23/2019 2:17:55 PM
 * Author : AVE-LAP-023
 */ 

#include <avr/io.h>
#include "TTC.h"
#include "Types.h"

int main(void)
{
	/*  identifying all led direction as outputs
	* call scheduler initialization and start it
	*/
    DIO_SetPinDirection(led0,1);
	DIO_SetPinDirection(led1,1);
	DIO_SetPinDirection(led2,1);
	DIO_SetPinDirection(but1,LOW);
	schedulerInit();
    Scheduler_Start();
}

