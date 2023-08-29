/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"
#include"../MCAL/Driver_DIO_V1/DIO_Interface.h"
#include"../MCAL/TIMER/TIMER_Interface.h"
#include"../MCAL/SPI/SPI_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/GIE/GIE_Interface.h"

void Pressed(void);
void main(void){

	//SCLK
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN7,OUTPUT);
	//MOSI
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN5,OUTPUT);
	//MISO
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN6,INPUT);
	//SS
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN4,INPUT);
	//Pull up
	DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN4,HIGH);

	//Initialize MC as Master
	SPI_MasterInit();

	//Initialize EXT Interrupt
	EXTI_VoidInit(EXT_INT0,FALLING);

	//Initialize EXTI Pin as Input
	DIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN2,INPUT);
	DIO_VoidSetPinValue(DIO_PORTD,DIO_PIN2,HIGH);
	//Initialize EXT interrupt SPI
	EXTI_VoidINT0CallBack(&Pressed);
	//GIE
	GIE_voidEnableGlobalInterrupt();

	while(1);
}
void Pressed(void){
	SPI_u8Transeive(1);
}



