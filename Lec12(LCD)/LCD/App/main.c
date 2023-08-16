/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr Elmaghraby
 */

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"
#include"../MCAL/Driver_DIO_V1/DIO_Interface.h"
#include <util/delay.h>
#include"../HAL/LCD/LCD_Interface.h"




void main(void){
	u8 x=0;
	u8 y=0;
	LCD_VoidInit();
	while(1){
	LCD_GoTOXY(x,y);
	LCD_VoidSendData('A');
	LCD_VoidSendData('M');
	LCD_VoidSendData('R');
	_delay_ms(500);
	LCD_VoidClearDisplay();
	x=~x;
	y=(y+1)%14;
	}

}

