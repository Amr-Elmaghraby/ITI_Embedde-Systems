/*
 * EEPROM_Program.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Hardware
 */
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"../../MCAL/TWI/TWI_Interface.h"

#include"EEPROM_Interface.h"
#include"../../MCAL/Driver_DIO_V1/DIO_Interface.h"

void EEPROM_SendDataByte(u8 Copy_u8DataByte,u16 Copy_u16LocationAddress)
{	u8 Address = ((0b1010<<3) | (A2<<2) | (Copy_u16LocationAddress>>8));

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Address);
	//TWI_SendSlaveAddressWithWrite(0b1010000);/**/

	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);
    TWI_MasterWriteDataByte(Copy_u8DataByte);
    TWI_SendStopCondition();
}

void EEPROM_ReadDataByte(u8 *Copy_u8DataByte,u16 Copy_u16LocationAddress)
{	u8 Address = ((0b1010<<3) | (A2<<2) | (Copy_u16LocationAddress>>8));
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Address);
	//TWI_SendSlaveAddressWithWrite(0b1010000);

	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);

	TWI_SendRepeatedStart();

	//TWI_MasterWriteDataByte(0b10100001);/**/
	TWI_SendSlaveAddressWithRead(Address);
	TWI_MasterReadDataByte(Copy_u8DataByte);
	TWI_SendStopCondition();
}












