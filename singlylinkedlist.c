#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *insert(struct node *head)
{
	int ele;
	struct node *temp;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the number to be inserted :");
	scanf("%d",&ele);
	if(head==NULL)
	{
		
		newnode->next=NULL;
		newnode->data=ele;
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
		newnode->data=ele;
		
	}
	return head;
}
int delete()
{
	struct node *temp,*temp1;
	 if(head!=NULL)
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		free(temp);
		printf("\n ----------------The element is deleted----------------");
	}
	else
		printf("\n The linked list is empty");
		
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\n The linked list is empty");
	}
	else if(head!=NULL)
	{
		
		while(temp->next!=NULL)
		{
			printf(" %d\t",temp->data);
			temp=temp->next;
		}
		printf(" %d\t",temp->data);
	}
}
struct node *reverse_ll(struct node *head)
{
	struct node *prev=NULL;
	struct node *current=head;
	struct node *next=NULL;
	while(current->next!=NULL)
	{
		next=current->next;
		current->next = prev; 
		 prev = current; 
        current = next; 
	}
	next=current->next;
		current->next = prev; 
		 prev = current; 
        current = next; 
	head=prev;
	printf("\n The linked list is reversed");
	return head;
	
}
struct node *insert_specific_location(struct node *head,int pos)
{
	int i;
	int ele;
	struct node *temp;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the number to be inserted :");
	scanf("%d",&ele);
	if(head==NULL)
	{
		
		newnode->next=NULL;
		newnode->data=ele;
		head=newnode;
	}
	else
	{
	
	
	temp=head;
	for(i=1;i<pos-1;i++)
	{
			temp=temp->next;
	}
	newnode->data=ele;
	newnode->next=temp->next;
	temp->next=newnode;
	}
	printf("\n The linked list is inserted");
	return head;
}
struct node *delete_specific_location(struct node *head,int pos)
{
	struct node *temp,*temp1;
	int i;
	 if(head!=NULL)
	{
		temp=head;
		for(i=1;i<pos;i++)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=temp->next;
		temp->next=NULL;
		free(temp);
		printf("\n ----------------The element is deleted----------------");
	}
	else
		printf("\n The linked list is empty");
		
}	
struct node *copy(struct node *head)
{
	struct node *temp,*temp1,*head1=NULL;
	temp=head;
	head1=(struct node *)malloc(sizeof(struct node));
	temp1=head1;
	temp1->data=temp->data;
	while(temp->next!=NULL)
	{
		temp1->next=(struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		temp1=temp1->next;
		temp1->data=temp->data;
	}
	temp1->next=NULL;
	printf("\n The linked list is copied");
	return head1;
}

int size()
{
	struct node *temp,*i;
	temp=head;
	int c;
	c=1;
	for(i=head;i->next!=NULL;i=i->next)
	{
		temp=temp->next;
		c++;
	}
	
	return c;

}

struct node *split(struct node *head)
{
	struct node *temp,*head2;
	int i=1,pos;
	temp=head;
	printf("\nAt which location do u want to split : ");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
		
		
	}
	head2=temp->next;
	temp->next=NULL;
	printf("\n The linked list is split");
	return head2;
}
void main()
{
	struct node *head1,*head2;
	int x,a,pos;
	do{
		printf("\n Enter 1 to insert\n Enter 2 to delete\n Enter 3 to display\n Enter 4 to reverse_ll\n Enter 5 to insert_specific_location\n Enter 6 to delete_specific_location\n Enter 7 to copy linked list to another linked list\n Enter 8 to split\n Enter 9 to Exit\n Enter Your Choice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
					head=insert(head);
					break;
			case 2: delete(head);
					
					break;
			case 3: display(head);
			a=size();
			printf("\n                  %d",a);
					break;
			case 4:	head=reverse_ll(head);
					break;
			case 5: printf("\nAt which location do u want to insert : ");
					scanf("%d",&pos);
					head=insert_specific_location(head,pos);
					break;
			case 6: printf("\nAt which location do u want to delete : ");
					scanf("%d",&pos);
					delete_specific_location(head,pos);
					break;
			case 7: head1=copy(head);
					printf("\n The original linkedlist is :");
					display(head);
					printf("\n The copied linkedlist is :");
					display(head1);
			case 8: head2=split(head);
					printf("\n The splitted linkedlist is :");
					printf("\n linkedlist 1 is :");
					display(head);
					printf("\n linkedlist 2 is :");
					display(head2);
					break;
			case 9: printf("\n ------------Exitting menu---------------");
					break;
		}
	}while(x!=9);
}