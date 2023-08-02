# include<stdio.h>


int main(){
	int x=10;
	int y=20;
	int z=30;
	int* p=&x;
	int* q=&y;
	int* r=&z;
	printf("x: %d\ny: %d\nz: %d\np: %x\nq: %x\nr: %x\n*p: %d\n*q: %d\n*r: %d\n",x,y,z,p,q,r,*p,*q,*r);
	printf("Swapping Pointers\n");
	int * temp=r;
	r=p;
	p=q;
	q=temp;
	printf("x: %d\ny: %d\nz: %d\np: %x\nq: %x\nr: %x\n*p: %d\n*q: %d\n*r: %d\n",x,y,z,p,q,r,*p,*q,*r);
	return 0;
	
}