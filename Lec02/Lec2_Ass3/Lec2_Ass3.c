# include <stdio.h>

void main(void){
	int num_1,num_2,num_3,max;
	// Input the three numbers from the user
	printf("Please Enter number1: ");
	scanf("%d",&num_1);
	printf("Please Enter number2: ");
	scanf("%d",&num_2);
	printf("Please Enter number3: ");
	scanf("%d",&num_3);
	// Find the maximum number among the three
	max=num_1; // Assume the first number is the maximum
	if(max < num_2){
		max=num_2; // Update max if the second number is greater
	}
	if(max<num_3){
		max=num_3; // Update max if the third number is greater
	}
	printf("Max value of \" %d, %d, %d \" is %d ",num_1,num_2,num_3,max);
}