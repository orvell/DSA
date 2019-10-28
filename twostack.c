#include<stdio.h>
int stack[20];
int top1=-1,top2=20;
void push(int ele,int stackno)
{
	if(top2-top1==1)
		printf("\n Stack overflow");
	else if (stackno==1)
	{
		stack[++top1]=ele;
	}
	else if (stackno==2)
	{
		stack[--top2]=ele;
	}
	else
	{
		printf("\n Ïnvalid stack number");
	}
}

void pop(int stackno)
{
	if(stackno==1)
	{
		if(top1==-1)
			printf("stack underflow");
		else
		{
			printf("\n The popped element of stack 1 is : %d",stack[top1--]);
		}
	}
	else if(stackno==2)
	{
		if(top2==20)
			printf("stack underflow");
		else
		{
			printf("\n The popped element of stack 2 is : %d",stack[top2++]);
		}
	}
	else
	{
		printf("\n Ïnvalid stack number");
	}
}

void display(int stackno)
{
	int i;
	if(stackno==1)
		{
		if(top1==-1)
			printf("stack empty");
		else
		{	printf("\n Stack 1 is :\n");
			for(i=top1;i>=0;i--)
				printf("%d\n",stack[i]);
		}
	}
	else if(stackno==2)
	{
		if(top2==20)
			printf("stack Empty");
		else
		{
			printf("\n Stack 2 is :\n");
			for(i=top2;i<20;i++)
				printf("%d\n",stack[i]);
		}
	}
	else
	{
		printf("\n Ïnvalid stack number");
	}
}
void main()
{
	int x,ele,sn;
	do{
		printf("\n Enter 1 to push \n Enter 2 to pop \n Enter 3 to display \n Enter 4 to Exit \n Enter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
		case 1: printf("\n Enter the number to be pushed :");
				scanf("%d",&ele);
				printf("\n Enter the stack number :");
				scanf("%d",&sn);
				push(ele,sn);
				break;
		case 2: printf("\n Enter the stack number :");
				scanf("%d",&sn);
				pop(sn);
				break;
		case 3:	printf("\n Enter the stack number :");
				scanf("%d",&sn);
				display(sn);
				break;
		case 4 : printf("\n ------------Exitting menu---------------");
				break;
				
		}
	}while(x!=4);
}