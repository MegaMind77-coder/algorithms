#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *next;
};
void print(struct node **head)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t=*head;
    while(t->next!=NULL)
    {
        printf("%d",t->val);
        t=t->next;
    }
}
void insert(struct node **head,int value)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->val=value;
    t->next=*head;
    *head = t;
}
void add(struct node **result,struct node **head1,struct node **head2,int na,int nb)
{
    
        struct node *temp1,*temp2;
        temp1=(struct node *)malloc(sizeof(struct node));
        temp2=(struct node *)malloc(sizeof(struct node));
        struct node *swap=(struct node*)malloc(sizeof(struct node));
        temp1=*head1;
        temp2=*head2;
        int sum;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            sum=0;
            sum=temp1->val+temp2->val+carry;
            insert(result,sum%10);
            carry=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
        
        }
        if(na>nb)
        {
            temp2=temp1;
        }
             while(temp2!=NULL){
                sum=0;
                sum=temp2->val+carry;
                insert(result,sum%10);
                carry=sum/10;
                temp2=temp2->next;
            }

        
        if(carry>0){
            insert(result,carry);
        }  
}
int main() {
    int a[]={1,2,3};
    int b[]={2,3,};
    int na=sizeof(a)/sizeof(int);
    int nb=sizeof(b)/sizeof(int);
    struct node *head1=(struct node*)malloc(sizeof(struct node));
    struct node *head2=(struct node*)malloc(sizeof(struct node));
    struct node *result = (struct node*)malloc(sizeof(struct node));
    head1->val=a[0];
    head1->next=NULL;
    head2->val=b[0];
    head2->next=NULL;
    
    for(int i=1;i<na;i++)
    {
        insert(&head1,a[i]);

    }

    for(int i=1;i<nb;i++)
    {
        insert(&head2,b[i]);
    }

    add(&result,&head1,&head2,na,nb);
    print(&result);
    return 0;
}