/*
 * DIO_Prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */
#include <avr/io.h>

#include"../../LIB/BIT_Math.h"
#include"../../LIB/STD_Type.h"

#include"DIO_Interface.h"


void DIO_VoidSetPinDirection(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_PinState){
	//Better Array to Be {&DDRA,&DDRB,&DDRC,&DDRD}
	//u8* arr={&DDRA,&DDRB,&DDRC,&DDRD};
	//arr[Copy_u8PortName]
	switch(Copy_u8PortName){
	case DIO_PORTA:
		switch(Copy_PinState){
		case OUTPUT:
			Set_Bit(DDRA,Copy_u8PinNumber);
			break;
		case INPUT:
			CLR_Bit(DDRA,Copy_u8PinNumber);
			break;
		}
		break;
	case DIO_PORTB:
		switch(Copy_PinState){
			case OUTPUT:
				Set_Bit(DDRB,Copy_u8PinNumber);
				break;
			case INPUT:
				CLR_Bit(DDRB,Copy_u8PinNumber);
				break;}
		break;
	case DIO_PORTC:
		switch(Copy_PinState){
			case OUTPUT:
				Set_Bit(DDRC,Copy_u8PinNumber);
				break;
			case INPUT:
				CLR_Bit(DDRC,Copy_u8PinNumber);
				break;}
		break;
	case DIO_PORTD:
		switch(Copy_PinState){
			case OUTPUT:
				Set_Bit(DDRD,Copy_u8PinNumber);
				break;
			case INPUT:
				CLR_Bit(DDRD,Copy_u8PinNumber);
				break;}
		break;

	}
}

void DIO_VoidSetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_PinValue){
	switch(Copy_u8PortName){
	case DIO_PORTA:
		switch(Copy_PinValue){
		case HIGH:
			Set_Bit(PORTA,Copy_u8PinNumber);
			break;
		case LOW:
			CLR_Bit(PORTA,Copy_u8PinNumber);
			break;
		}
		break;
	case DIO_PORTB:
		switch(Copy_PinValue){
			case HIGH:
				Set_Bit(PORTB,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_Bit(PORTB,Copy_u8PinNumber);
				break;}
		break;
	case DIO_PORTC:
		switch(Copy_PinValue){
			case HIGH:
				Set_Bit(PORTC,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_Bit(PORTC,Copy_u8PinNumber);
				break;}
		break;
	case DIO_PORTD:
		switch(Copy_PinValue){
			case HIGH:
				Set_Bit(PORTD,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_Bit(PORTD,Copy_u8PinNumber);
				break;}
		break;

	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber){
	u8 Local_u8PinValue;
	switch(Copy_u8PortName){
	case DIO_PORTA:
		Local_u8PinValue = Get_Bit(PINA,Copy_u8PinNumber);
		break;
	case DIO_PORTB:
		Local_u8PinValue = Get_Bit(PINB,Copy_u8PinNumber);
		break;
	case DIO_PORTC:
		Local_u8PinValue = Get_Bit(PINC,Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		Local_u8PinValue = Get_Bit(PIND,Copy_u8PinNumber);
			break;
	}


	return Local_u8PinValue;
}


void DIO_VoidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection){
	u8* SelPort = 0x00;
	switch(Copy_u8PortName){
		case DIO_PORTA:
			SelPort = &DDRA;
			break;
		case DIO_PORTB:
			SelPort = &DDRB;
			break;
		case DIO_PORTC:
			SelPort = &DDRC;
			break;
		case DIO_PORTD:
			SelPort = &DDRD;
			break;
	}
	* SelPort = Copy_u8PortDirection;
}

void DIO_VoidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue){
	u8* SelPort = 0x00;
		switch(Copy_u8PortName){
			case DIO_PORTA:
				SelPort = &PORTA;
				break;
			case DIO_PORTB:
				SelPort = &PORTB;
				break;
			case DIO_PORTC:
				SelPort = &PORTC;
				break;
			case DIO_PORTD:
				SelPort = &PORTD;
				break;
		}
		* SelPort = Copy_u8PortValue;
}












