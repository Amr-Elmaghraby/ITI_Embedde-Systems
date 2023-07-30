#include <stdio.h>

void main(void){
	int Height;
	printf("Enter heigth of the pyramid: ");
	scanf("%d",&Height);
	for (int i=0;i<Height;i++){
		for(int j=Height-i-1;j>0;j--){
			printf(" ");
		}
		for(int u=2*i+1;u>0;u--){
		printf("*");}
		printf("\n");
	}
	
}