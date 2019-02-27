/*
 * Timer0.c
 *
 * Created: 2/14/2019 9:34:56 AM
 *  Author: AVE-LAP-063
 */ 
#include "Timer_0.h"

/*
void timer_delaay (uint8 k)
{
	uint8 i=0;
	TCNT0=0;
	OCR0=124;
	TCCR0|=(1<<WGM01)|(1<<CS00)|(1<<CS01);
	while (k)
	{ 
		
		while ((TIFR&(1<<OCF0))==0);
		TCCR0=0;
		k--;
		TIFR|=(1<<OCF0);
		TCCR0=(1<<WGM01)|(1<<CS00)|(1<<CS01);

	}
}*/
TCNT0=0;
