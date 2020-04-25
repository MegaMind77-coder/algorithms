#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
typedef long long int ll;

//the idea here is to use two avl trees one to store the elements, along with their index as paramter 
//eg: index of 2 is 1, so node->idx for 2 = 1
//another avl tree only for the indexes only, we create a balances binary search tree, and then mintain the tree using avl functions
//for the given array indexes 0 1 2 3 4 5 are added to the index BBST , this is done in linear time
//a loop is executed to delete the min element in the array avl tree, until the total nodes are zero
// for each iteration we find the index of the min element, and then find the number of nodes ahead of it in 0(logn)
//using the index bbst(this is done in a very similar manner as the rank function, we just don't initailize it to 1)
//thus we find the number of indexes(undeletes) which are greater than index of min
//after finding this, we delete the min element and the index respectively
//rotaion is done to ensure height is 0(logn)
//since each iteration performs function of 0(height)
//n iteratiuons result in nlog operations 
//hence 0(nlogn) solution


//intitial count value for array avl tree is 0, since it is not required'
//initial count value of idx_bst nodes are one, since required to find elements to the right


struct BST //normal avl tree node with new struct element idx
{
  int key;
  int idx;//stores index of element in the given array
  int height;
  int count;
  struct BST *left, *right;
};

struct BST *newNode (int key, int count, int idx) 
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->idx = idx;
  temp->left = temp->right = NULL;
  temp->height = 0;
  temp->count = count;
  return temp;
}

int Max (int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int Height (struct BST *node)
{
  if (node)
    {
        if (node->left && node->right){
            return 1 + Max (node->left->height, node->right->height);
        }
        else if (node->left){
            return 1 + node->left->height;
        }
        else if (node->right){
            return 1 + node->right->height;
        }
        else{
            return 0;
        }
    }
    else{
        return -1;
    }
}

int Count (struct BST *node)
{
  if (node)
    {
      if (node->left && node->right)
      {
    	return 1 + node->left->count + node->right->count;
      }
      else if (node->left){
	    return 1 + node->left->count;
      }
      else if (node->right){
    	return 1 + node->right->count;
      }
      else{
	    return 1;
      }
    }
  else
    return 0;
}

bool AVL (struct BST * node)
{
  if (abs (Height (node->left) - Height (node->right)) < 2){
      return true;
  }
  else{
      return false;
  }
}

void Inorder (struct BST *node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("%d  ", node->key);
      Inorder (node->right);
    }
}

struct BST *Rotate (struct BST *Z)
{
    struct BST *X, *Y, *T1, *T2, *T3, *T4;
    int c = 0;
    if (Height (Z->left) + 1 == Z->height){
        Y = Z->left;
    }
    else
    {
        Y = Z->right;
        c++;
    }
    c = c * 2;
    if (Height (Y->left) + 1 == Y->height){
        X = Y->left;
    }
    else{
        X = Y->right;
        c++;
    }
    if (c == 0){
        T3 = Y->right;
        Y->right = Z;
        Z->left = T3;
        Z->height = Height (Z);
        X->height = Height (X);
        Y->height = Height (Y);
        Z->count = Count (Z);
        X->count = Count (X);
        Y->count = Count (Y);
        return Y;

    }
    else if (c == 3){
        T2 = Y->left;
        Y->left = Z;
        Z->right = T2;
        Z->height = Height (Z);
        X->height = Height (X);
        Y->height = Height (Y);
        Z->count = Count (Z);
        X->count = Count (X);
        Y->count = Count (Y);
        return Y;
    }
    else if (c == 1){

        T2 = X->left;
        T3 = X->right;
        Y->right = T2;
        Z->left = T3;
        X->left = Y;
        X->right = Z;

        Z->height = Height (Z);
        Y->height = Height (Y);
        X->height = Height (X);
        Z->count = Count (Z);
        Y->count = Count (Y);
        X->count = Count (X);
        return X;
    }
    else{
        T2 = X->left;
        T3 = X->right;
        Y->left = T3;
        Z->right = T2;
        X->left = Z;
        X->right = Y;
        Z->height = Height (Z);
        Y->height = Height (Y);
        X->height = Height (X);
        Z->count = Count (Z);
        Y->count = Count (Y);
        X->count = Count (X);
        return X;
    }
}

