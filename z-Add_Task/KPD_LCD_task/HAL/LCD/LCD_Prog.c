/*
 * LCD_Prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Hardware
 */
#include<util/delay.h>
#include<stdlib.h>
#include"../../LIB/STD_Type.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/Driver_DIO/DIO_Interface.h"
#include"LCD_Interface.h"


void LCD_VoidSendData(u8 Copy_u8Data){
	DIO_VoidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);//Send Command
	DIO_VoidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW); //Write
	DIO_VoidSetPortValue(LCD_DATA_PORT,Copy_u8Data);

	DIO_VoidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void LCD_VoidSendCommand(u8 Copy_u8Command){
	DIO_VoidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);//Send Command
		DIO_VoidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW); //Write
		for(u8 i=0;i<8;i++){
			DIO_VoidSetPinValue(LCD_DATA_PORT,i,Get_Bit(Copy_u8Command,i));
		}
		DIO_VoidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(2);
		DIO_VoidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void LCD_VoidInit(void){
		DIO_VoidSetPortDirection(LCD_DATA_PORT,0x11);
		DIO_VoidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
		DIO_VoidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
		DIO_VoidSetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
		_delay_ms(40);
		LCD_VoidSendCommand(0b00111000);
		LCD_VoidSendCommand(0b00001100);
		LCD_VoidSendCommand(0b00000001);
}

void LCD_VoidClearDisplay(void){
	LCD_VoidSendCommand(0b00000001);
}

void LCD_GoTOXY(u8 Copy_u8X,u8 Copy_u8Y){
	/**
	 *  at x=0, y=0   address=0x00
	 *  at x=0, y=1   address=0x01
	 *  at x=0, y=17  address=0x17
	 *  at x=1, y=0   address=0x40
	 *  at x=1, y=3   address=0x43
	 *
	 *  at x=0  address = y position
	 *  at x=1 address = y+0x40
	 * */
	u8 Local_add=0;
	if(Copy_u8X==0){
		Local_add = Copy_u8Y;
	}
	else{
		Local_add = Copy_u8Y+0x40;
	}

	Set_Bit(Local_add,7); //lcd understand that is an address of postion
	LCD_VoidSendCommand(Local_add);


}

void LCD_voidSendString(u8* Copy_pcString)
{
	u8 Local_u8Index=0;

	while(Copy_pcString[Local_u8Index]!='\0')
	{
		LCD_VoidSendData(Copy_pcString[Local_u8Index]);
		Local_u8Index++;
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
   u8 Local_u8Str[10];
   //itoa is a function to convert number to a string
   //first par: represent number it self
   //sec par: represent buffer to store string convention
   //third par: represent number base 10==>Decimal   2==>Binary

   //OR:
   //  sprintf(str, "%d", number); // Convert integer to string
   itoa(Copy_u32Number, Local_u8Str,10);
   LCD_voidSendString(Local_u8Str);

}






