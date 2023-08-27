/*
 * 7Seg_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Hardware
 */

#ifndef HAL_7SEG_7SEG_INTERFACE_H_
#define HAL_7SEG_7SEG_INTERFACE_H_

#define SvSeg_PORTA			DIO_PORTA
#define SvSeg_PORTB			DIO_PORTB
#define SvSeg_PORTC			DIO_PORTC
#define SvSeg_PORTD			DIO_PORTD

#define OFF					0x00

void SvSeg_VoidCounter(u8 Copy_Port, u8 del_Sec);

void SvSeg_VoidDisplay(u8 Copy_Port,u8 number);

void SvSeg_CLR(void);

#endif /* HAL_7SEG_7SEG_INTERFACE_H_ */
