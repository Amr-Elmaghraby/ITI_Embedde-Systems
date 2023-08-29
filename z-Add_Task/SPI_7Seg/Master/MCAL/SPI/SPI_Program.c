/*
 * SPI_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Hardware
 */
#include<avr/io.h>

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"SPI_Interface.h"

void SPI_MasterInit(void){
	//Master Initialize
	Set_Bit(SPCR,4);
	//Clock prescaler -->64
	Set_Bit(SPCR,1);
	CLR_Bit(SPCR,0);
	CLR_Bit(SPSR,0);
	//Enable SPI
	Set_Bit(SPCR,6);

}

void SPI_SlaveInit(void){
	//Slave Initialize
	CLR_Bit(SPCR,4);

	//Enable SPI
	Set_Bit(SPCR,6);
}

u8 SPI_u8Transeive(u8 Copy_u8Data){
	//Send Data
	SPDR = Copy_u8Data;
	//Wait Until Transfer is complete , Flag is Cleared Automatic
	while(Get_Bit(SPSR,7)==0);
	//Receive Data "Get Exchanged Data"
	return SPDR;
}