struct BST *Insert (struct BST *node, int key, int idx)
{
  if (!node){
    return newNode(key, 0, idx);
  }
  if (key < node->key){
    node->left = Insert (node->left, key, idx);
  }
  else if (key > node->key){
    node->right = Insert (node->right, key, idx);
  }
  node->height = Height (node);
  node->count = Count (node);
  if (!AVL (node)){
      node = Rotate (node);
    }
  return node;
}

struct BST *Delete (struct BST *node, int X)
{
    if (!node){
        return node;
    }
    if (node->key > X)
    {
      node->left = Delete (node->left, X);
      node->height = Height (node);
      node->count = Count (node);
      if (!AVL (node)){
        node = Rotate (node);
      }
      return node;
    }
    else if (node->key < X)
    {
      node->right = Delete (node->right, X);
      node->height = Height (node);
      node->count = Count (node);
      if (!AVL (node)){
        node = Rotate (node);
      }
      return node;
    }
    if (node->left && node->right)
    {
      struct BST *temp = node->left;
      while (temp->right){
          temp = temp->right;
      }
      node->key = temp->key;
      node->left = Delete (node->left, temp->key);
    }
    else
    {
      struct BST *child;
      if (node->left){
          child = node->left;
      }
      else{
          child = node->right;
      }
      free (node);
      return child;
    }
}


//my functions


int min_idx(struct BST *root){ //utility function to return index of min element in the array
    struct BST *temp = root;
    if(temp){
        if(temp->left){
            temp = temp->left;
            while(temp->left){
                temp = temp->left;
            }
            return temp->idx;
        }
        else{
            return temp->idx;
        }
    }
    else{
        return -1;
    }
}

int min_key(struct BST *root){ //utility function to return min element in the array
    struct BST *temp = root;
    if(temp){
        if(temp->left){
            temp = temp->left;
            while(temp->left){
                temp = temp->left;
            }
            return temp->key;
        }
        else{
            return temp->key;
        }
    }
    else{
        return -1;
    }
}
struct BST *create_idx_BBST(int idx_arr[], int l, int r){ //function creates the BBST for indexes
    struct BST *node = NULL;
    if(l <= r){
        int mid = (l+r)/2;
        node = newNode(idx_arr[mid], 1, 0);
        node->left = create_idx_BBST(idx_arr, l, mid-1);
        node->right = create_idx_BBST(idx_arr, mid+1, r);
        node->height = Height(node); //in each recursion height and count value are update to allow use of avl functions
        node->count = Count(node);
    }
    return node;
}

int count_right(struct BST *node, int X){ //function return number of index  to right of chosen index
    int num_right = 0;
    while(node){
        if(X == node->key){
            if(node->right){
                num_right += node->right->count;
            }
            return num_right;
        }
        else if (X < node->key)
        {
            num_right+=1;
            if(node->right){
                num_right += node->right->count;
            }
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return num_right;
}

int total_cost(struct BST **root, struct BST **idx_root, int size){ //function to calculate total cost
    int del_idx, min_element, num_right;
    int total_cost = 0;
    while(size--){
        del_idx = min_idx(*root);
        min_element = min_key(*root);
        *root = Delete(*root, min_element);
        total_cost += count_right(*idx_root, del_idx);
        *idx_root = Delete(*idx_root, del_idx);
    }
    return total_cost;
}

int main ()
{
    int i, n;
    struct BST *root = NULL;
    printf("Enter size of array:");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter data : ");
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; ++i){
        root = Insert (root, arr[i], i);
    }
   
    int idx_arr[n];
    for(int i=0;i<n;i++){
        idx_arr[i] = i;
    }
    struct BST *idx_bst = NULL;
    idx_bst = create_idx_BBST(idx_arr, 0, n-1);
    printf("%d", total_cost(&root, &idx_bst, n));
    return 0;
}
