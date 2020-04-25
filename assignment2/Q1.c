#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100000

//in this question we need to create a balance binary search tree from two bsts

struct node //struct of node of bst 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
struct stack // struct of node of stack
{ 
    struct node *element; 
    struct stack *next; 
}; 

int mergedarr[MAX];// a global array that stores the 
int idx = 0;

void push(struct stack **top, struct node *k) //function to push an element in to stack, it pushes it at the bottom of stack, that
// is near the head element
{ 
    struct stack *new = (struct stack *) malloc(sizeof(struct stack)); //creating a stack element
   
    new->element = k; //stores pointer to node of the bst
    new->next = *top; // makes new element point to the top before adding  
    (*top) = new; //makes the pointer to top, point at the new element
} 


struct node *pop(struct stack **top) //pops an element out of a stack, returns the pointer to the popped node
{ 
    struct  node *del; 
    struct stack *st; //deleted stack element
    st = *top; 
    (*top) = (*top)->next; // makes top point to the previous element
    del = st->element; // stores the node element(in the deleted stack element) to be returned
    free(st); 
    return del; //return node element deleted
} 
  
bool isEmpty(struct stack *top) 
{ 
    if (top == NULL ) 
        return true; 
  
    return false; 
} 

struct node* newNode (int data) 
{ 
    struct node *temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  

struct node *insert(struct node *root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root-> left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node *root) //inorder traversal, used when either of the bsts is empty
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        mergedarr[idx] = root->data; //stores each element of the non empty bst in an array in sorted order
        idx+=1; 
        inorder(root->right); 
    } 
} 

struct node *CreateBBST(int l, int r){
     //function to create a balanced binary search tree given a sorted array
    struct node *node = NULL;
    if(l <= r){
        int mid = (l+r)/2;
        node = newNode(mergedarr[mid]);
        node->left = CreateBBST(l, mid-1);
        node->right = CreateBBST(mid+1, r);
    }
    return node;
}
  
struct node *merge(struct node *root1, struct node *root2) 
{ 
    struct stack *s1 = NULL;  // stack for first bst
    struct node  *temp1 = root1; 
    struct stack *s2 = NULL;  //stack for 2nd bst
    struct node  *temp2 = root2; 
  
    if (root1 == NULL) // if first bst is empty, we still take the inorder of 2nd bst
    { 
        inorder(root2); 
        return CreateBBST(0, idx-1); 
    } 

    if (root2 == NULL) // if 2nd bst is empty, take inorder of first bst
    { 
        inorder(root1); 
        return CreateBBST(0, idx-1); 
    }  

    int y=0;
    while (temp1 != NULL || !isEmpty(s1) || temp2 != NULL || !isEmpty(s2)) //loop will continue till both pointers do not reach null
    // and both the stacks are empty

    // the idea is to visit each node in both bsts once, puch all left nodes into their respective stacks
    { 
        if (temp1 != NULL || temp2 != NULL ) 
        { 
            if (temp1 != NULL) 
            { 
                push(&s1, temp1);  
                temp1 = temp1->left; //keep moving to left till you encounter a null in bst1
            } 
            if (temp2 != NULL) 
            { 
                push(&s2, temp2); 
                temp2 = temp2->left; //keep moving to left till null is reached in bst2 
            }
        } 
        else
        { 
            if (isEmpty(s1))  //if bst1 has finished, we perform inorder on remainign elements from bst2 
            {  
                while (!isEmpty(s2)) 
                { 
                    temp2 = pop (&s2); 
                    temp2->left = NULL; 
                    inorder(temp2); 
                } 
                //printf("%d", idx);
                return CreateBBST(0, idx-1); 
            } 
            if (isEmpty(s2))  //if bst2 has finished, we perform inorder on remainign elements from bst1 
            { 
               
                while (!isEmpty(s1)) 
                { 
                    temp1 = pop (&s1); 
                    temp1->left = NULL; 
                    inorder(temp1); 
                } 
                return CreateBBST(0, idx-1); 
            } 
            temp1 = pop(&s1); 
            temp2 = pop(&s2); 

            if (temp1->data < temp2->data) //compares left most elements
            { 
                mergedarr[idx] = temp1->data; //stores min element in it
                idx+=1;
                temp1 = temp1->right; //goes to the right checks for other elements in next iterartion it finds all the elements
                //that are successor of the root node at which we stopped
                push(&s2, temp2); 
                temp2 = NULL; 
            } 
            else
            { 
                mergedarr[idx] = temp2->data;
                idx+=1;
                temp2 = temp2->right; 
                push(&s1, temp1); 
                temp1 = NULL; 
            } 
        } 
    }
    return CreateBBST(0, idx-1); // if the loop ends it would mean that we have a valid sorted array containing nodes of the two bsts
    // so we create a bst in order(n)
} 

//time complexity for creating a valid sorted array 0(n+n) assuming both the bsts contain n nodes each
//time complexity for creating a bbst frm the array is 0(n+n) (where n+n is the length of the merged array )
// hence total complexity is 0(n)

void printInorder(struct node *root){
    if(root){
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() 
{ 
    struct node  *root1 = NULL, *root2 = NULL; 


   //printInorder(newBBST);
    int num_nodes;
    printf("Enter number of nodes of first bst : ");
    scanf("%d", &num_nodes);
    
    int data;
    for(int i=0; i<num_nodes; i++){
        printf("Enter data for bst : ");
        scanf("%d", &data);
        root1 = insert(root1, data);
    }
    
    printf("Enter number of nodes of second bst : ");
    scanf("%d", &num_nodes);
    
    for(int i=0; i<num_nodes; i++){
        printf("Enter data for bst : ");
        scanf("%d", &data);
        root2 = insert(root2, data);
    }
    
    struct node *new_BBST = merge(root1, root2);
    printInorder(new_BBST);
    return 0; 
} 
