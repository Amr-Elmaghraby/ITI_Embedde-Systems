# include <stdio.h>

int main(){
	int in_ID,in_pass,corr_pass;

	printf("Please enter your ID:");
	scanf("%d",&in_ID);
	//check the ID and create password to be same as ID 
	switch(in_ID){
		case 111:
			corr_pass = in_ID;
			printf("Please Enter your Password: ");
			scanf("%d",&in_pass);
			if(in_pass==corr_pass){
				printf("Welcome Amr");
			}else{
				printf("Incorrect Pass");
			}
			break;
		case 123:
			corr_pass = in_ID;
			printf("Please Enter your Password: ");
			scanf("%d",&in_pass);
			if(in_pass==corr_pass){
				printf("Welcome Omar");
			}else{
				printf("Incorrect Pass");
			}	
			break;
		case 133:
			corr_pass = in_ID;
			printf("Please Enter your Password: ");
			scanf("%d",&in_pass);
			if(in_pass==corr_pass){
				printf("Welcome Ahmed");
			}else{
				printf("Incorrect Pass");
			}
			break;
		case 234:
			corr_pass = in_ID;
			printf("Please Enter your Password: ");
			scanf("%d",&in_pass);
			if(in_pass==corr_pass){
				printf("Welcome Hany");
			}else{
				printf("Incorrect Pass");
			}
			break;
		case 345:
			corr_pass = in_ID;
			printf("Please Enter your Password: ");
			scanf("%d",&in_pass);
			if(in_pass==corr_pass){
				printf("Welcome Ayman");
			}else{
				printf("Incorrect Pass");
			}
			break;
		default:
			printf("Incorrect ID");
			break;
	}
	return 0;
}