/*
 * UARTS.c
 *
 * Created: 2/27/2019 1:26:20 PM
 *  Author: AVE-LAP-063
 */ 
#include "UART.h"
#include "Config_UART.h"
UART_Config_S Mine;
void UART_Inti()
{
	

	UBRRL = Mine.BaudRate;
	Mine.DataSize = DATASIZE;
	Mine.No_StopBits = NO_STOPBITS ;
	Mine.SpeedMode = SPEEDMODE;
	Mine.ParityMode = PARITYMODE ;
	Mine.BaudRate = (FOSC/(BAUDRATE)/16)-1;
	UBRRH = (Mine.BaudRate&0xf0)>>8;
	UBRRL =Mine.BaudRate;
	if (Mine.No_StopBits==ONE){
	Set_Bit(UCSRC,URSEL);

	Clear_Bit(UCSRC,USBS);
	}
	else
	{
	Set_Bit(UCSRC,URSEL);	
	Set_Bit(UCSRC,USBS);
	}
	switch(Mine.ParityMode)
	{
		case 0 :
		
		Set_Bit(UCSRC,URSEL);
		/*Clear_Bit(UCSRC,UPM0);
		Clear_Bit(UCSRC,UPM1);*/
		break;
		case 1 :
		Set_Bit(UCSRC,URSEL);
		Clear_Bit(UCSRC,UPM0);
		Set_Bit(UCSRC,UPM1);
		break;
		case 2 :
		Set_Bit(UCSRC,URSEL);

		Clear_Bit(UCSRC,UPM1);
		Set_Bit(UCSRC,UPM0);
		break;
	}
	
	/*SPEED*/

	if(Mine.SpeedMode == LOW)
	{
		Clear_Bit(UCSRA,U2X);
	}

	else
	{
		Set_Bit(UCSRA,U2X);
	}


	/*SIZE*/

	switch(Mine.DataSize)
	{
		case 5 :
		Set_Bit(UCSRC,URSEL);
		Clear_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRC,UCSZ0);
		Clear_Bit(UCSRB,UCSZ2);
break;
		case 6 :
		Set_Bit(UCSRC,URSEL);
		Clear_Bit(UCSRC,UCSZ1);
		Set_Bit(UCSRC,UCSZ0);
		Clear_Bit(UCSRB,UCSZ2);
break;
		case 7 :
		Set_Bit(UCSRC,URSEL);
		Set_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRC,UCSZ0);
		Clear_Bit(UCSRB,UCSZ2);
break;
		case 8 :
		UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	/*	Set_Bit(UCSRC,URSEL);
		Set_Bit(UCSRC,UCSZ1);
		Set_Bit(UCSRC,UCSZ0);*/
break;

		case 9 :
		Set_Bit(UCSRC,URSEL);
		Set_Bit(UCSRC,UCSZ1);
		Set_Bit(UCSRC,UCSZ0);
		Set_Bit(UCSRB,UCSZ2);
break;
		default :
		Set_Bit(UCSRC,URSEL);
		Set_Bit(UCSRC,UCSZ1);
		Set_Bit(UCSRC,UCSZ0);
		Clear_Bit(UCSRB,UCSZ2);
break;
	}

		
	UCSRB |= (1<<RXEN) | (1<<TXEN);

}

void UART_Transmit(uint8 Data)
{ 		

	  while(!Get_Bit(UCSRA,UDRE));

	UDR = Data;
}

uint8 UART_Reseive()
{
	
	return UDR;
}


