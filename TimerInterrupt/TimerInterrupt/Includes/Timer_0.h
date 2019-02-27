/*
 * Timer0.h
 *
 * Created: 2/14/2019 9:35:21 AM
 *  Author: AVE-LAP-063
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Types.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#define TCNT0	(*(volatile ptr8)(0x52))
#define TCCR0 (*((volatile ptr8)(0x53)))
#define TIFR (*((volatile ptr8)(0x58)))
#define OCR0 (*((volatile ptr8)(0x5C)))
#define OCF0 1
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3 
#define GIE 7
#define SREG (*((volatile ptr8)(0x5F)))
#define OCIE0 1
#define TIMSK  (*((volatile ptr8)(0x59)))

extern void timer_delaay (uint8 k);
#endif /* TIMER0_H_ */