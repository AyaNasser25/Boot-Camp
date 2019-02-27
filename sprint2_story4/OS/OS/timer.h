/*
 * timer.h
 *
 * Created: 2/13/2019 5:51:10 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Types.h"
#include "BiteWiseOperation.h"
#include <avr/io.h>

#include <stdlib.h>

#define sec_3 3000
#define sec_2 2000
#define sec_4 4000
#define OCR_1ms 200


typedef void (*ptr_fun) (void);

void timer_init(uint8 OCR_val);
void timer_delay(uint32 n);
void set_callback(ptr_fun fun);


#endif /* TIMER_H_ */