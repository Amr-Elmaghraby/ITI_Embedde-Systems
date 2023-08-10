/*
 * main.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Hardware
 */

#include<avr/io.h>
#include<util/delay.h>
typedef signed long int s32;

s32 main(){
	DDRA = 0b00000111;
	DDRD = 0b11111111;
	s32 arr[10]={0b00000110, //1
				 0b01011011, //2
				 0b01001111, //3
				 0b01100110, //4
				 0b01101101, //5
	             0b01111101, //6
	             0b00000111, //7
	             0b01111111, //8
	             0b01101111, //9
	             0b00111111}; //0
	s32 out[3]={0x01, 0x02, 0x04};
	s32 sec[3]={10,3,10};
	s32 cont=0;
	while(1){
		PORTA = out[cont];
		for(s32 i=0;i<sec[cont];i++){
			PORTD = arr[i];_delay_ms(1000);
		}
		cont++;
		cont %= 3;
	}
	return 0;
}


