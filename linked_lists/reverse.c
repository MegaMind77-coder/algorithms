#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};

//void reverse(struct node **head,int n)
void print(struct node *head){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
}

void insert_at_head(struct node **head,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
//    struct node *temp;
//    temp = *head;
    new->val = value;
    new->next = *head;
    *head = new;
}


void reverse(struct node **head){
    struct node *temp1,*temp2;
    temp1 = *head;
    temp2 =  temp1->next;
    temp1->next = NULL;
    while(temp2!=NULL){
        insert_at_head(&temp1,temp2->val);
        temp2 = temp2->next;
    }
    *head = temp1;
   // printf("%d",temp1->val);
}

int main()
{
    int n,value;//number of nodes
    scanf("%d",&n);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&value);
    head->val = value;
    head->next = NULL;
    struct node *temp,*new;
    temp = head;
    for(int i=1;i<n;i++){
        scanf("%d",&value);
        new = (struct node *)malloc(sizeof(struct node));
        new->val = value;
        new->next = NULL;
        temp->next = new;
        temp = new;
   }
 //  print(head);
   reverse(&head);
   print(head);

   return 0;
}