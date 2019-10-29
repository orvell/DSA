#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  int data;
  int priority;
  struct node * next;
};

struct node * create(){

    struct node * tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->next=NULL;
    printf("Enter data \n");
    scanf("%d",&tmp->data);
    printf("Enter its priority\n");
    scanf("%d",&tmp->priority);

    return tmp;
}

struct node * enqueue(struct node * head){

    struct node *tmp,*tmp1,*newnode;

    if(head==NULL)
        head=create();

    else{

        tmp=head;
        newnode=create();

        if(head->priority < newnode->priority){
            newnode->next=head;
            head=newnode;
        }else{
            while(tmp->next!=NULL && tmp->next->priority >= newnode->priority)
                tmp=tmp->next;
            newnode->next = tmp->next;
            tmp->next = newnode;
        }

    }

  return head;
}

struct node * dequeue(struct node * head){

    if(head==NULL)
        puts("Queue Empty");
    else{
        struct node * tmp;
        tmp=head;
        head=head->next;
        printf("Removed Element : %d",tmp->data);
        tmp->next=NULL;
        free(tmp);
    }

  return head;
}

void display(struct node * head){

    while(head!=NULL){
        printf("%d \t",head->data);
        head=head->next;
    }
}

void main(){

    struct node * head=NULL;
    int choice;

    do{

      puts("\n 1 : Enqueue \n 2 : Dequeue \n 3 : Display Queue \n 4 : Exit.");
      scanf("%d",&choice);

      switch (choice) {
        case 1:
              head=enqueue(head);
              break;
        case 2:
              head=dequeue(head);
              break;
        case 3:
              display(head);
              break;
        case 4:
              puts("Exiting the menu.");
              break;
        default:
              puts("Invalid choice.");
      }

    }while(choice!=4);

}