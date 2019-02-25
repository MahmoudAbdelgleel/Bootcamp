/*
 * TIMERI.C
 *
 * Created: 2/24/2019 9:57:53 AM
 *  Author: AVE-LAP-063
 */ 
#include "TIMERI.h "
volatile  uint16  q=ZERO;
volatile void  (*callback )(void);

 /*************************ISR(TIMER0_COMP_vect)*********************
   *Parameters :
   *           I/P:void
   *           O/P:void
   *           I/P:void
   *Return:void
   *Description: to CALL CALL BACK FUNCTION 

   ********************************************************/
ISR(TIMER0_COMP_vect)
{
	(*callback)();	
}
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
void timer0_init(){
	Set_Bit(SREG,7); /* to set the global flag*/
	OCR0 = OCR_VALUE; /* to assign ocr value */
	Set_Bit(TIMSK,OCIE0); 
	/*choose prescale 64 and CTC mode */
	Set_Bit(TCCR0,WGM01);
	Set_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS00);
	Set_Bit(SREG,GlOBAL_INTERRUPT_BIT);
}

/********************************************Set_CallBack*********************
*Parameters :
*           I/P:POINTER TO FUNCTION 
*           O/P:void
*           I/o:void
*Return:void
*Description: TO ASSIGN THE CALLBACK FUNCTION THAT EXECUTED BY ISR

********************************************************/
void  Set_CallBack( void (*call)(void))

{
  callback = call;   /*call is sent form the os layer */
}