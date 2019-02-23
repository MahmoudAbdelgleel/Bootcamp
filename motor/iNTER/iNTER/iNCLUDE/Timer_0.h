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
#include "magic_num.h"
#include "Interrupt config.h "
#define TCNT0 (*((volatile ptr8)(0x52)))
#define TCCR0 (*((volatile ptr8)(0x53)))
#define TIFR (*((volatile ptr8)(0x58)))
#define OCR0 (*((volatile ptr8)(0x5C)))
#define GICR (*((volatile ptr8)(0x5B)))
#define OCF0 1
#define CS00 0
#define CS01 1
#define CS02 2
#define MCUCSR (*((volatile ptr8)(0x54)))
#define  ISC2 6
#define WGM01 3 
#define INT2 5
extern void timer_delaay (uint8 k);
#define GIE 7
#define SREG (*((volatile ptr8)(0x5F)))
#define OCIE0 1
#define TIMSK  (*((volatile ptr8)(0x59)))

void timer_init ();
#endif /* TIMER0_H_ */