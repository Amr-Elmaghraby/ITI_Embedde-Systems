/*
 * USART_Interface.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Elmaghraby
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

void USART_VoidInit(void);

void USART_VoidTxData(u8 Copy_u8Data);

u8 USART_VoidRxData(void);

void USART_VoidTxString(u8* Copy_String);

void USART_VoidCallBackFunction(void(*PTR_CallBackFunc)(void));

#endif /* MCAL_USART_USART_INTERFACE_H_ */
