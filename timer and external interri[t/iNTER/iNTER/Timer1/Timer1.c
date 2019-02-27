/*
 * Timer1.c
 *
 * Created: 2/21/2019 12:13:42 PM
 *  Author: AVE-LAP-063
 */ 
#include "Timer1.h "
#include "motor_config.h"
	/****************************************************************************

Function Name		 : timer1_init

Function Description : Function responsible for  initializing the registers 

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void timer1_init(){
	TCNT1H=ZERO;
	TCNT1L=ZERO;
	DIO_SetPinDirection(OC1B,OUTPUT);
	DIO_SetPinDirection(OC1A,OUTPUT);
	DIO_SetPinDirection(MOTOR1_R,OUTPUT);
	DIO_SetPinDirection(MOTOR1_L,OUTPUT);
	DIO_SetPinDirection(MOTOR2_R,OUTPUT);
	DIO_SetPinDirection(MOTOR2_L,OUTPUT);
	DIO_WritePin(MOTOR1_R,HIGH);
		DIO_WritePin(MOTOR1_L,LOW);
	Set_Bit(TCCR1A,COM1A0);/*inverting*/
	Set_Bit(TCCR1A,COM1A1); /*inverting*/
	Set_Bit(TCCR1B,CS11); /*  NO prescaler  */
	Set_Bit(TCCR1A,COM1B0);/*inverting*/
	Set_Bit(TCCR1A,COM1B1); /*inverting*/
}

void Right (){
DIO_WritePin(MOTOR2_R,HIGH);
DIO_WritePin(MOTOR2_L,LOW);
ICR1H =(COMPARE_VALUE>>one_byte);
			ICR1L=COMPARE_VALUE;
	OCR1BH=(COMPARE_VALUE>>one_byte);
	OCR1BL=COMPARE_VALUE;	
}
void left (){
	DIO_WritePin(MOTOR2_R,ZERO);
	DIO_WritePin(MOTOR2_L,ONE);
	ICR1H =(COMPARE_VALUE>>one_byte);
	ICR1L=COMPARE_VALUE;
	OCR1BH=(COMPARE_VALUE>>one_byte);
	OCR1BL=COMPARE_VALUE;
}
void s_1 ()
{	DIO_WritePin(MOTOR2_R,ZERO);
	DIO_WritePin(MOTOR2_L,ZERO);
	ICR1H =(COMPARE_VALUE>>one_byte);
	ICR1L=COMPARE_VALUE;
	OCR1BH=ZERO;
	OCR1BL=ZERO;
	
	}
	/****************************************************************************

Function Name		 : Mode select

Function Description : Function responsible for selecting mode whether Fast or phase correct ,duty cycle 

Function Parameters  : 
					  duty ,top and mode

Function Return      : N/A

*******************************************************************************/
	void MODE_SELECT (float duty,uint16 top,uint8 mode)
	{ uint16 COMPARE_VALUE2=ZERO;
		if (mode==ONE){
			DIO_WritePin(MOTOR2_R,0);
			DIO_WritePin(MOTOR2_L,1);
			Set_Bit(TCCR1A,WGM11); /* mode 14 */
			Set_Bit(TCCR1B,WGM12); /* mode 14 */
			Set_Bit(TCCR1B,WGM13); /* mode 14 */
			ICR1H =(top>>one_byte);
			ICR1L=top;
			COMPARE_VALUE2=(top-(uint16)((duty/100)*(top+1)));
			OCR1BH=(COMPARE_VALUE2>>one_byte);
			OCR1BL=COMPARE_VALUE2;
           OCR1AH=(COMPARE_VALUE2>>one_byte);
           OCR1AL=COMPARE_VALUE2;
		}
	
	if (mode==TWO){
		DIO_WritePin(MOTOR2_R,LOW);
		DIO_WritePin(MOTOR2_L,HIGH);
		Set_Bit(TCCR1A,WGM11); /* mode 14 */
		Clear_Bit(TCCR1B,WGM12); /* mode 14 */
		Set_Bit(TCCR1B,WGM13); /* mode 14 */
		ICR1H =(top>>one_byte);
		ICR1L=top;
		COMPARE_VALUE2=(top-(uint16)((duty/100)*(top+1)));
		OCR1BH=(COMPARE_VALUE2>>one_byte);
		OCR1BL=COMPARE_VALUE2;
		OCR1AH=(COMPARE_VALUE2>>one_byte);
		OCR1AL=COMPARE_VALUE2;
	}
	}
	
	