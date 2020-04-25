#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
void insert(struct node **head,int x)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=*head;
    *head = temp;
    //printf("%d\n",head->val);
}

void print(struct node *head,int n)
{
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp=head;
    for(int i=0;i<n;i++)
    {
        printf("%d\n",temp->val);
        temp=temp->next;
    }
}
void multiply(struct node *head1,struct node *head2,struct node **result,int na,int nb)
{
    for(int i=0;i<na;i++)
    {

    }
}*/

int main()
{
    int a[]={9,8,5,5,5};
    int b[]={1,2,3};
    int na = sizeof(a)/sizeof(int);
    int nb = sizeof(b)/sizeof(int);

    struct node *head1=(struct node *)malloc(sizeof(struct node));
    struct node *head2=(struct node *)malloc(sizeof(struct node));
    struct node *result = (struct node *)malloc(sizeof(struct node));
    head1=NULL;
    head2=NULL;
    
    for(int i=0;i<na;i++)
    {
        insert(&head1,a[i]);
    }
  //  print(head1,na);
    for(int j=0;j<nb;j++)
    {
        insert(&head2,b[j]);
    }

 return 0;   
}