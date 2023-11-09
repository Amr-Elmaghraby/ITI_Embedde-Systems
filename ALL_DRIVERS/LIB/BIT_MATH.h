
#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define Set_Bit(var,Bit_No)   (var |=(1<<Bit_No))
#define CLR_Bit(var,Bit_No)   (var &=~(1<<Bit_No))
#define Toggle(var,Bit_No)    (var ^=(1<<Bit_No))
#define Get_Bit(var,Bit_No)   ((var>>Bit_No) & 0x01)

#endif
