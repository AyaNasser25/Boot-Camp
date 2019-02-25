/*
 * BiteWiseOperation.h
 *
 * Created: 2/13/2019 11:17:00 AM
 *  Author: AVE-LAP-023
 */ 


#ifndef BITEWISEOPERATION_H_
#define BITEWISEOPERATION_H_

#define  Set_Bit(Register,Bit) (Register |= (1<<Bit))
#define  Clear_Bit(Register,Bit) (Register &= (~(1<<Bit)))
#define  Togle_Bit(Register,Bit) (Register ^= (1<<Bit))
#define  Get_Bit(Register,Bit) (Register & (1<<Bit))






#endif /* BITEWISEOPERATION_H_ */