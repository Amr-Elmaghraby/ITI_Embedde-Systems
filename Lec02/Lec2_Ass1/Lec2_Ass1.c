# include <stdio.h>

int main(){
	int nums[10];
	int number;
	int idx= -1;
	
	for(int i=0;i<10;i++){
		printf("Enter Number %d:",i+1);
		scanf("%d",&nums[i]);
	}
	//Enter number to search for
	printf("Enter number to search for: ");
	scanf("%d",&number);
	for(int i=0;i<10;i++){
		if(number==nums[i]){
			idx = i+1;
			break; // to print first found element
		}
	}
	if(idx ==-1){
		printf("Number is not found");
	}else{
		printf("Value is exist at element number %d",idx);
	}
}
