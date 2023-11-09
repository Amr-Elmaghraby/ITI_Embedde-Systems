/*
 * USART_Program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Elmaghraby
 */
#include<avr/io.h>

#include"../../LIB/STD_Type.h"
#include"../../LIB/BIT_MATH.h"

#include"USART_Interface.h"

void(*GLOBAL_PTR_CallBack)(void) = NULL;

void USART_VoidInit(void){
	//Note: UCSRC is not bit allocate
	u8 Local_u8UCSRC_value=0;
	//Select UCSRC Reg
	Set_Bit(Local_u8UCSRC_value,7);

	//Select Asynchronous Mode
	CLR_Bit(Local_u8UCSRC_value,6);

	//Disable Parity Mode
	CLR_Bit(Local_u8UCSRC_value,5);
	CLR_Bit(Local_u8UCSRC_value,4);

	//Select Stop bit to be 1 bit
	CLR_Bit(Local_u8UCSRC_value,3);

	//Select 8 bit character size
	Set_Bit(Local_u8UCSRC_value,2);
	Set_Bit(Local_u8UCSRC_value,1);
	CLR_Bit(UCSRB,2); //Note IN Another Register

	//Put Value to UCSRC
	UCSRC = Local_u8UCSRC_value;

	//Baud Rate  9600 Sample per Second
	UBRRL = 51;
	//enable receiver
	Set_Bit(UCSRB,4);
	//enable transmitter
	Set_Bit(UCSRB,3);
}

void USART_VoidTxData(u8 Copy_u8Data){
	//Wait until Transmit data buffer is empty
	while(Get_Bit(UCSRA,5)==0);
	//Clear Flag
	Set_Bit(UCSRA,5);

	UDR = Copy_u8Data;

}

u8 USART_VoidRxData(void){
	//Wait until Receiving Data
	while(Get_Bit(UCSRA,7)==0);
	//Clear Flag


	return UDR;
}

void USART_VoidTxString(u8* Copy_String){
	u8 Local_idx=0;
	while(Copy_String[Local_idx] != '\0'){
		USART_VoidTxData(Copy_String[Local_idx]);
		Local_idx ++;
	}
}

void USART_VoidCallBackFunction(void(*PTR_CallBackFunc)(void)){
	GLOBAL_PTR_CallBack = PTR_CallBackFunc;
	Set_Bit(UCSRB,7);
}

void __vector_13 (void) __attribute__((signal));
void __vector_13 (void){
	if(GLOBAL_PTR_CallBack!=0x00)
		GLOBAL_PTR_CallBack();
}









