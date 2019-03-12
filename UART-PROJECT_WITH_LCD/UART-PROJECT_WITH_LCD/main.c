/*
 * UART-PROJECT_WITH_LCD.c
 *
 * Created: 2/27/2019 1:22:08 PM
 * Author : AVE-LAP-063
 */ 

#include "UART.h"
#include "Config_UART.h"


int main(void)
{  UART_Inti();

    /* Replace with your application code */
    while (1) 
    { UART_Transmit('c');
    }
	return 0;
}

