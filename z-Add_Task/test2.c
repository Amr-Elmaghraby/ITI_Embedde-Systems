	#include<stdio.h>
	
	
	int main(void){
		int Copy_Prescaller = 10;
		printf("rescaller Initial Value = %d\n",Copy_Prescaller);
	for(int i=0;i<3;i++){
		if((Copy_Prescaller%10)==1)
			printf("1\n");
		else
			printf("0\n");
		Copy_Prescaller = Copy_Prescaller /10;
		printf("prescaller=%d\n",Copy_Prescaller);
	}
	return 0;
	}