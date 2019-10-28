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
void main()
{
	char postfix[20];
	int i,res;
	int x;
	char op1,op2;
	printf("\nEnter the Postfix Expression for evaluation ");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isalnum(postfix[i]))
		{
			push(postfix[i]-'0');
		}
		else 
		{
			op1=pop();
			op2=pop();
			switch(postfix[i])
			{
				case '+':res=(int)op1+(int)op2;
							break;
				case '-':res=(int)op1-(int)op2;
						break;
				case '*':res=(int)op1*(int)op2;
						break;
				case '/':res=(int)op1/(int)op2;
					break;
			}
			push(res);
		}
	}
	x=pop();
	printf("\n The ans is %d",x);
}
	