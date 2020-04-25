#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
typedef long long int ll;

struct BST //normal struct of bst node 
{
  ll key;
  ll min;
  ll max;
  struct BST *left, *right;
};


struct BST *Queue[MAX]; //queue to store the pointer to node in bst
int front = 0; 
int rear = 0;
int size = 0;

void push(struct BST *new){ //function to add an element to the queue
  Queue[rear] = new;
  rear+=1;
  size+=1;
}
 //function to delete an element from the queue
void pop(){
  int del = front;
  front+=1;
  Queue[del] = NULL;
  size -=1;
}

struct BST *newNode (ll key) //returns pointer to newly created node 
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = NULL;
  temp->max = MAX; //min and max element set the range for the elements in the subtree so that we can decide whether the next elemnent lies
  //in the left or right subtree(of root node)while iterating
  temp->min = -MAX;
  return temp;
}

void Inorder (struct BST *node) //function to print inorder traversal 

{
  if (node)
    {
      Inorder (node->left);
      printf ("%lld  ", node->key);
      Inorder (node->right);
    }
}

struct BST *constructBST(ll arr[], ll n){ //function returns pointer to bst created from level order traversal 

  struct BST *root = NULL; //initializes root node to null
  if(n == 0){
    return root;
  }
  else
  {
    int idx = 0;
    struct BST *temp, *new;
    new = newNode(arr[idx]); //we add first element as root node
    idx+=1;
    push(new);// push it in the queue
    root = new;

    while (idx < n) //we iterate through the length of the array 
    {
      temp = Queue[front]; //we take the pointer in the front of the queue
      pop();

      if(idx < n && (arr[idx] < temp->key && arr[idx] > temp->min)){ //if next element in array is less than root node
      // and is greater than the minimum of of the range of elements in the subtree, we add it to the left subtree
      //basically it is lesser than the root node and greater than -infinity in first iteraion.

        new = newNode(arr[idx]);
        idx+=1;
        new->max = temp->key; // we change max value for the new elements range, to the value of parent node, so that only elements lesser than 
        //max value which is the value of parent node can lie in that subtree 

        new->min = temp->min;
        push(new); //push the newnode into the queue since it might be a parent for other elements
        temp->left = new;
      }
      //printf("%lld\n", Queue[1]->key);
      if(idx < n && (arr[idx] > temp->key && arr[idx] < temp->max )){
        //if greater than root node value and lesser than max value in right subtree, we add element to the right
        new = newNode(arr[idx]);
        idx+=1;
        new->max = temp->max;
        new->min = temp->key; // we change min value of new node to value of parent node
        //so that elements greater than parent can fall in the right subtree 

        push(new); //push the newnode into the queue since it might be a parent for other elements
        temp->right = new;
      }
    }

    return root;
  }
}

//complexity linear time 


int main ()
{
  struct BST *root = NULL;
  ll n;
  printf("Enter number of elements in level order array: ");
  scanf("%lld", &n);
  ll level_order_traversal[n];
  for(int i = 0;i<n; i++){
    printf("Enter data : ");
    scanf("%lld", &level_order_traversal[i]);
  }
  root = constructBST(level_order_traversal, n);
  Inorder(root);
  return 0;
}
