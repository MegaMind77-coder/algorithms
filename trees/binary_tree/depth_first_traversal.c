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

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    printf("%d ",root->val);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

int main(){

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}