/*
 * tasks.h
 *
 * Created: 2/23/2019 5:23:04 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef TASKS_H_
#define TASKS_H_
#include "Dio_Registers.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Types.h"

#define LED_PORT PORTB
#define LEd1 12
#define LEd2 13
#define LEd3 14
extern void LED_ONE();
extern void LED_TWO();
extern void LED_THREE();
void BUTTON_CHECK();
#define  FIRST_PERIOD 1000
#define  SECOND_PERIOD 1400
#define  THIRD_PERIOD 1900
extern void (*array_function[3])(void);
extern void (*arr_empty[max_size])(void);
extern void scheduler_Remove_Task(void (*ptrf)(void));
extern volatile  uint16  q;
#endif /* TASKS_H_ */