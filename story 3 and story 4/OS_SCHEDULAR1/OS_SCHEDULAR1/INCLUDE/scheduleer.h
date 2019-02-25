/*
 * scheduleer.h
 *
 * Created: 2/23/2019 5:23:19 PM
 *  Author: AVE-LAP-063
 */ 

#ifndef SCHEDULEER_H_
#define SCHEDULEER_H_
#include "Dio_Registers.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Types.h"
#include "tasks.h"

void Scheduler_init_start ();
void TTC_SCHEDULAR ();
extern void timer0_init();
void SetCallBack ();
void  (*arr_empty[max_size])(void);
extern void (*array_function[3])(void);
void flagtimer(void);
uint8 scheduler_Add_Task(void (*ptr)(void));
struct My_struct
{
	void (*Ptr2func)(void);
	uint16 Task_Periodicty ;
	uint16 Remaining_Ticks;
	uint8 priority;
};
void Structure_Schedular();
uint8 add_func(void (*ptrf)(void),uint16 PERIOD,uint8 prio);
void Remaining(void);
void schedulerStart(void);
void arrange_tasks ();
void scheduler_Remove_Task(void (*ptrf)(void));
#endif /* SCHEDULEER_H_ */