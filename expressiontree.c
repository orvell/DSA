#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node * left;
    struct node * right;
};

struct node * stack[20];
int top=-1;

struct node * createnode(){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c \t",root->data);
        inorder(root->right);
    }
}

void push(struct node * t){

    if(top==19)
        puts("Full");
    else
        stack[++top]=t;

}

struct node * pop(){
    if(top==-1)
        return NULL;
    else
        return stack[top--];
}

struct node * expressiontree(char postfix[]){

    struct node * t;
    int i=0;
    while(i<strlen(postfix)){

        if(isalnum(postfix[i])){
            t = createnode();
            t->data=postfix[i];
            push(t);
        }
        else{
            t = createnode();
            t->data=postfix[i];
            t->right=pop();
            t->left=pop();
            push(t);
        }

        i++;
    }
  t=pop();

  return t;
}

void main(){

    char postfix[20];
    struct node * root;
    printf("Enter the postfix eqn.\n");
    gets(postfix);
    root=expressiontree(postfix);
    inorder(root);

}