/*
 * LCD_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Hardware
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/*
 * RS(Register Select): 0 ==> Send LCD Data   1==> Take Data
 * RW(Read/Write): 0 ==> Write   1==>Read
 * EN(Enable)
 * */

#define LCD_DATA_PORT	DIO_PORTA

#define LCD_RS_PORT		DIO_PORTB
#define LCD_RS_PIN		DIO_PIN0

#define LCD_RW_PORT		DIO_PORTB
#define LCD_RW_PIN		DIO_PIN1

#define LCD_EN_PORT		DIO_PORTB
#define LCD_EN_PIN		DIO_PIN2



void LCD_VoidSendData(u8 Copy_u8Data);

void LCD_VoidSendCommand(u8 Copy_u8Command);

void LCD_VoidInit(void);

void LCD_VoidClearDisplay(void);

void LCD_GoTOXY(u8 Copy_u8X,u8 Copy_u8Y);



#endif /* HAL_LCD_LCD_INTERFACE_H_ */
