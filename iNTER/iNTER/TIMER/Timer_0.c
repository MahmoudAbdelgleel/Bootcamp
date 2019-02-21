/*
 * Timer0.c
 *
 * Created: 2/14/2019 9:34:56 AM
 *  Author: AVE-LAP-063
 */ 
#include "Timer_0.h"
volatile static uint16 i=ZERO;
extern volatile uint8 flag;
#include "avr/interrupt.h"
/*************************timer_inti()*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: timer  init is to Initialize the configuration
of timer interrupt to Enable global interrupt and timer , configure prescaler
,enable external interrupt and determine whether working on falling or rising edge


********************************************************/
void timer_init ()
{  Timer_PORT=ZERO;
	DIO_SetPinDirection(button1,INPUT);
	TCNT0=ZERO;
	OCR0=124;
	TCCR0|=(ONE<<WGM01)|(ONE<<CS00)|(ONE<<CS01);
	TIMSK|=(ONE<<OCIE0);
	Set_Bit(GICR,INT2);
	Set_Bit(MCUCSR,ISC2);
}
   /*************************ISR(TIMER0_COMP_vect)*********************
   *Parameters :
   *           I/P:
   *           O/P:
   *           I/P:
   *Return:void
   *Description: to set flag only after 1 second 

   ********************************************************/
ISR(TIMER0_COMP_vect)
{  i++;
	if (i<One_sec){
	}
	else {	
		i=ZERO;
		flag++;
		
		}
		Set_Bit(SREG,GIE);  /*  Set global interrupt*/

}
/*************************ISR(INT2_vect)*********************
   *Parameters :
   *           I/P:
   *           O/P:
   *           I/P:
   *Return:void
   *Description: Handle external interrupt

   ********************************************************/
ISR(INT2_vect)
{  flag=FIVE;
i=ZERO;
  		Set_Bit(SREG,GIE);  /*  Set global interrupt*/
}