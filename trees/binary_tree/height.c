#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
    int h;
};

struct node *newnode(int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    new->h = 0;
    return new;
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int height(struct node *root){
    if(root == NULL){
        return -1;
    }
    else{
        root->h = max(height(root->left),height(root->right)) + 1;
        return root->h;
    }
}

int main(){
    struct node *root = newnode(10); 
    root->left        = newnode(8); 
    root->right       = newnode(2); 
    root->left->left  = newnode(3); 
    root->left->right = newnode(5); 
    root->right->left = newnode(2);
    printf("%d ",height(root));
    printf("%d",root->right->h);
    return 0;
}