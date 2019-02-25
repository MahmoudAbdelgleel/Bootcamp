/*
 * TIMERI.h
 *
 * Created: 2/24/2019 9:58:11 AM
 *  Author: AVE-LAP-063
 */ 


#ifndef TIMERI_H_
#define TIMERI_H_
#include "Dio_Registers.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Types.h"
#include "tasks.h"
#include <avr/interrupt.h>
#define REQ
#ifndef REQ
#define TCNT0 (*((volatile ptr8)0x52))
#define TCCR0 (*((volatile ptr8)0x53))
#define TIFR  (*((volatile ptr8)0x58))
#define OCR0  (*((volatile ptr8)0x5C))
#define TIMSK (*((volatile ptr8)0x59))
#define SREG  (*((volatile ptr8)0x5F))
#define GICR  (*((volatile ptr8)0x5B))
#endif
#define OCIE0 1
#define GlOBAL_INTERRUPT_BIT  7
#define OCF0  1
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define GIE 7
void timer0_init();
extern volatile void  (*callback )(void);
extern volatile  uint8 flag;
#define  OCR_VALUE 124
extern void  Set_CallBack(void (*call)(void));


#endif /* TIMERI_H_ */