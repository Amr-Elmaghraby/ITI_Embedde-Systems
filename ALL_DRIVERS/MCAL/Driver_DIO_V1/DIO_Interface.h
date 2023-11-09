/*
 * DIO_Interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Hardware
 */

#ifndef MCAL_DRIVER_DIO_V1_DIO_INTERFACE_H_
#define MCAL_DRIVER_DIO_V1_DIO_INTERFACE_H_

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7

#define OUTPUT	1
#define INPUT	0

#define	HIGH	1
#define LOW		0

//return type ModelName_returntypeFunction(datatype Copy_datatypePArameter)
//DIO_PORTA, DIO_PIN1, OUTPUT

//DIO_PORTA, DIO_PIN1, HIGH

void DIO_VoidSetPinDirection(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_PinState);

void DIO_VoidSetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void DIO_VoidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection);

void DIO_VoidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);

#endif /* MCAL_DRIVER_DIO_V1_DIO_INTERFACE_H_ */
