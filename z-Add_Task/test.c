#include <stdio.h>
#include <stdlib.h>
void LCD_voidSendString(char* Copy_pcString)
{
	int Local_u8Index=0;

	while(Copy_pcString[Local_u8Index]!='\0')
	{
		printf("%c\n",Copy_pcString[Local_u8Index]);
		Local_u8Index++;
	}
}
int main() {
    int number = 9876405;
	printf("%lld\n",number);
    char str[2]; // Allocate a buffer to hold the string

    itoa(number, str, 10); // Convert integer to string
	printf("%lld\n",number);
	LCD_voidSendString(str);	


    return 0;
}
