#include <stdio.h>



void main(void){
		int val=46;
		int arr[20];
		int size=0;
		while(val!=0){
			if(val%2==0){
				arr[size] = 0;
			}
			else{
				arr[size] = 1;
				val=val-1;
				}
				val /=2;
				size++;
			}

			for(int i=size-1;i>=0;i--){
				printf("%d",arr[i]);
				}	
}