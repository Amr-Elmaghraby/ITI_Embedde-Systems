/*
 * Servo_Program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Hardware
 */

#include"../../LIB/STD_Type.h"

#include"../../MCAL/TIMER/TIMER_Interface.h"
 u16 Ticks=0;

 void Servo_VoidInit(void){
		TIMER_VoidTimer1Init(PWM,10);
		TIMER_VoidSetOverFlow(20000);
 }

void Servo_VoidDegree(u8 Copy_u8Degree){
	if(Copy_u8Degree>180)
		Copy_u8Degree = 180;
	f32 Ton = (1/180.0) * Copy_u8Degree + 1;
	Ticks = Ton * 1000;
	TIMER_VoidTimer1ChannelASetCompareValue(Ticks);
}

void Servo_VoidReset(void){
	TIMER_VoidTimer1ChannelASetCompareValue(0);
}

u16 Servo_u16GetTicks(void){
	return Ticks;
}
