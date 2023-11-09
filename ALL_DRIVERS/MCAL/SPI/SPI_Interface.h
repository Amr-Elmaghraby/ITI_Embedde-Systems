/*
 * SPI_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Hardware
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_MasterInit(void);

void SPI_SlaveInit(void);

u8 SPI_u8Transeive(u8 Copy_u8Data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
