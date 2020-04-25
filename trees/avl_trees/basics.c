#include<stdio.h>
#include<stdlib.h>

int max_val(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}


struct node
{
    int val;
    struct node *left;
    struct node *right;
    int height;
};

struct node *NewNode(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->val = data;
    new->left = NULL;
    new->right = NULL;
    new->height = 0;

    return new;
}

int height(struct node* node){
    if(node){
        return node->height;
    }
    return 0;
}


struct node *leftrotate(struct node *x){
    struct node *oldroot = x;
    struct node *newroot = oldroot->right;

    oldroot->right = newroot->left;
    newroot->left = oldroot;

    oldroot->height = max_val(height(oldroot->left),height(oldroot->right)) + 1;
    newroot->height = max_val(height(newroot->left),height(newroot->right)) + 1;

    return newroot;
}

struct node *rightrotate(struct node *y){
    struct node *oldroot = y;
    struct node *newroot = oldroot->left;

    oldroot->left = newroot->right;
    newroot->right = oldroot;

    oldroot->height = max_val(height(oldroot->left),height(oldroot->right)) + 1;
    newroot->height = max_val(height(newroot->left),height(newroot->right)) + 1;

    return newroot;
}



int new_balance(struct node *node){
    if(node == NULL){
        return 0;
    }
    return height(node->left)-height(node->right);    
}

struct node *insert(struct node *root,int data){
    if(root == NULL){
        root = NewNode(data);
        return root;
    }
    else if(data < root->val){
        root->left = insert(root->left, data);
    }
    else if(data > root->val){
        root->right = insert(root->right,data);
    }
    else{
        return root;
    }


    root->height = max_val(height(root->left), height(root->right)) + 1;
    int balance = new_balance(root);
    if(balance > 1 && data<root->left->val){
        rightrotate(root);
    }

    if(balance < -1 && data > root->right->val){
        leftrotate(root);
    }

    if(balance > 1 && data > root->left->val){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if(balance < -1 && data < root->right->val){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}




int main(){
    struct node *root = NULL;
    root = insert(root, 10); 
    //printf("%d",root->val);
    root = insert(root, 20);
    printf("%d ",height(root));
    root = insert(root, 30);
    printf("%d ",height(root));
    //printf("%d",root->right->val);
   // root = insert(root, 40);
    return 0;
}
