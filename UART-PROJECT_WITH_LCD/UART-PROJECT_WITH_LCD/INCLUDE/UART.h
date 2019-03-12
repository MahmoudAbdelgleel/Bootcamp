/*
 * UARTS.h
 *
 * Created: 2/27/2019 1:23:11 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef UARTS_H_
#define UARTS_H_
#include "Types.h"
#include "magic_num.h"
#include "Dio_Registers.h"
#include "Dio.h"
#include "BitwiseOperation.h"

typedef struct  {
	uint16 BaudRate ;
	uint8 No_StopBits ;
	uint8 ParityMode ;
	uint8 DataSize ;
	uint8 SpeedMode ;
}UART_Config_S ;


void UART_Inti(void);
void UART_Transmit(uint8 Data);
uint8 UART_Reseive(void);
void UART_TransmitString(uint8* String ,uint8 Size);
#endif /* UARTS_H_ */