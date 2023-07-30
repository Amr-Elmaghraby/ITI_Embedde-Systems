# include <stdio.h>

void main(void){
	//define two integers
	int a,b;
	//Insert two numbers from user
	printf("Please enter number a: ");
	scanf("%d",&a);
	printf("Please enter number b: ");
	scanf("%d",&b);
	//Summing
	printf("%d + %d = %d\n",a,b,a+b);
	//Subtracting
	printf("%d - %d = %d\n",a,b,a-b);
	//Adding
	printf("%d & %d = %d\n",a,b,a%b);
	//Orring
	printf("%d | %d = %d\n",a,b,a|b);
	//Xoring
	printf("%d ^ %d = %d\n",a,b,a^b);
}