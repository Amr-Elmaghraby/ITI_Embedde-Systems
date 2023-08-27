/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"
#include"../MCAL/Driver_DIO_V1/DIO_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include"../HAL/Servo/Servo_Interface.h"

void main(void){
	LCD_VoidInit();
	KPD_VoidInit(KPD_COL_PORTA,KPD_ROW_PORTA);
	Servo_VoidInit();
	DIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN5,OUTPUT);
	u8 pressed = 255;
	u8 Deg=0;
	LCD_voidSendString("Deg:  ");
	while(1){
		pressed = KPD_u8GetPressedKey();
		if(pressed!=255){
			if(pressed=='&'){
				LCD_VoidClearDisplay();
				LCD_voidSendString("Deg:  ");
				Servo_VoidReset();
				Deg=0;
					}
			else if(pressed=='='){
				LCD_GoTOXY(1,0);
				LCD_voidSendString("Ticks: ");
				Servo_VoidDegree(Deg);
				LCD_voidSendNumber(Servo_u16GetTicks());
			}
			else if(pressed=='/' || pressed=='*' || pressed=='-'|| pressed=='+'){
				LCD_VoidClearDisplay();
				LCD_voidSendString("Incorrect Input");
				}
			else{
				Deg = pressed + Deg*10;
				LCD_VoidSendData(pressed+'0');
			}
		}
	}
}




