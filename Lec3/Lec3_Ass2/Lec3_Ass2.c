#include <stdio.h>

int main() {

    int in_ID, in_pass;
	int tr=3; //Initialize value of tries to have 3 tries
	
    printf("Please enter your ID: ");
    scanf("%d", &in_ID);

   switch(in_ID){
	   case 1234:
			printf("Please enter your password: ");
			while(tr){
				scanf("%d", &in_pass);
				if(in_pass == 7788){
					printf("Welcome Ahmed");
					break;
				}
				if(tr==1){break;}
				printf("Try Again: ");
				tr--;
			}
			break;
		case 5678:
			printf("Please enter your password: ");
			while(tr){
				scanf("%d", &in_pass);
				if(in_pass == 5566){
					printf("Welcome Amr");
					break;
				}
				if(tr==1){break;}
				printf("Try Again: ");
				tr--;
			}
			break;
		case 9870:
			printf("Please enter your password: ");
			while(tr){
				scanf("%d", &in_pass);
				if(in_pass == 1122){
					printf("Welcome Wael");
					break;
				}
				if(tr==1){break;}
				printf("Try Again: ");
				tr--;
			}
			break;
		default:
			printf("You are not Register");
			break;
   }
   if(tr ==1){
	   printf("Incorrect password for 3 times, No more tries");
   }
    return 0;
}
