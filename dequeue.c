#include<stdio.h>
#include<stdlib.h>
struct dequeue
{
	int arr[10];
	int f;
	int r;
}dq;
void insert_rear(int ele)
{
	if(dq.f==-1 && dq.r==-1)
	{
		dq.f=dq.r=0;
		dq.arr[dq.r]=ele;
	}
	else if (dq.f==(dq.r+1)%10)
		printf("\n Queue full");
	else
	{
		dq.r=(dq.r+1)%10;									//dq.r=(dq.r+1)%size;
		dq.arr[dq.r]=ele;
	}
}
int remove_rear()
{
	int x;
	if(dq.f==-1 && dq.r==-1)
	{
		printf("\n Queue empty");
		return NULL;
	}
	else if(dq.f==(dq.r))
	{
		x=dq.arr[dq.r];
		dq.f=dq.r=-1;
		return x;
	}
	else
	{
		x=dq.arr[dq.r];
		dq.r=(dq.r-1)%10;				//dq.r=(dq.r-1)%size;
		return x;
	}
}
void display()
{int i;
	if(dq.f==-1 && dq.r==-1)
	{
			printf("\n Queue empty");
	}
	else
	{
		for(i=dq.f;i!=dq.r;i=(i+1)%10)
		{
			printf(" %d ",dq.arr[i]);
		}
		printf(" %d ",dq.arr[i]);
	}
}
void initialize()
{
	dq.f=-1;
	dq.r=-1;
	printf("\n Queue Initialized where front= %d rear= %d",dq.f,dq.r);
}
void insert_front(int ele)
{
	if(dq.f==-1 && dq.r==-1)
	{
		dq.f=dq.f=0;
		dq.arr[dq.f]=ele;
	}
	else if (dq.f==(dq.r+1))
	{
		printf("\n Queue full");
	}
	else
	{
		dq.f=(dq.f-1+10)%10;                            //dq.f=(dq.f-1+size)%size;
		dq.arr[dq.f]=ele;                                 
		
	}
}
int remove_front()
{
  int x;
   if(dq.f==dq.r && dq.r==-1)
	{ 
		printf("q is empty\n" );
	}
		else if(dq.f==dq.r)
	{
		x=dq.arr[dq.f];
		dq.f=-1;
		dq.r=-1;
		return (x);
	}
	else
	{
	x=dq.arr[dq.f];
	dq.f=(dq.f+1)%10;						//dq.f=(dq.f+1)%size;
	return(x);
	}

  }
void main()
{
	int ele,x,a;
	struct queue *q;
	do{
		printf("\n Enter 1 to insert at rear \n Enter 2 to remove from rear \n Enter 3 to display\n Enter 4 to initialize \n Enter 5 to insert at front \n Enter 6 to delete from front\n 7 to exit \n Enter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:printf("\n Enter the number to be inserted :");
					scanf("%d",&ele);
					insert_rear(ele);
					break;
			case 2: a=remove_rear();
					printf("\n The element deleted from rear is : %d",a);
					break;
			case 3:display();
					break;
			case 4:	initialize();
					break;
			case 5: printf("\n Enter the number to be inserted :");
					scanf("%d",&ele);
					insert_front(ele);
					break;
			case 6: a=remove_front();
					printf("\n The element deleted from front is : %d",a);
					break;		
					
			case 7 : printf("\n ------------Exitting menu---------------");
				break;
		}
	}while(x!=7);
}