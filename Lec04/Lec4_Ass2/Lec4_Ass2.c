# include <stdio.h>
void Add(int a , int b){
	printf("%d + %d = %d",a,b,a+b);
}
void Subtract(int a , int b){
	printf("%d - %d = %d",a,b,a-b);
}
void Multiply(int a , int b){
	printf("%d * %d = %d",a,b,a*b);
}
void Divide(int a , int b){
	printf("%d / %d = %1.2f",a,b,(float)a/b);
}
void And(int a , int b){
	printf("%d & %d = %d",a,b,a&b);
}
void Or(int a , int b){
	printf("%d | %d = %d",a,b,a|b);
}
void Not(int a){
	printf("!%d= %d",a,!a);
}
void Xor(int a , int b){
	printf("%d ^ %d = %d",a,b,a^b);
}
void Reminder(int a , int b){
	printf("%d %% %d = %d",a,b,a%b);
}
void Increment(int a){
	printf("++%d = %d",a,a+1);
}
void Decrement(int a){
	printf("--%d = %d",a,a-1);
}

int main(){
	int opr;
	int operan[2];
	int itr=0;
	printf("Please Enter Operation ID: ");
	scanf("%d",&opr);
	if(opr== 7 ||opr== 10 ||opr== 11 ){itr=1;}else{itr=2;}
	for(int i=0;i<itr;i++){	
		printf("Please Enter Operand%d: ",i+1);
		scanf("%d",&operan[i]);
	}
	switch(opr){
		case 1:
			Add(operan[0],operan[1]);
			break;
		case 2:
			Subtract(operan[0],operan[1]);
			break;
		case 3:
			Multiply(operan[0],operan[1]);
			break;
		case 4:
			Divide(operan[0],operan[1]);
			break;
		case 5:
			And(operan[0],operan[1]);
			break;
		case 6:
			Or(operan[0],operan[1]);
			break;
		case 7:
			Not(operan[0]);
			break;
		case 8:
			Xor(operan[0],operan[1]);
			break;
		case 9:
			Reminder(operan[0],operan[1]);
			break;
		case 10:
			Increment(operan[0]);
			break;	
		case 11:
			Decrement(operan[0]);
			break;
		default:
			printf("Inorrect ID value");
			break;
		
	}

	return 0;
}





















