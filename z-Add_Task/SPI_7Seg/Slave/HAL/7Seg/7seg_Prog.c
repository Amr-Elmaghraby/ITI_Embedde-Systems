/*
 * 7seg_Prog.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hardware
 */
#include<util/delay.h>

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"
#include"../../MCAL/Driver_DIO_V1/DIO_Interface.h"

#include"7Seg_Interface.h"

u8 Port;
u8 arr[10]={0b00111111, //0
				0b00000110, //1
				 0b01011011, //2
				 0b01001111, //3
				 0b01100110, //4
				 0b01101101, //5
	             0b01111101, //6
	             0b00000111, //7
	             0b01111111, //8
	             0b01101111, //9
	             };
void SvSeg_VoidInit(u8 Copy_Port){
	Port = Copy_Port;
	DIO_VoidSetPortDirection(Copy_Port,0xFF);
}
void SvSeg_VoidCounter(u8 del_Sec){
	for(u8 i=0;i<10;i++){
		DIO_VoidSetPortValue(Port,arr[i]);
		_delay_ms(del_Sec*1000);
	}
}

void SvSeg_VoidDisplay(u8 number){
	DIO_VoidSetPortValue(Port,arr[number]);
}

void SvSeg_CLR(void){
	DIO_VoidSetPortValue(Port,OFF);
}

void SvSeg_VoidDisplay2(u8 Copy_port, u8 number){
	DIO_VoidSetPortDirection(Copy_port,0xFF);
	DIO_VoidSetPortValue(Copy_port,arr[number]);
}




