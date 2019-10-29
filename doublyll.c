#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * createnode(){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct node * insert_end(struct node * head, int data){

    if(head==NULL){
        head=createnode();
        head->data=data;
    }
    else{
        struct node * tmp=head,* newnode;
        while(tmp->next!=NULL)
            tmp=tmp->next;

        newnode=createnode();
        newnode->data=data;
        tmp->next=newnode;
        newnode->prev=tmp;
    }
  return head;
}

struct node * insert_front(struct node * head, int data){

    if(head==NULL){
        head=createnode();
        head->data=data;
    }
    else{
        struct node * newnode;
        newnode=createnode();
        newnode->data=data;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
  return head;
}

struct node * insert_posi(struct node * head, int data, int posi){

    if(head==NULL){
        head=createnode();
        head->data=data;
    }
    else{
        struct node * temp=head;
        struct node * newnode=createnode();
        newnode->data=data;

        int i=1;
        while(i<posi-1){
            if(temp->next!=NULL)
                temp=temp->next;
            i++;
        }

        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;

    }
  return head;
}

struct node * remove_front(struct node * head){

    if(head==NULL)
        return NULL;
    else{

        struct node * temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        printf("\nRemoved : %d \n",temp->data);
        free(temp);
    }
  return head;
}

struct node * remove_end(struct node * head){

    if(head==NULL)
        return NULL;
    else{

        struct node * temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        struct node * temp1=temp;
        temp=temp->prev;
        temp->next=NULL;
        temp1->prev=NULL;
        printf("\nRemoved : %d \n",temp1->data);
        free(temp1);
    }
  return head;
}

struct node * remove_posi(struct node * head, int posi){

    if(head==NULL)
        return NULL;
    else{
        struct node * temp=head;
        int i=1;

        while(i<posi){
            temp=temp->next;
            i++;
        }
        struct node * temp1=temp->prev;
        temp1->next=temp->next;
        temp->next->prev=temp1;
        temp->prev=NULL;
        temp->next=NULL;
        printf("\nRemoved : %d \n",temp->data);
        free(temp);
    }
  return head;
}

void display(struct node * head){

    if(head==NULL)
        return;
    else{
        struct node * temp;
        temp=head;
        while(temp!=NULL){
            printf("%d \t",temp->data);
            temp=temp->next;
        }
    }
}

void main(){
    struct node * head=NULL;
    int choice,data,posi;

    do{
        puts("\n1: Insert End\n2: Remove End\n3: Insert Front\n4: Remove Front\n5: Insert Posi\n6: Remove Posi\n7: Display\n8: Exit");
        scanf("%d",&choice);

        switch (choice) {
          case 1:
                puts("Enter data");
                scanf("%d",&data);
                head=insert_end(head,data);
                display(head);
                break;
          case 2:
                head=remove_end(head);
                display(head);
                break;
          case 3:
                puts("Enter data");
                scanf("%d",&data);
                head=insert_front(head,data);
                display(head);
                break;
          case 4:
                head=remove_front(head);
                display(head);
                break;
          case 5:
                puts("Enter data & posi");
                scanf("%d",&data);
                scanf("%d",&posi);
                head=insert_posi(head,data,posi);
                display(head);
                break;
          case 6:
                puts("posi");
                scanf("%d",&posi);
                head=remove_posi(head,posi);
                display(head);
                break;
          case 7:
                display(head);
                break;
          case 8:
                puts("Bye");
                break;
          default:
                puts("Invalid choice");
        }
    }while(choice!=8);
}