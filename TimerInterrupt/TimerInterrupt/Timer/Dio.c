/*
 * DIO.c
 *
 * Created: 2/13/2019 3:03:00 PM
 *  Author: AVE-LAP-063
 */ 
#include "Dio.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	
	if (PinNum>=8&&PinNum<16){
		
		if (PinValue){
			Set_Bit(PORTB,(PinNum-8));
			
		}
		else {
			
			Clear_Bit(PORTB,(PinNum-8));
		}
	}
	if (PinNum>=0&&PinNum<9){
		
		if (PinValue){
			Set_Bit(PORTA,PinNum);
			
		}
		else {
			
			Clear_Bit(PORTA,PinNum);
		}
	}
	 
	 if (PinNum>=16&&PinNum<24){
		
		if (PinValue){
			Set_Bit(PORTC,(PinNum-16));
			
		}
		else {
			
			Clear_Bit(PORTC,(PinNum-16));
			}
	}
		 if (PinNum>=24&&PinNum<32){
			
			if (PinValue==1){
				Set_Bit(PORTD,(PinNum-24));
				
				}
			else {
				
				Clear_Bit(PORTD,(PinNum-24));
				}	
			}
		
	}
	

	

 uint8 DIO_ReadPin(uint8 PinNum)
 
 {
	if (PinNum>=0&&PinNum<8)
	{
		return (Get_Bit(PINA,PinNum));
		
	} 
	if ((PinNum>=8)&&((PinNum)<16))
	{
		return( Get_Bit(PINB,(PinNum-8)));
		
	} 
 
 
 
	if (PinNum>=16&&PinNum<24)
	{
		return (Get_Bit(PINC,(PinNum-16)));
		
	} 
	if (PinNum>=24&&PinNum<32)
	{
		return (Get_Bit(PIND,(PinNum-24)));
		
	} 
 
 return (-1);
 }
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	
	if (PinNum>=8&&PinNum<16){
		
		if (PinDirection){
			Set_Bit(DDRB,(PinNum-8));
			
		}
		else {
			
			Clear_Bit(DDRB,(PinNum-8));
		}
	}
	if (PinNum>=0&&PinNum<9){
		
		if (PinDirection){
			Set_Bit(DDRA,PinNum);
			
		}
		else {
			
			Clear_Bit(DDRA,PinNum);
		}
	}
	
	if (PinNum>=16&&PinNum<24){
		
		if (PinDirection){
			Set_Bit(DDRC,(PinNum-16));
			
		}
		else {
			
			Clear_Bit(DDRC,(PinNum-16));
		}
	}
	if (PinNum>=24&&PinNum<32){
		
		if (PinDirection==1){
			Set_Bit(DDRD,(PinNum-24));
			
		}
		else {
			
			Clear_Bit(DDRD,(PinNum-24));
		}
	}
	
}

