#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int arr[10];
	int f;
	int r;
}q;
void initialize()
{
	q.f=-1;
	q.r=-1;
	printf("\n Queue Initialized where front= %d rear= %d",q.f,q.r);
}
void insert(int ele)
{
	if(q.f==-1 && q.r==-1)
	{
		q.f=q.r=0;
		q.arr[q.r]=ele;
	}
	else if(q.r==9)
	{
		printf("\n Queue full");
	}
	else
	{
		q.r=q.r+1;
		q.arr[q.r]=ele;
	}
	
}
int delete()
{
	int x;
	if(q.f==-1 && q.r==-1)
	{
		printf("\n Queue empty");
		return NULL;
	}
	else if(q.f==q.r)
	{
		x=q.arr[q.f];
		q.f=-1;
		q.r=-1;
		return x;
	}
	else
	{
		x=q.arr[q.f];
		q.f=q.f+1;
		return x;
	}
}
void display()
{
	int i;
	if(q.f==-1 && q.r==-1)
	{
		printf("\n Queue empty");
	}
	else
	{
		printf("\n The Queue is ");
		for(i=q.f;i!=q.r;i=(i+1))
		{
			printf(" %d ",q.arr[i]);
		}
		printf(" %d ",q.arr[i]);
	}
}
void main()
{
	int ele,x,a;
	struct queue *q;
	do{
		printf("\n Enter 1 to initialize \n Enter 2 to insert \n Enter 3 to delete \n Enter 4 to display\n Enter 5 to exit \n Enter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:	initialize();
					break;
			case 2: printf("\n Enter the number to be inserted :");
					scanf("%d",&ele);
					insert(ele);
					break;
			case 3: a=delete();
					printf("\nThe deleted element is : %d",a);
					break;
			case 4: display();
					break;
			case 5 : printf("\n ------------Exitting menu---------------");
				break;
		}
	}while(x!=5);
}