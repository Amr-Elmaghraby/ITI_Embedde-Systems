//include stdio to use printf, scanf
#include <stdio.h>

void main(void){
	//define int to store the height of the pyramid
	int Height;
	printf("Enter heigth of the pyramid: ");
	scanf("%d",&Height);
	for (int i=0;i<Height;i++){
		//loop to add spaces at each level
		for(int j=Height-i-1;j>0;j--){
			printf(" ");
		}
		//loop to add proper value of '*'
		for(int u=2*i+1;u>0;u--){
		printf("*");}
		//add line to end each level
		if(i!=Height-1){
			printf("\n");}
	}
	//while(1){fflush(stdout);}
}