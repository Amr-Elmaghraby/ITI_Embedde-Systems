/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr Elmaghraby
 */

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"
#include"../MCAL/Driver_DIO_V1/DIO_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"




void main(void){
		DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN0,OUTPUT);
		DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN1,OUTPUT);

		DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN3,INPUT);
		DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN3,HIGH);

		DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN4,INPUT);
		DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN4,HIGH);

		LCD_VoidInit();
		u8 Dir=10;
		u8 Prev_Dir=10;

		while(1){
			if(DIO_u8GetPinValue(DIO_PORTB,DIO_PIN3)==LOW){
				DIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,HIGH);
				Dir=0;
			}
			else{
				DIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,LOW);
			}
			if(DIO_u8GetPinValue(DIO_PORTB,DIO_PIN4)==LOW){
				DIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,HIGH);
				if(!DIO_u8GetPinValue(DIO_PORTB,DIO_PIN3))
					Dir=2;
				else
					Dir=1;
			}
			else{
				DIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,LOW);
			}
			if(DIO_u8GetPinValue(DIO_PORTB,DIO_PIN3) && DIO_u8GetPinValue(DIO_PORTB,DIO_PIN4)){
				Dir=2;
			}

			if(Dir != Prev_Dir){
				LCD_VoidClearDisplay();
				switch(Dir){
					case 0:
						LCD_VoidSendData('R');LCD_VoidSendData('i');LCD_VoidSendData('g');LCD_VoidSendData('h');LCD_VoidSendData('t');
						break;
					case 1:
						LCD_VoidSendData('L');LCD_VoidSendData('i');LCD_VoidSendData('f');LCD_VoidSendData('t');
						break;
					case 2:
						LCD_VoidClearDisplay();
						break;
					}
			}
			Prev_Dir = Dir;
		}
}

