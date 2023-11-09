/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Hardware
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXT_INT0		0
#define EXT_INT1		1

#define RISING 	2
#define FALLING 3
#define LOGICAL_CHANGE 4


void EXTI_VoidInit(u8 INT_Number, u8 Mode);

void EXTI_VoidDisable(u8 INT_Number);


void EXTI_VoidINT0CallBack(void(*NotificationFunction)(void));
void EXTI_VoidINT1CallBack(void(*NotificationFunction)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
