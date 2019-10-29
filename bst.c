#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

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
        printf("%d \t",root->data);
        inorder(root->right);
    }
}

struct node * insert(struct node * root){

    if(root==NULL){
        root=createnode();
        puts("Enter data");
        scanf("%d",&root->data);
    }
    else{
        puts("Enter data");
        struct node * newnode = createnode();
        scanf("%d",&newnode->data);
        struct node *p=root,*q;

        while(p!=NULL){
            q=p;
            if(newnode->data < p->data)
                p=p->left;
            else
                p=p->right;
        }

        if(newnode->data < q->data)
            q->left=newnode;
        else
            q->right=newnode;
    }

  return root;
}

int search(struct node * root, int ele){

    if(root==NULL){
        puts("Empty tree");
        return 0;
      }
    else{
        int flag=0;
        struct node * p=root;

        while(p!=NULL){
            if(p->data == ele){
                flag = 1;
                break;
            }
            else if(ele < p->data)
                p=p->left;
            else
                p=p->right;
        }
        if(flag==1)
            return 1;
        else
            return 0;
    }

}

struct node * delete(struct node * root, int ele){

    if(!search(root,ele))
        return root;
    else{
        struct node *p=root,*q;

        int flag=0;
        while(p!=NULL){
            if(p->data == ele){
                flag=1;
                break;
            }
            q=p;
            if(ele < p->data)
                p=p->left;
            else
                p=p->right;
        }

        if(flag==1){
              if(p->left==NULL && p->right==NULL){
                  //case 1:leaf node
                  if(p == q->left)
                      q->left=NULL;
                  else
                      q->right=NULL;
                  free(p);
                }
              else if(p->left!=NULL && p->right==NULL){
                  //case 2: Left subtree
                  if(p==q->left)
                      q->left=p->left;
                  else
                      q->right=p->left;
                  free(p);
                }
              else if(p->right!=NULL && p->left==NULL){
                  //case 3: Right subtree
                  if(p==q->left)
                      q->left=p->right;
                  else
                      q->right=p->right;
                  free(p);
                }
              else{
                  //case 4:Both subtrees
                  q=p;
                  p=p->right;
                  while(p->left!=NULL)
                      p=p->left;
                  int x = p->data;
                  delete(root,p->data);
                  q->data=x;
              }
        }

        return root;
    }

}


void main(){

    int choice,s,res;
    struct node * root=NULL;
    do{
      puts("\n1: Insert\n2: Search\n3: Delete\n4: Inorder\n5: Exit");
      scanf("%d",&choice);

      switch (choice) {
        case 1:
              root=insert(root);
              break;
        case 2:
              puts("Ele to be searched:");
              scanf("%d",&s);
              res=search(root,s);
              if(res)
                  puts("Found");
              else
                  puts("Not found");
              break;
        case 3:
              puts("Ele to be deleted:");
              scanf("%d",&s);
              root=delete(root,s);
              break;
        case 4:
              puts("Inorder traversal:");
              inorder(root);
              break;
        case 5:
              puts("ok");
              break;
        default:
                puts("Invalid");
      }

    }while(choice!=5);

}