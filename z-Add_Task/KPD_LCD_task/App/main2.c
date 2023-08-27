/*
 * main2.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hardware
 */
/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hardware
 */


/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */


#include "../LIB/STD_Type.h"
#include "../LIB/BIT_Math.h"

#include"../HAL/LCD/LCD_Interface.h"
#include"../HAL/KPD_Handler/KPD_Interface.h"
#include"../HAL/7Seg/7Seg_Interface.h"
#include"../MCAL/Driver_DIO/DIO_Interface.h"

#include<util/delay.h>
/*



void main(void){
	KPD_VoidInit(KPD_ROW_PORTC,KPD_COL_PORTC);
	LCD_VoidInit();

	u32 dec=0;

	while(1){
		u8 num=KPD_u8GetPressedKey();
		if(num!=255){
			if(num=='&'){LCD_VoidClearDisplay();
			 LCD_VoidSendData('D');LCD_VoidSendData('E');LCD_VoidSendData('C');LCD_VoidSendData(':');
			 LCD_GoTOXY(1,0);
			 LCD_VoidSendData('B');LCD_VoidSendData('I');LCD_VoidSendData('N');LCD_VoidSendData(':');
			 LCD_GoTOXY(0,4);
			}
			else if(num=='='){
				LCD_GoTOXY(1,4);
				LCD_VoidSendData('0');LCD_VoidSendData('b');
				u32 val=dec;
				u8 arr[20];
				u8 size=0;
				while(val!=0){
					if(val%2==0){
						arr[size] = 0;
					}
					else{
						arr[size] = 1;
						val=val-1;
					}
					val /=2;
					size++;
				}

				for(s8 i=size-1;i>=0;i--){
					LCD_VoidSendData(arr[i]+'0');
				}
				dec=0;
			}
			else if(num=='/' || num=='*' || num=='-'|| num=='+'){

					 dec=0;
					 LCD_VoidClearDisplay();
					 LCD_VoidSendData('D');LCD_VoidSendData('E');LCD_VoidSendData('C');LCD_VoidSendData(':');
					 LCD_GoTOXY(1,0);
					 LCD_VoidSendData('B');LCD_VoidSendData('I');LCD_VoidSendData('N');LCD_VoidSendData(':');
					 LCD_GoTOXY(0,4);
				 }
			else{
				dec = num + dec*10;
				LCD_VoidSendData(num+'0');
			}
		}
	}
}
*/


