#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node *newnode(int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int top = -1;

void push(struct node *stack[],struct node *x){
    top+=1;
    stack[top] = x;
}

void pop(struct node *stack[]){
    top-=1;
}


void preorder(struct node *root){
    struct node *stack[MAX];
    struct node *temp = root;
    if(temp){
        push(stack,temp);
        while(top>=0){
            printf("%d ",stack[top]->val);
            temp = stack[top--];
            if(temp->right){
                push(stack,temp->right);
            }
            if(temp->left){
                push(stack,temp->left);
            }
        }
    }
}

int main(){
    struct node *root = newnode(10); 
    root->left        = newnode(8); 
    root->right       = newnode(2); 
    root->left->left  = newnode(3); 
    root->left->right = newnode(5); 
    root->right->left = newnode(2); 
    preorder(root);
    return 0;
}