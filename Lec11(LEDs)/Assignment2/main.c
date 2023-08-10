/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Hardware
 */
#include<avr/io.h>
#include<util/delay.h>
typedef signed long int s32;
s32 main(void){
	DDRA = 0b11111111;
	PORTA = 0b0000000;
	s32 arr[8]={0b00000001, //pin0
			   0b00000010, //pin1
			   0b00000100, //pin2
			   0b00001000, //pin3
			   0b00010000, //pin4
			   0b00100000, //pin5
			   0b01000000, //pin6
			   0b10000000, //pin7
	};
	s32 i=0;
	s32 snk=0;
	s32 inp=0;
	s32 Png=0;
	s32 size = sizeof(arr)/sizeof(s32);

	DDRB = 0b00000000;
	PORTB = 0b00000111;   //enable pull up resistor
	while(1){
		inp=(~PINB) &0x07;
		inp++;
		switch(inp){
			case 1:  // Flashing Every 500ms
				PORTA = 0xFF;
				_delay_ms(500);
				PORTA = 0x00;
				_delay_ms(500);
				break;
			case 2: // Shifting Left Every 250ms
				PORTA = arr[i];
				_delay_ms(250);
				i++;
				i=i%size;
				break;
			case 3: // Shifting Right Every 250ms
				PORTA = arr[i];
				_delay_ms(250);
				i--;
				if(i==-1)
					i=size-1;
				break;
			case 4: // 2-LEDs Converging Every 300ms
				for(s32 con=0;con<4;con++){
				PORTA = arr[size-1-con] | arr[con];_delay_ms(300);
					}
				break;
			case 5: // 2-LEDs Diverging Every 300ms
				for(s32 div=0;div<4;div++){
				PORTA = arr[(size/2)+div] | arr[(size/2)-1-div];_delay_ms(300);
					}
				break;
			case 6: // Ping Pong Effect Every 250ms
				if(Png==0){
					for(s32 pp=0;pp<size;pp++){
						PORTA = arr[pp];_delay_ms(250);
						}
				}else{
					for(s32 pp=size-1;pp>=0;pp--){
						PORTA = arr[pp];_delay_ms(250);
					}
				}Png++;
				Png=Png%2;
				break;
			case 7: // Increment (Snake Effect) Every 300ms
				PORTA |= arr[snk];
				_delay_ms(300);
				snk++;
				if(snk==size){
					PORTA=0x00;
					snk=0;
				}
				break;
			case 8: // // 2-LEDs Converging/Diverging Every 300ms
				for(s32 con=0;con<4;con++){
				PORTA = arr[size-1-con] | arr[con];_delay_ms(300);
					}
				for(s32 div=0;div<4;div++){
				PORTA = arr[(size/2)+div] | arr[(size/2)-1-div];_delay_ms(300);
					}
				break;
		}
	}
	return 0;
}

