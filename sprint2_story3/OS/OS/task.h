/*
 * task.h
 *
 * Created: 2/23/2019 2:52:22 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef TASK_H_
#define TASK_H_

#include "DIO_driver.h"

/* struct that contains :
 * element 1: pointer to task function (void/void).
 * element 2: task periodicity (in OS_ticks unit) (Never changes at runtime)
 * element 3: runtime processing variable to detect remaining ticks before task execution at runtime
 */


extern void task1 (void);
extern void task2 (void);
extern void task3 (void);

 


#endif /* TASK_H_ */