/*
 * DIO_driver.c
 *
 * Created: 2/13/2019 2:17:30 PM
 *  Author: AVE-LAP-023
 */ 
#include "Types.h"
#include "BiteWiseOperation.h"
#include <avr/io.h>




void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinNum >=0 && PinNum <=7){
		switch(PinValue){
			case 1 : Set_Bit(PORTA,PinNum);
			break;
			case 0 : Clear_Bit(PORTA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=8 && PinNum <=15){
		switch(PinValue){
			case 1 : Set_Bit(PORTB,(PinNum-8));
			break;
			case 0 : Clear_Bit(PORTB,(PinNum-8));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=16 && PinNum <=23){
		switch(PinValue){
			case 1 : Set_Bit(PORTC,(PinNum-16));
			break;
			case 0 : Clear_Bit(PORTC,(PinNum-16));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=24 && PinNum <=31){
		switch(PinValue){
			case 1 : Set_Bit(PORTD,(PinNum-24));
			break;
			case 0 : Clear_Bit(PORTD,(PinNum-24));
			break;
			default :
			break ;
		}
	}
}

uint8 DIO_ReadPin(uint8 PinNum){
	if(PinNum >=0 && PinNum <=7){
		return (Get_Bit(PINA,PinNum));
	}
	else if(PinNum >=8 && PinNum <=15){
		return (Get_Bit(PINB,(PinNum-8)));
	}
	else if(PinNum >=16 && PinNum <=23){
		return (Get_Bit(PINC,(PinNum-16)));
	}
	else if(PinNum >=24 && PinNum <=31){
		return (Get_Bit(PIND,(PinNum-24)));
	}
}

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	if(PinNum >=0 && PinNum <=7){
		switch(PinDirection){
			case 1 : Set_Bit(DDRA,PinNum);
			break;
			case 0 : Clear_Bit(DDRA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=8 && PinNum <=15){
		switch(PinDirection){
			case 1 : Set_Bit(DDRB,(PinNum-8));
			break;
			case 0 : Clear_Bit(DDRB,(PinNum-8));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=16 && PinNum <=23){
		switch(PinDirection){
			case 1 : Set_Bit(DDRC,(PinNum-16));
			break;
			case 0 : Clear_Bit(DDRC,(PinNum-16));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=24 && PinNum <=31){
		switch(PinDirection){
			case 1 : Set_Bit(DDRD,(PinNum-24));
			break;
			case 0 : Clear_Bit(DDRD,(PinNum-24));
			break;
			default :
			break ;
		}
	}
}

void DIO_togglePin(uint8 PinNum){
	
	if(PinNum >=0 && PinNum <=7){
		Togle_Bit(PORTA,PinNum);
	}
	else if(PinNum >=8 && PinNum <=15){
		Togle_Bit(PORTB,(PinNum-8));
	}
	else if(PinNum >=16 && PinNum <=23){
		Togle_Bit(PORTC,(PinNum-16));
	}
	else if(PinNum >=24 && PinNum <=31){
		Togle_Bit(PORTD,(PinNum-24));
	}
}