/*
 * main3.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Hardware
 */

/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */
/*

#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"

#include"../HAL/LCD/LCD_Interface.h"
#include"../HAL/KPD_Handler/KPD_Interface.h"
#include"../HAL/7Seg/7Seg_Interface.h"
#include"../MCAL/Driver_DIO/DIO_Interface.h"

#include<util/delay.h>


#include<stdio.h>

u16 power(u8 base,u8 exp){
	u16 val=1;
	if(exp==0){return 1;}
	else{
		while(exp!=0){
			val *= base;
			exp--;
			}
	}
	return val;
}


void main(void){
	KPD_VoidInit(KPD_ROW_PORTC,KPD_COL_PORTC);
	LCD_VoidInit();
	u8 ascii=200;
	u8 size = 2;
	s32 par[2]={0,0};
	s32 val=0;

	u8 idx=0;
	u8 sign=0;
	u8 str='+';

	while(1){
		u8 num=KPD_u8GetPressedKey();
		if(num!=255){
			if(num=='&'){LCD_VoidClearDisplay();
			idx=0;
			for(u8 i=0;i<size;i++){
					par[i]=0;
					 }
			}
			else if(num=='='){
				if(sign==1){
					par[1] = -1*par[1];
					sign=0;
				}
				u8 base=0;
				u8 st=0;
				u8 div=0;
				u8 nextCHK=2;
				LCD_VoidClearDisplay();
				switch (str){
					case '/':
						val = par[0] / par[1];
						break;
					case '*':
						val = par[0] * par[1];
						break;
					case '-':
						val = par[0] - par[1];
						break;
					case'+':
						val = par[0] + par[1];
						break;
				}
				par[0] = val;
				par[1] = 0;
				idx=0;
				LCD_voidSendNumber(val);

				}
			else if(num=='-'){
				 ascii = num;
				 LCD_VoidSendData(ascii);
				if(par[idx]==0){
					sign=1;
				}
				else{
					if(sign==1){
						par[0] = -1*par[0];
						sign=0;
						}
					idx++;
					str=num;
					}
			}
			else if(num=='/' || num=='*' || num=='+'){
				 str=num;
				 ascii = num;
				 LCD_VoidSendData(ascii);
				 if(sign==1){
					par[0] = -1*par[0];
					sign=0;
					}
				 idx++;
				 if(idx>(size-1)){
					 LCD_VoidClearDisplay();
					 LCD_voidSendString("Syntax Error");
					 for(u8 i=0;i<size;i++){
						 par[i]=0;
					 }
				 }
			}
			else{
				ascii = num + '0';
				LCD_VoidSendData(ascii);
				par[idx] = num + par[idx]*10;
			}
		}
	}
}

*/
