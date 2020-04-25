#include<stdio.h>
#include<stdlib.h>

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
//keep adding nodes wherever , no limit since not an array only dynamic
int main(){

    struct node *root = newnode(1);
    printf("%d ",root->val);
    root->left = newnode(2);
    root->right = newnode(3);
    printf("%d",(root->left)->val);
    return 0;
}