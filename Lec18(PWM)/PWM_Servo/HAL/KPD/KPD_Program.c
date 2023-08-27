/*
 * KDP_Prog.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hardware
 */
/*
 * KPD_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Hardware
 */
#include "../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"../../MCAL/Driver_DIO_V1/DIO_Interface.h"

#include"KPD_Interface.h"


u8 ROW_PORT; u8 COL_PORT;

void KPD_VoidInit(u8 Copy_ROW_PORT,u8  Copy_Col_PORT){
	ROW_PORT = Copy_ROW_PORT;
	COL_PORT = Copy_Col_PORT;

	DIO_VoidSetPinDirection(Copy_Col_PORT,KPD_COL0_PIN,OUTPUT);
	DIO_VoidSetPinDirection(Copy_Col_PORT,KPD_COL1_PIN,OUTPUT);
	DIO_VoidSetPinDirection(Copy_Col_PORT,KPD_COL2_PIN,OUTPUT);
	DIO_VoidSetPinDirection(Copy_Col_PORT,KPD_COL3_PIN,OUTPUT);

	DIO_VoidSetPinValue(Copy_Col_PORT,KPD_COL0_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_Col_PORT,KPD_COL1_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_Col_PORT,KPD_COL2_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_Col_PORT,KPD_COL3_PIN,HIGH);

	DIO_VoidSetPinDirection(Copy_ROW_PORT,KPD_ROW0_PIN,INPUT);
	DIO_VoidSetPinDirection(Copy_ROW_PORT,KPD_ROW1_PIN,INPUT);
	DIO_VoidSetPinDirection(Copy_ROW_PORT,KPD_ROW2_PIN,INPUT);
	DIO_VoidSetPinDirection(Copy_ROW_PORT,KPD_ROW3_PIN,INPUT);

	DIO_VoidSetPinValue(Copy_ROW_PORT,KPD_ROW0_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_ROW_PORT,KPD_ROW1_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_ROW_PORT,KPD_ROW2_PIN,HIGH);
	DIO_VoidSetPinValue(Copy_ROW_PORT,KPD_ROW3_PIN,HIGH);

}

u8 KPD_u8GetPressedKey(void){
	u8 Local_u8PressedKey=0xFF;

	u8 Local_u8ColumsArray[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 Local_u8RowsArray[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	u8 Local_u8KeyArray[4][4]={{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'&',0,'=','+'}};

	for(u8 Local_u8ColumsIndex=0;Local_u8ColumsIndex<4;Local_u8ColumsIndex++){

		DIO_VoidSetPinValue(COL_PORT,Local_u8ColumsArray[Local_u8ColumsIndex],LOW);

		for(u8 Local_u8RowsIndex=0;Local_u8RowsIndex < 4;Local_u8RowsIndex++){

			u8 Local_u8PinState=DIO_u8GetPinValue(ROW_PORT,Local_u8RowsArray[Local_u8RowsIndex]);

			if(Local_u8PinState==0){
				Local_u8PressedKey=Local_u8KeyArray[Local_u8RowsIndex][Local_u8ColumsIndex];
				while(Local_u8PinState==0){
					Local_u8PinState=DIO_u8GetPinValue(ROW_PORT,Local_u8RowsArray[Local_u8RowsIndex]);
				}
				return Local_u8PressedKey;
			}
		}
		DIO_VoidSetPinValue(COL_PORT,Local_u8ColumsArray[Local_u8ColumsIndex],HIGH);
	}
	return Local_u8PressedKey;

}


