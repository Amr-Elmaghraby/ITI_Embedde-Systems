# include <stdio.h>
int get_max(int x[10]);
int get_min(int x[10]);
int main(){
	int nums[10];
	int max,min;
	for(int i=0;i<10;i++){
		printf("Please enter Number%d: ",i+1);
		scanf("%d",&nums[i]);
	}
	max= get_max(nums);
	min= get_min(nums);
	printf("\nMax number Entered is: %d\n",max);
	printf("Min number Entered is: %d\n",min);
	return 0;
}

int get_max(int x[10]){
	int mx;
	mx = x[0];
	for(int i=1;i<10;i++){
		if(mx<x[i]){
			mx=x[i];
		}
	}
	return mx;
}
int get_min(int x[10]){
	int mi;
	mi = x[0];
	for(int i=1;i<10;i++){
		if(mi>x[i]){
			mi=x[i];
		}
	}
	return mi;
}