#include <stdio.h>
#include <stdlib.h>
struct node//this is the structure for node of the linked list  
{
    int val;//stores the value of the node           
    struct node *next;//member stores the address of the next node 
}*first;//first is a pointer to a 'node' structure 
void traverse()//this function is to traverse the linked list starting from the first node and prints the output 
{
    struct node *temp;//temp is the pointer to a node structure and is used to traverse the linked list 
    temp = first;//temp starts from the first node 
    while(temp != NULL)//the loop continues till pointer of the last node points to NULL
    {
        printf("%d-->", temp->val);//prints val linked to a particular node 
        temp = temp->next;//pointer then points to the address of the next node               
    }
    printf("NULL\n");//prints 'NULL' at the end 
}
void delodd()//this function removes nodes that contains odd values 
{
    struct node *temp;
    struct node *prev;//stores the address of previous node to temp
    temp = first; 
    while (first != NULL && (first->val)%2!=0)//checks if the first node matches the condition,if so it frees the memory that stores the address of the first node 
    {
        prev = first;
        first = first->next;
        free(prev);//frees memory stored for first
    }
    prev = NULL;
    temp  = first;
    while (temp != NULL)//pointer moves until 'next' points to NULL 
    {
        if ((temp->val)%2!=0)//if the condition is matched 
        {
            {
                prev->next = temp->next;//next of prev stores the address in next of temp
            }
            free(temp);
            temp = prev->next;
        } 
        else
        {
            prev = temp;// prev then stores temp 
            temp = temp->next;//moves to next node 
        }        
    }
}
int main()
{
    int n;
    scanf("%d", &n);//stores the number of nodes 
    struct node *new, *temp;
    int val;
    first = (struct node *)malloc(sizeof(struct node));//creates the first node 
    scanf("%d", &val);//takes input of val stored in first node 
    first->val = val;//val is stored in 'val' member of  first 
    first->next = NULL;//next temprorily points to NULL    
    temp = first;//links the temporary node to new 
    for(int i=2; i<=n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &val);//takes input for val
        new->val = val; 
        new->next = NULL; 	
        temp->next = new;//links the temporary node to new  
        temp = temp->next;//temp then moves to the next node     
    }
    traverse();//prints the linked list
    delodd();//deletes nodes storing odd values 
    traverse();//prints the linked list
    return 0;
}



		 
