#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#define max 100003

struct node
{
    int val;
    struct node *next;  
};

void insert(struct node **head,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = value;
    new->next = NULL;
    struct node *temp=(*head);
   // printf("%d\n",new->val);
    if(temp==NULL){
        (*head)=new;
        printf("yo\n");
        return;
    }
    *head = new;
}

int stringmatch(char *text,char *pattern,int startindex){
    int match = 1;
    int i=0;
    for(i;i<strlen(pattern);i++){
        if(text[startindex+i]!=pattern[i])
            break;
    }
    if(i==strlen(pattern)){
        match-=1;
        return match;
    }
    else{
        return match;
    }
}

int main()
{
    char *text="111011101111011101111011101111000111011101111011101111011101111";
    char *patterns[100] = {
        "111011101111011101111011101111",
        "011101111011101111011101111000",
    };
    int max = pow(10,5)+7;
    int m=pow(10,6);
    struct node *hashtable[1000000];
    for(int i=0; i<2; i++)
    {
        int N = (patterns[i][0]-'0');
        int len_pat = strlen(patterns[i]);

        for(int j = 1; j<len_pat; j++)
        {
            N = (2*N + (patterns[i][j]-'0'))%max;
        }
        if(N<0){
            N+=max;
        }

        printf("%d\n",N);
        hashtable[N]=(struct node *)malloc(sizeof(struct node *));
        insert(&hashtable[N],i);      
    }

    int len_text=strlen(text);
    int len = strlen(patterns[0]);
    int p=2;
    int a = (text[0]-'0');
    for(int i=1;i<len;i++){
        a = (2*a + (text[i]-'0'))%max;
        p*=2;
    }
    printf("%d\n",a);
    if(hashtable[a]!=NULL){
        //printf("%s",patterns[hashtable[a]->val]);
        if(stringmatch(text,patterns[hashtable[a]->val],0)==0){
             printf("pattern %s found at %d\n",patterns[hashtable[a]->val],0);
        }
    }
    for(int i=1;i<len_text-len+1;i++){
            a = (2*a+(text[i+len-1]-'0')-(p*(text[i-1]-'0')))%max;
            if(a<0){
                a+=max;
            }
            if(hashtable[a]!=NULL){
                if(stringmatch(text,patterns[hashtable[a]->val],i)==0){
                    printf("pattern %s found at %d\n",patterns[hashtable[a]->val],i);
                }
            }
    }
    return 0;
}