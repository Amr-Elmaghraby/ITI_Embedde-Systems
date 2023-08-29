/*
 * PIE_Prog.c


 *
 *  Created on: Aug 17, 2023
 *      Author: Hardware
 */

#include<avr/io.h>
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"EXTI_Interface.h"

void (*global_PTRINT0NotificationFunction)(void)=0x00;
void (*global_PTRINT1NotificationFunction)(void)=0x00;

void EXTI_VoidInit(u8 INT_Number, u8 Mode){
	switch(INT_Number){
		case EXT_INT0:
			switch(Mode){
				case RISING:
					//set interrupt 1 to rising edge
					Set_Bit(MCUCR,0);
					Set_Bit(MCUCR,1);
					break;
				case FALLING:
					//INT1--->falling edge
					CLR_Bit(MCUCR,0);
					Set_Bit(MCUCR,1);
					break;
				case LOGICAL_CHANGE:
					//set interrupt 0 to any logical change
					Set_Bit(MCUCR,0);
					CLR_Bit(MCUCR,1);
					break;
			}
			//Enable INT0
			Set_Bit(GICR,6);
			break;
		case EXT_INT1:
			switch(Mode){
				case RISING:
					//set interrupt 1 to rising edge
					Set_Bit(MCUCR,2);
					Set_Bit(MCUCR,3);
					break;
				case FALLING:
					//falling edge
					CLR_Bit(MCUCR,2);
					Set_Bit(MCUCR,3);
					break;
				case LOGICAL_CHANGE:
					//any logical change
					Set_Bit(MCUCR,2);
					CLR_Bit(MCUCR,3);
					break;
			}
			//Enable INT1
			Set_Bit(GICR,7);
			break;
	}
}

void EXTI_VoidDisable(u8 INT_Number){
	switch(INT_Number){
		case EXT_INT0:
			//Disable INT0
			CLR_Bit(GICR,6);
			break;
		case EXT_INT1:
			//Disable INT1
			CLR_Bit(GICR,7);
			break;
	}
}

void EXTI_VoidINT0CallBack(void(*NotificationFunction)(void)){
	global_PTRINT0NotificationFunction= NotificationFunction;
}

void EXTI_VoidINT1CallBack(void(*NotificationFunction)(void)){
	global_PTRINT1NotificationFunction= NotificationFunction;
}

//INT0
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if(global_PTRINT0NotificationFunction!=0x00)
	global_PTRINT0NotificationFunction();
}

//INT1
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if(global_PTRINT1NotificationFunction!=0x00)
		global_PTRINT1NotificationFunction();
}











