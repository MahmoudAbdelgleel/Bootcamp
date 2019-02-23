/*
 * Dio.h
 *
 * Created: 2/13/2019 3:04:15 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "Dio_Registers.h"
#include "BitwiseOperation.h"
extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
extern uint8 DIO_ReadPin(uint8 PinNum);
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif /* DIO_H_ */