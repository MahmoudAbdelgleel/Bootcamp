/*
 * Timer1.h
 *
 * Created: 2/21/2019 12:13:27 PM
 *  Author: AVE-LAP-063
 */ 
#include "Types.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Interrupt config.h "

#ifndef TIMER1_H_
#define TIMER1_H_

void timer1_init(void);
void Right();
void left ();
void s_1 ();
void MODE_SELECT (float duty,uint16 top,uint8 mode);

#endif /* TIMER1_H_ */