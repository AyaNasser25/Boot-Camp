/*
 * CFile1.c
 *
 * Created: 2/13/2019 3:57:20 PM
 *  Author: AVE-LAP-023
 */ 

#include "timer.h"
#include "DIO_driver.h"
#include <avr/interrupt.h>

static volatile void  (*gcall_back) (void) = NULL; // call back pointer 

/********************************************************************************************************
* Function name :-     timer_init                                                                       *
* function job :-    initialize timer module to start to count to ocr value                             *
* function arguments :-         ocr value                                                               *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void timer_init(uint8 OCR_val){
	/* FRC0 = 1 & CTC MODE IS ON & PRECSACLE 64 */
	
	TCNT0 = FALSE;
	OCR0 = OCR_val;
	TIMSK |= (1<<OCIE0);
	sei();
	TCCR0 |= (1<<FOC0) | (1<<WGM01) |(1<<CS00) | (1<<CS01);
}
/********************************************************************************************************
* Function name :-    set_callback                                                                      *
* function job :- point call back pointer to specific function                                          *
* function arguments :-         pointer to function                                                     *
* function return :-            N/A                                                                     *
*********************************************************************************************************/

void set_callback(ptr_fun fun)
{
	gcall_back = fun;
	
	
}
/********************************************************************************************************
* Function name :-   ISR                                                                                *
* function job :- call call back pointer to indicate that interrupt has occurred                        *
* function arguments :-         N/A                                                                     *
* function return :-            N/A                                                                     *
********************************************************************************************************/

 ISR (TIMER0_COMP_vect)
 {
	  /* increase global flag that tells all files about timing */
	 if(gcall_back != NULL){
	   gcall_back();
	 }
	
 }