/*
 * WDT_Prog.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Hardware
 */

#include<avr/io.h>

#include"../../LIB/STD_Type.h"
#include"../../LIB/BIT_MATH.h"

#include"WDT_Interface.h"

void WDT_VoidEnable(void){
	Set_Bit(WDTCR,3);
}

void WDT_VoidDisable(void){
	WDTCR |= (3<<3);
	CLR_Bit(WDTCR,3);
}

void WDT_VoidSleep(u8 Copy_u8SleepTime){
	//Set Prescale Value
	for(u8 i=0;i<3;i++){
		if((Copy_u8SleepTime%10)==1)
			Set_Bit(WDTCR,i);
		else
			CLR_Bit(WDTCR,i);
		Copy_u8SleepTime = Copy_u8SleepTime /10;
	}
}

