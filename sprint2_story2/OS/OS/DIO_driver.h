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

#define led0 12
#define led1 13
#define led2 14
#define led3 15



void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
void DIO_togglePin(uint8 PinNum);



#endif /* DIO_DRIVER_H_ */