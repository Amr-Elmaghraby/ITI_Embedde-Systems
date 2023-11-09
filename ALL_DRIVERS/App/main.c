/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */

#include<avr/io.h>

#include"../LIB/STD_Type.h"
#include"../HAL/LCD/LCD_Interface.h"

#include"../RTOS_Stack/RTOS/RTOS_Interface.h"

void LED1_Task(void);
void LED2_Task(void);
void LED3_Task(void);
void LCD_Task(void);

void main(void){
	LCD_VoidInit();
	DDRA = 0b00000111;
	RTOS_voidCreateTask(0,1000,&LED1_Task,5000);
	RTOS_voidCreateTask(1,2000,LED2_Task,0);
	RTOS_voidCreateTask(2,3000,LED3_Task,3);
	RTOS_voidCreateTask(3,500,LCD_Task,0);

	RTOS_voidStart();
	while(1);
}

void LED1_Task(void){
	//Toggle Led 1 PA0
	PORTA ^= (1<<0);
}
void LED2_Task(void){
	//Toggle Led 2 PA1
	PORTA ^= (1<<1);
}
void LED3_Task(void){
	//Toggle led 3	PA2
	PORTA ^= (1<<2);
}
void LCD_Task(void){
	LCD_VoidClearDisplay();
	static u8 x=0,y=0;
	LCD_GoTOXY(x,y);
	LCD_voidSendString("Amr Elmaghraby");
	y = (y+1)%16;

}

