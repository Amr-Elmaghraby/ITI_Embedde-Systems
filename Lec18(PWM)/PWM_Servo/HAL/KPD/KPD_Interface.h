/*
 * KBD_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Hardware
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#define KPD_COL_PORTA		DIO_PORTA
#define KPD_COL_PORTB		DIO_PORTB
#define KPD_COL_PORTC		DIO_PORTC
#define KPD_COL_PORTD		DIO_PORTD

#define KPD_ROW_PORTA		DIO_PORTA
#define KPD_ROW_PORTB		DIO_PORTB
#define KPD_ROW_PORTC		DIO_PORTC
#define KPD_ROW_PORTD		DIO_PORTD

#define KPD_COL0_PIN		DIO_PIN0
#define KPD_COL1_PIN		DIO_PIN1
#define KPD_COL2_PIN		DIO_PIN2
#define KPD_COL3_PIN		DIO_PIN3

#define KPD_ROW0_PIN		DIO_PIN4
#define KPD_ROW1_PIN		DIO_PIN5
#define KPD_ROW2_PIN		DIO_PIN6
#define KPD_ROW3_PIN		DIO_PIN7


void KPD_VoidInit(u8 Copy_ROW_PORT,u8  Copy_Col_PORT);

u8 KPD_u8GetPressedKey(void);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
