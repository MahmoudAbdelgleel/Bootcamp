/*
 * iNTER.c
 *
 * Created: 2/20/2019 7:23:57 PM
 * Author : AVE-LAP-063
 */ 
/*
#include "avr/interrupt.h"
*/

#include "Timer_0.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Interrupt config.h" 
volatile uint8 flag=ZERO;
int main(void)
{
	DIO_SetPinDirection(led3,OUTPUT);
	DIO_SetPinDirection(led1,OUTPUT);
	DIO_SetPinDirection(led2,OUTPUT);
	DIO_SetPinDirection(button1,INPUT);
	timer_init();
	
	/*    In case Flag=1 this means that only one second passed 
	      In case Flag=2 this means that two seconds passed                   
		  In case Flag=3 this means that three seconds passed
		  In case Flag=4 this means that external interrupt occurs

   */
	while (ONE)
{	
		if(flag==ONE) {    /*  Case 1 second passed*/
			DIO_WritePin(led1,LOW);
			DIO_WritePin(led3,HIGH);
			DIO_WritePin(led2,LOW);
		}
		
  else if (flag==TWO){
	  DIO_WritePin(led3,LOW);
	  DIO_WritePin(led1,HIGH);
	  DIO_WritePin(led2,LOW);
                       }
   
   else if (flag==THREE){
	   DIO_WritePin(15,LOW);
	   DIO_WritePin(13,LOW);
	   DIO_WritePin(14,HIGH);
						}
   
   else if (flag==FIVE)
      {
	   
   
   DIO_WritePin(led3,HIGH);
   DIO_WritePin(led1,HIGH);
   DIO_WritePin(led2,HIGH);
      }
   else { flag=ZERO;
   	Set_Bit(SREG,GIE);
        }
  
    }
}

