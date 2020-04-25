#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

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

int head = 0;
int tail = 0;

void enqueue(struct node **q,struct node *x){
    q[tail] = x;
    tail+=1;
}

struct node *dequeue(struct node **q){
    head+=1;
    return q[head-1];
}

void level_order(struct node *root){
    struct node **q =(struct node **)malloc(sizeof(struct node *)*MAX);
    struct node *temp = root;
   // enqueue(q,temp);
    while(temp){
       // temp = dequeue(q);
        printf("%d ",temp->val);
        if(temp->left){
            enqueue(q,temp->left);
        }
        if(temp->right){
            enqueue(q,temp->right);
        }
        temp = dequeue(q);
    }
}

int main(){
    struct node *root = newnode(10); 
    root->left        = newnode(8); 
    root->right       = newnode(2); 
    root->left->left  = newnode(3); 
    root->left->right = newnode(5); 
    root->right->left = newnode(2);
    level_order(root);
    return 0;
}