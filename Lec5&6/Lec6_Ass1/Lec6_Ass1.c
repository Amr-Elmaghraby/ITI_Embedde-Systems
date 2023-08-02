# include <stdio.h>

void bubble_sort(int* ptr,int size){
		for(int i=0;i<size-1;i++){
		for(int j=1;j<size-i;j++){
			if(ptr[j]<ptr[j-1]){
				ptr[j] ^= ptr[j-1] ^= ptr[j] ^= ptr[j-1];
			}
		}
	}
} 

int main(){
	int size;
	printf("Please Enter array size: ");
	scanf("%d",&size);
	
	int nums[size];
	for(int i=0;i<size;i++){
		printf("Please enter ptrmber%d: ",i+1);
		scanf("%d",&nums[i]);
	}
	bubble_sort(&nums[0],size);

	printf("Values After Sorting are: \n");
	for(int i=0;i<size;i++){
		printf("%d\n",nums[i]);
	}
	
}