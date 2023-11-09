/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Hardware
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#define GND	0
#define VCC 1
//Set this Macro to VCC or GND
#define A2	GND

void EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16LocationAdd);

void EEPROM_ReadDataByte(u8* Copy_u8DataByte, u16 Copy_u16LocationAdd);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
