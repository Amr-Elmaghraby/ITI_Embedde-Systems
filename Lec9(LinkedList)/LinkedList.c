#include <stdio.h>
#include<stdlib.h>
#include "STD_Type.h"
#define Null (void*)0x00

typedef struct node{
	s32 data ;
	struct node* Next ;
}node;

/*node* Linked_List(node* LL){
	LL->head = Null;
	return LL;
}*/
void AddNode(node** h_ptr,s32 val){
	node* current = * h_ptr;
	if(current==Null){
		current = (node*) malloc(sizeof(node));
		current -> data = val;
		current -> Next = Null;
		* h_ptr = current;
	}
	else{
		node * temp = (node*) malloc(sizeof(node));
		while(current->Next != Null){
			current = current-> Next; 
		}
		current -> Next  = temp;
		temp-> data = val;
		temp-> Next = Null;
	}
}

void DeleteNode(node ** h_ptr,s32 del){
	node * current = *h_ptr;
	node * prv = Null;
	while(current!=Null){
		if(current -> data == del){
			if(prv ==Null){
				*h_ptr = (*h_ptr) ->Next;
			}
			else{
				prv->Next = current->Next;
			}
			node* tmp = current;
			current = current ->Next;
			free(tmp);
		}
		else{
			prv = current;
			current = current ->Next;
			}
	}
}

void InsertNode(node ** h_ptr,s32 val,u32 idx){
	node* current = * h_ptr;
	if(idx==0){
		current = (node*) malloc(sizeof(node));
		current -> data = val;
		current -> Next = *h_ptr;
		* h_ptr = current;
		}
	else{
		for(u32 i=0;i<idx-1;i++){
			current = current -> Next;}
		node * ins = (node*) malloc(sizeof(node));
		node * temp = (node*) malloc(sizeof(node));
		temp = current -> Next;
		current -> Next  = ins;
		ins-> data = val;
		ins-> Next = temp;
	}
}


void PrintLinkedList(node* head){
	s16 n_d=1;
	printf("-------------------\n");
	node* current = head;
	while(current !=Null){
		printf("Node Number %hu = %d\n",n_d,current->data);
		current = current->Next;
		n_d ++;
	}
	if(n_d==1){printf("List Is Empty\n");}
	printf("-------------------\n\n\n");
}

s16 main(){
	/*node* LL=Null;
	LL=Linked_List(LL);*/
	node* head = Null;
	s32 inp;
	u32 size=0;
	while(1){
		printf("To Add Node Enter 0\n");
		printf("To Print The Linked List Enter 1\n");
		printf("To Exit Press 2\n");
		printf("To Delete Val From LL Enter 5\n");
		printf("To Insert Val To LL Enter 6\n");
		printf("=====> ");
		scanf("%d",&inp);
		if(inp==2){
			printf("Your Choice: %d\n",inp);
			printf("Thank You\nGood Bye\n");
			break;}
		s32 Data;
		u32 idx;
		switch (inp){
			case 0:
				printf("Your Choice %d\n",inp);
				printf("Please Enter Node Value: ");
				scanf("%d",&Data);
				AddNode(&head,Data);
				size++;
				break;
			case 1:
				PrintLinkedList(head);
				break;
			case 5:
				printf("Please Enter Value to Delete from LL: ");
				scanf("%d",&Data);
				DeleteNode(&head,Data);
				break;
			case 6:
				printf("Please Enter Value to Insert To the LL: ");
				scanf("%d",&Data);
				printf("Please Insert Index to add at: ");
				scanf("%d",&idx);
				if(idx<size)
				{   InsertNode(&head,Data,idx);
					size++;}
				else
					printf("Size of LL can't be Smaller than Input Idx\n");
				break;
			default:
				printf("Your Choice: %d",inp);
				printf("Invalid Choice Please Try Again\n");
				break;
		}

	}
	return 0;
} 