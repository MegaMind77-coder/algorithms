#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};

void insert_at_tail(struct node **head,int x){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = x;
    new->next = NULL;
    new->prev = NULL;
    struct node *temp = *head;
    if(temp == NULL){
        *head = new;
        return;   
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void insert_at_head(struct node **head,int x){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = x;
    new->next = NULL;
    new->prev = NULL;
    struct node *temp = *head;
    if(temp == NULL){
       // printf("yes");
        *head = new;
        return ;
    }
    else{
        new->next = temp;
        temp->prev = new;
        *head = new;
    }
}

void print(struct node *head){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
}

void print_reverse(struct node *head){
    struct node *temp;
    temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp = temp->prev;
    }
}

int main()
{
    struct node *head = NULL;
    insert_at_head(&head,0);
   // printf("%d",head->val);
    insert_at_head(&head,1);   
      print(head);
  printf("\n");
    print_reverse(head);
   insert_at_tail(&head,2);
   //print(head);
   printf("\n");
   print(head);
    return 0;
}
