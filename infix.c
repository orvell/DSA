#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x)
{
	stack[++top]=x;
}
char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
int prec(char x)
{
	if(x=='(')
		return 0;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
}
void main()
{
	char infix[20],postfix[20];
	char x;
	int i,k=0;
	printf("\nEnter the Expression");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			postfix[k++]=infix[i];
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while((x=pop())!='(')
			{
				postfix[k++]=x;
			}
			
		}
		else
		{
			while(prec(stack[top])>=prec(infix[i])&& top!=-1)
			{
				postfix[k++]=pop();
			}
		
		push(infix[i]);
		}
	}
	while(top!=-1)
	{
		postfix[k++]=pop();	
	}
	postfix[k]='\0';
	//for(i=0;postfix[i]!='\0';i++)
		printf("%s",postfix);
}