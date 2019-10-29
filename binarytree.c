#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int flag;
	struct node *left,*right;
};
struct node *stack[20];
int top=-1;
void push( struct node *t)
{
	if(top==19)
		printf("\nStack overflow");
	else
		stack[++top]=t;
}
struct node *pop()
{
	if(top==-1)
	{
		printf("\nStack underflow");
	return NULL;
	}
	else
		return stack[top--];
}
struct node *create()
{
	struct node *t;
	int x;
	printf("\n Enter the data(-1 for null): ");
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	printf("\n Enter the left child of %d ",x);
	t->left=create();
	printf("\n Enter the right child of %d ",x);
	t->right=create();
	return t;
}
void inorder(struct node *root)
{
	struct node *t;
	t=root;
	printf("\n Inorder Format:\n");
	while(t!=NULL)
	{
		push(t);
		t=t->left;
	}
	while(top!=-1)
	{
		t=pop();
		printf("%d ",t->data);
		t=t->right;
		while(t!=NULL)
		{
			push(t);
			t=t->left;
		}
	}
	
}
void preorder(struct node *root)
{
struct node *t;
	t=root;
	printf("\n Pre order Format:\n");
	while(t!=NULL)
	{
		printf("%d ",t->data);
		push(t);
		t=t->left;
	}
	while(top!=-1)
	{
		t=pop();
		t=t->right;
		while(t!=NULL)
		{
			printf("%d ",t->data);
			push(t);
			t=t->left;
		}
	}
}
void postorder(struct node * t)         //postorder Traversal
{
  while(t!=NULL){
    t->flag=0;
    push(t);
    t=t->left;
  }
  while(top!=-1){
    t=pop();
    if(t->flag==1)
      printf("%d\t",t->data);
     else{
      t->flag=1;
      push(t);
      t=t->right;
      while(t!=NULL){
        t->flag=0;
        push(t);
        t=t->left;
      }
  }
}
}


void main()
{
	struct node *root;
	int x;
	do{
		printf("\n Enter 1 to create  \n Enter 4 to display inorder\n Enter 5 to display preorder \n Enter 6 to display postorder \n Enter 7 to Exit \n Enter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: root=create();
					break;
			case 4: inorder(root);
					break;
			case 5: preorder(root);
					break;
			case 6: postorder(root);
					break;
			case 7: printf("\n ------------Exitting menu---------------");
					break;
		}
	}while(x!=7);
}