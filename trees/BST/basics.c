#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = data;
    new->left =  NULL;
    new->right = NULL;
    return new;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        return newnode(data);
    }

    if(data < root->val){
        root-> left = insert(root->left, data);
    }
    else if(data > root->val){
        root-> right = insert(root->right, data);
    }
    
    return root;
}

struct node *search(struct node *root,int data){
    if(root->val == data || root == NULL){
        return root;
    }
    if(root->val < data){
        //printf("%d ",root->val);
        return search(root->right,data);
    }
    return search(root->left, data);
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

struct node *delete(struct node *root,int data){
        if(root == NULL){
            return root;
        }
        if(data < root->val){
            root->left = delete(root->left,data);
        }
        else if(data > root->val){
            root->right = delete(root->right,data);
        }
        else{
            if(root->left == NULL){
                struct node *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                struct node *temp = root->left;
                free(root);
                return temp;
            }
            struct node *cur = root->left;
            while(cur && cur->right!=NULL){
                cur = cur->right;
            }
            root->val = cur->val;
            root->left = delete(root->left,cur->val);
        }
        return root;
}



int main()
{
    struct node *root = NULL;
    root =  insert(root,50);
    insert(root, 30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    
   // preorder(root);
    //struct node *s = search(root, 90);
 //   inorder(root);
  //  delete(root,30);
   struct node *s = search(root, 30);
   printf("%d",  s->val);
    //inorder(root);
}