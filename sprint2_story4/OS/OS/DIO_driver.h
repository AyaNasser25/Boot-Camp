/*
 * DIO_driver.h
 *
 * Created: 2/13/2019 2:15:49 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#include "Types.h"
#include "BiteWiseOperation.h"
#include <avr/io.h>

#define led0 12
#define led1 13
#define led2 14
#define led3 15
#define but1  10

#define PORTA_START 0
#define PORTA_END 7
#define PORTB_START 8
#define PORTB_END 15
#define PORTC_START 16
#define PORTC_END 24
#define PORTD_START 25
#define PORTD_END 31




/********************************************************************************************************
* Function name :- DIO_WritePin                                                                         *
* function job :- write value in port if micro controller                                               *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
********************************************************************************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
/********************************************************************************************************
* Function name :- DIO_ReadPin                                                                          *
* function job :- Read value from pin of micro controller                                               *
* function arguments :- pin number                                                                      *
* function return :-            N/A                                                                     *
********************************************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum);
/********************************************************************************************************
* Function name :- DIO_SetPinDirection                                                                  *
* function job :- determine direction of specified pin                                                  *
* function arguments :- pin number and desired direction (I/O)                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
/********************************************************************************************************
* Function name :- DIO_togglePin                                                                        *
* function job :- toggle desired pin                                                                    *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_togglePin(uint8 PinNum);



#endif /* DIO_DRIVER_H_ */