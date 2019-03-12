/*
 * Config_UART.h
 *
 * Created: 2/27/2019 4:00:36 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef CONFIG_UART_H_
#define CONFIG_UART_H_
#include "Types.h"
#define  FOSC 16000000
#define BAUDRATE    9600
#define NO_STOPBITS 1
#define PARITYMODE  0
#define DATASIZE    8
#define SPEEDMODE   0
#define  UCSRA (*(volatile ptr8)(0x2B))
#define  UCSRB (*(volatile ptr8)(0x2A))
#define  UCSRC (*(volatile ptr8)(0x40))
#define  UBRRH (*(volatile ptr8)(0x40))
#define  UBRRL (*(volatile ptr8)(0x29))
#define  UDR (*(volatile ptr8)(0x2C))
#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define U2X 1
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define  RXB8 1
#define  TXB8 0
#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCSZ2 2
#endif /* CONFIG_UART_H_ */