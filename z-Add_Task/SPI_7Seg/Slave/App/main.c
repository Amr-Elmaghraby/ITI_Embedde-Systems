/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"
#include"../MCAL/Driver_DIO_V1/DIO_Interface.h"
#include"../MCAL/SPI/SPI_Interface.h"
#include"../HAL/7Seg/7Seg_Interface.h"

void main(void){


	//MOSI
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN5,INPUT);

	//MISO
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN6,OUTPUT);

	//ss
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN4,INPUT);
	//SCLK
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN7,INPUT);
	//Initialize as Slave
	SPI_SlaveInit();
	//Initialize 7Seg
	SvSeg_VoidInit(SvSeg_PORTD);
	u8 num=1;
	u8 num2=0;
	while(1){
		u8 Data=0;
		Data=SPI_u8Transeive(77);
		if(Data==1){
			SvSeg_VoidDisplay(num);
			if(num ==0){
				num2 ++;
				num2 %=10;
				SvSeg_VoidDisplay2(SvSeg_PORTC,num2);
			}
			num ++;
			num %=10;
		}
	}
}




