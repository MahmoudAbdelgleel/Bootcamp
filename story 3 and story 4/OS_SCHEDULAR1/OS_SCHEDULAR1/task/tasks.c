/*
 * Task.c
 *
 * Created: 2/23/2019 2:43:15 PM
 *  Author: AVE-LAP-063
 */ 
#include "../INCLUDE/tasks.h "
#include "../INCLUDE/Dio.h "

void LED_ONE()
{	
DIO_WritePin(LEd1,HIGH);
DIO_WritePin(LEd2,LOW);
DIO_WritePin(LEd3,LOW);


}
void LED_TWO()
{

	DIO_WritePin(LEd2,HIGH);
	DIO_WritePin(LEd3,LOW);
	DIO_WritePin(LEd1,LOW);
}
void LED_THREE()
{
	DIO_WritePin(LEd3,HIGH);
	DIO_WritePin(LEd2,LOW);
	DIO_WritePin(LEd1,LOW);
}

void BUTTON_CHECK()
{
	if (DIO_ReadPin(10))
	{
	 scheduler_Remove_Task(LED_THREE);
	}
}
void (*array_function[3])(void)={LED_ONE,LED_TWO,LED_THREE};
void (*arr_empty[max_size])(void);