/*
 * ADC_Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Hardware
 */

#include<avr/io.h>

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"ADC_Interface.h"

void ADC_VoidInit(void){
	//set reference voltage ===> AVCC
	Set_Bit(ADMUX,6);
	CLR_Bit(ADMUX,7);

	//set left adjustment
	Set_Bit(ADMUX,5);

	//set ADC Prescaller  ===> 64
	CLR_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);

	//Enable ADC
	Set_Bit(ADCSRA,7);


}

u8 ADC_u8StartConversion(u8 Copy_u8ChannelNumber){
	//ADC Channel Select
	ADMUX&=0b11100000;
	ADMUX|=Copy_u8ChannelNumber;

	//ADC Start Conversion
	Set_Bit(ADCSRA,6);

	//wait until conversion is completed
	while(!Get_Bit(ADCSRA,4));

	//Clear Flag
	Set_Bit(ADCSRA,4);

	//return value from ADCH
	return ADCH;
}









