/*
 * BitwiseOperation.h
 *
 * Created: 2/13/2019 11:40:47 AM
 *  Author: AVE-LAP-063
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_
#define Set_Bit(Register,Bit)   (Register|=(1<<Bit) )
#define Clear_Bit(Register,Bit)   (Register&=~(1<<Bit))
#define Toggle_Bit(Register,Bit)   (Register^=(1<<Bit) )
#define Get_Bit(Register,Bit)    (((Register&(1<<Bit))>>Bit)) 


#endif /* BITWISEOPERATION_H_ */