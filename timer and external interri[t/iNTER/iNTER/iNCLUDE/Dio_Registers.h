/*
 * Dio_Registers.h
 *
 * Created: 2/13/2019 2:48:11 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_
#include "Types.h"
#define  PORTA (*(volatile ptr8)(0x3B))
#define DDRA  (*(volatile ptr8 )(0x3A))
#define  PINA (*(volatile ptr8)(0x19))
#define  PORTB (*(volatile ptr8)(0x38))
#define DDRB  (*(volatile ptr8 )(0x37))
#define  PINB (*(volatile ptr8)(0x36))
#define  PORTC (*(volatile ptr8)(0x35))
#define DDRC  (*(volatile ptr8 )(0x34))
#define  PINC (*(volatile ptr8)(0x33))
#define  PORTD (*(volatile ptr8)(0x32))
#define DDRD  (*(volatile ptr8 )(0x31))
#define  PIND (*(volatile ptr8)(0x30))


#endif /* DIO_REGISTERS_H_ */