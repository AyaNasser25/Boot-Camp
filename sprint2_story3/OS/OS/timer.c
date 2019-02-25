/*
 * CFile1.c
 *
 * Created: 2/13/2019 3:57:20 PM
 *  Author: AVE-LAP-023
 */ 

#include "timer.h"
#include "DIO_driver.h"
#include <avr/interrupt.h>

static volatile void  (*gcall_back) (void) = NULL;


void timer_init(uint8 OCR_val){
	/* FRC0 = 1 & CTC MODE IS ON & PRECSACLE 64 */
	
	TCNT0 = FALSE;
	OCR0 = OCR_val;
	TIMSK |= (1<<OCIE0);
	sei();
	TCCR0 |= (1<<FOC0) | (1<<WGM01) |(1<<CS00) | (1<<CS01);
}


void set_callback(p_fun fun)
{
	gcall_back = fun;
	
}
/* interrupt code */
 ISR (TIMER0_COMP_vect)
 {
	  /* increase global flag that tells all files about timing */
	 NewTickFlag ++;
	 if(gcall_back != NULL){
	 gcall_back();
	
	 }
	
 }