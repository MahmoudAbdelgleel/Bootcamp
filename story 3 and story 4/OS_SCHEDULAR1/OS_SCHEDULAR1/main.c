/*
 * OS_SCHEDULAR1.c
 *
 * Created: 2/23/2019 5:20:32 PM
 * Author : AVE-LAP-063
 */ 
#include "scheduleer.h " 
#include "tasks.h "

int main(void)
{	DIO_SetPinDirection(10,INPUT);
	DIO_SetPinDirection(12,OUTPUT);
	DIO_SetPinDirection(13,OUTPUT);
	DIO_SetPinDirection(14,OUTPUT);
	DIO_SetPinDirection(15,OUTPUT);
	
	uint8 cheeck;
	/* the user has to enter the tasks required to occur rhere is 2 options to
	use :
	scheduler_Add_Task if required to add task only
	add_func  if required to add task and the  period 
	*/
	
Scheduler_init_start ();
	 cheeck=add_func(LED_ONE,1000,2);
 	 cheeck=add_func(LED_TWO,1400,3);
	 cheeck=add_func(LED_THREE,1900,1);
	 cheeck=add_func(BUTTON_CHECK,1,4);
	if(cheeck==0){
	/* maximum number of  elements in the array */		
	}
schedulerStart ();
}

