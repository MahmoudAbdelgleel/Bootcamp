/*
 * motor_config.h
 *
 * Created: 2/23/2019 10:48:13 AM
 *  Author: AVE-LAP-063
 */ 


#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_
#include "Types.h"
#include "Dio.h"
#include "BitwiseOperation.h"
#include "magic_num.h"
#include "Interrupt config.h "
#define  ICR1H  (*((volatile ptr8)(0x47)))
#define  ICR1L  (*((volatile ptr8)(0x46)))
#define TCCR1A (*((volatile ptr8)(0x4F)))
#define TCCR1B (*((volatile ptr8)(0x4E)))
#define TCNT1H (*((volatile ptr8)(0x4D)))
#define TCNT1L (*((volatile ptr8)(0x4C)))
#define OCR1AH (*((volatile ptr8)(0x4B)))
#define OCR1AL (*((volatile ptr8)(0x4A)))
#define TIMSK1  (*((volatile ptr8)(0x59)))
#define SREG1 (*((volatile ptr8)(0x5F)))
#define OCR1BH (*((volatile ptr8)(0x49)))
#define OCR1BL (*((volatile ptr8)(0x48)))
#define WGM10 0
#define WGM11 1
#define CS10 0
#define CS11 1
#define CS12 3
#define CS13 4
#define WGM12 3
#define WGM13 4
#define  COM1A1 7
#define COM1A0 6
#define COM1B0 4
#define COM1B1 5
#define OCIE1A 4
#define OCIE1B 3
#define OCIE1A 4
#define OC1B 28
#define OC1A 29
#define TOP_VALUE 5000
#define COMPARE_VALUE 0
#define COMPARE_VALUE1 2000
#define MOTOR1_R  26
#define MOTOR1_L 27
#define MOTOR2_R 30
#define MOTOR2_L 31
#define one_byte 8


#endif /* MOTOR_CONFIG_H_ */