#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
    int l;
};

struct node *newnode(int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    new->l = 0;
    return new;
}

int main(){
    
    return 0;
}