/*
 * Timer1.h
 *
 * Created: 2/21/2019 12:13:27 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define TCCR1A (*((volatile ptr8)(0x4F)))
#define TCCR1B (*((volatile ptr8)(0x4E)))
#define TCNT1H (*((volatile ptr8)(0x4D)))
#define TCNT1L (*((volatile ptr8)(0x4C)))
#define OCR1AH (*((volatile ptr8)(0x4B)))
#define OCR1AL (*((volatile ptr8)(0x4A)))
#define TIMSK1  (*((volatile ptr8)(0x59)))
#define SREG1 (*((volatile ptr8)(0x3F)))







#endif /* TIMER1_H_ */