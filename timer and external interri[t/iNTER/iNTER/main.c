/*
 * iNTER.c
 *
 * Created: 2/20/2019 7:23:57 PM
 * Author : AVE-LAP-063
 */ 
/*
#include "avr/interrupt.h"
*/
#include <util/delay.h>
#include "Timer1.h"
#include "motor_config.h"

volatile uint8 flag=ZERO;
int main(void)
{
	
timer1_init();	
 _delay_ms(10);
/* FIRST ARGUMENT IS THE DUTY 
SECOND ARGUMENT IS THE TOP VALUE
THIRD  ARGUMENT IS THE MODE VALUE
1 FOR FAST 
2 FOR PHASE CORRECT 


*/
  _delay_ms(10000000);
 
}

