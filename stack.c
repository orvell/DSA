#include<stdio.h>
#include<stdlib.h>
char stack[5];
int top=-1;
void push( int x)
{
	if(top==4)
		printf("\nStack overflow");
	else
		stack[++top]=x;
}
int pop()
{
	if(top==-1)
		printf("\nStack underflow");
	else
		return stack[top--];
}
int stacktop()
{
	if(top==-1)
		printf("\nStack underflow");
	else
		return stack[top];
}
void display()
{
	int i;
	if(top==-1)
		printf("\nStack underflow");
	else
	{
		printf("The stack is \n");
		for(i=top;i>=0;i--)
		printf("%d\n",(int)stack[i]);	
	}
}
void main()
{
	int x,ele;
	do
	{
	printf("\n Enter 1 to push \n Enter 2 to pop \n Enter 3 for stacktop \n Enter 4 to display \n Enter 5 to Exit \n Enter your choice : ");
	scanf("%d",&x);
		switch(x)
		{
		case 1: printf("\n Enter the number to be pushed :");
				scanf("%d",&ele);
				push(ele);
				break;
		case 2: ele=pop();
				printf("\n The popped element is : %d",ele);
				break;
		case 3: ele=stacktop();
				printf("\n The stacktop is : %d",ele);
				break;	
		case 4:display();
				break;
		case 5 : printf("\n ------------Exitting menu---------------");
				break;
				
		}
	}while(x!=5);
}