/*
 * TWI_Program.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Hardware
 */
#include<avr/io.h>

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"

#include"TWI_Interface.h"
/* pass 0 in master address if master will not be addressed*/
void TWI_VoidMasterInit(u8 Copy_MasterAddress){
	//Set Baud Rate value ==> 400 Kbps
	/*
	 * SCL = CPU Clock Freq /(16 + 2(TWBR) * (4 ^ TWPS))
	 * TWBR = 2
	 * TWPS = 0
	 */
	TWBR = 2;
	CLR_Bit(TWSR,TWPS1);
	CLR_Bit(TWSR,TWPS0);

	//Set Master Address
	if(Copy_MasterAddress !=0){
		TWAR = Copy_MasterAddress <<1;
	}
	/*enable TWI */
	Set_Bit(TWCR, TWEN);

}

void TWI_VoidSlaveInit(u8 Copy_SlaveAddress){
	//Set Slave Address
	TWAR = Copy_SlaveAddress <<1;

	//Enable TWI
	Set_Bit(TWCR,TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void){
	TWI_ErrStatus 	Local_ErrStatus = NoError;
	//Send Start Condition
	Set_Bit(TWCR,TWSTA);

	//Clear Flag to start previous operation
	Set_Bit(TWCR,TWINT);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=START_ACK){
		Local_ErrStatus = StartConditionErr;
		}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatedStart(void){
	TWI_ErrStatus 	Local_ErrStatus = NoError;
	//Send Start Condition
	Set_Bit(TWCR,TWSTA);

	//Clear Flag to start previous operation
	Set_Bit(TWCR,TWINT);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=REP_START_ACK){
		Local_ErrStatus = RepeatedStartErr;
		}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_SlaveAddress){
	TWI_ErrStatus 	Local_ErrStatus = NoError;

	//Clear Start Condition
	//CLR_Bit(TWCR,TWSTA);

	//Set Slave Address
	TWDR = Copy_SlaveAddress <<1;
	//For Write Operation
	CLR_Bit(TWDR,0);

	//Clear Flag to start previous operation  //Enable TWI
	TWCR=(1<<TWINT)|(1<<TWEN);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=SLAVE_ADD_AND_WR_ACK){
		Local_ErrStatus = SlaveAddressWithWriteErr;
		}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_SlaveAddress){
	TWI_ErrStatus 	Local_ErrStatus = NoError;

	//Clear Start Condition
	//CLR_Bit(TWCR,TWSTA);

	//Set Slave Address
	TWDR = Copy_SlaveAddress <<1;
	//For Read Operation
	Set_Bit(TWDR,0);

	//Clear Flag to start previous operation
	TWCR=(1<<TWINT)|(1<<TWEN);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=SLAVE_ADD_AND_RD_ACK){
		Local_ErrStatus = SlaveAddressWithReadErr;
		}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte){
	TWI_ErrStatus 	Local_ErrStatus = NoError;

	//Write Data to data byte
	TWDR = Copy_u8DataByte;

	//Clear Flag to start previous operation
	Set_Bit(TWCR,TWINT);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=MasterWriteDataByteErr){
		Local_ErrStatus = MasterWriteDataByteErr;
		}
	return Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_Pu8DataByte)
{
	TWI_ErrStatus 	Local_ErrStatus = NoError;

	//Enable ACK
	Set_Bit(TWCR,TWEA);
	//Clear Flag to start previous operation
	Set_Bit(TWCR,TWINT);

	//Wait Until Interrupt Flag is Raised Again and previous operation is completed
	while(!Get_Bit(TWCR,TWINT));

	//Check Status  ,  Status is in bit3 => 7 in  TWSR Reg
	if((TWSR & 0xF8)!=MSTR_RD_BYTE_WITH_ACK){
		Local_ErrStatus = MasterReadDataByteErr;
		}
	else{
		// Read Data
		*Copy_Pu8DataByte = TWDR;

	}
	return Local_ErrStatus;
}

void TWI_SendStopCondition(void)
{
	/* generate stop condition on the bus */
	Set_Bit(TWCR,TWSTO);

	/* Clear the interrupt flag to start the previous operation */
	Set_Bit(TWCR,TWINT);
}



