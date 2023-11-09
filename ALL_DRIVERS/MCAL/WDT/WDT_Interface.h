/*
 * WDT_Interface.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Hardware
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

void WDT_VoidEnable(void);

void WDT_VoidDisable(void);
/*
	WDP2 	WDP1	WDP0	Number of WDT Oscillator Cycles		Typical Time-out( VCC = 3.0V)	Typical Time-out(VCC = 5.0V)
	0 		0 		0 		16K (16,384) 							17.1 ms 							16.3 ms
	0		0		1 		32K (32,768) 							34.3 ms 							32.5 ms
	0	 	1		0 		64K (65,536) 							68.5 ms 							65 ms
	0 		1		1 		128K (131,072)						 	0.14 s 								0.13 s
	1		0 		0 		256K (262,144)							0.27 s 								0.26 s
	1 		0 		1 		512K (524,288) 							0.55 s 								0.52 s
	1 		1 		0 		1,024K (1,048,576)						1.1 s 								1.0 s
	1		1 		1 		2,048K (2,097,152) 						2.2 s 								2.1 s
*/
//NOTE:  Do Not Write 0 at first      "e.g.  011 ===> 11"

void WDT_VoidSleep(u8 Copy_u8SleepTime);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
