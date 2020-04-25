#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define max 1000007

struct node {
    int val;
    struct node *next;
};

void insert(struct node **head,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = value;
    new->next =  NULL;
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
    }
}

void print(struct node *head){
	struct node *temp;
	temp = head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp = temp->next;
	}
	printf("\n");
}
int lenexists(char *str1,char *str2,int l){
   int exists = -1;
   int len_str1 = strlen(str1);
   int len_str2 = strlen(str2);
   
   int p = 2;
   struct node *hashtable[max];
   for(int i=0;i<len_str1-l+1;i++){
       int sum = (str1[i]-'0');
       for(int j=i+1;j<l+i;j++){
          sum = (2*sum + (str1[j]-'0'))%max;
       }
	 //  printf("%d",sum);
		 if(sum<0){
			 sum+=max;
		 }
		// printf("%d\n",sum);
		 insert(&hashtable[sum],i);
		// print(hashtable[sum]);
   }
    
	int a = (str2[0]-'0');
	for(int i=1;i<l;i++){
       a = (2*a + (str2[i]-'0'))%max;
	}
	if(a<0){
		a+=max;
	}
  //	printf("%d",a);
	if(hashtable[a]!=NULL){
		struct node *temp = hashtable[a];
		//printf("yo");
		while(temp!=NULL){
			int j=0;
			for(int i=temp->val;i<l+temp->val;i++){
              if(str1[i]!=str2[j]){
					  break;
				  }
				  j+=1;
			}
			//printf("\n%d",j);
			if(j==l){
				exists+=1;
				return exists;
				break;
			}
			temp=temp->next;
		}
	}
	for(int i=1;i<len_str2-l;i++){
		a = (2*a+(str2[i+l-1]-'0')-((int)pow(2,l)*(str2[i-1]-'0')))%max;
		if(a<0){
			a+=max;
		}
		if(hashtable[a]!=NULL){
			struct node *t = hashtable[a];
			while(t!=NULL){
			int j=0;
			for(int i=t->val;i<l+t->val;i++){
              if(str1[i]!=str2[j]){
					  break;
				  }
				  j+=1;
			}
			if(j==l){
				exists+=1;
				return exists;
				break;
			}
			t=t->next;
		}
		}
	}
   return exists;
}

int binarysearch(char *str1,char *str2)
{
   int l=0;
	int r=MIN(strlen(str1),strlen(str2));
	while(l<=r){
		int mid = l + (r-l)/2;
		if(lenexists(str1,str2,mid)==0)
		{
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return l-1;
}



int main()
{
    char *str1 = "10010101";
    char *str2 = "1001111";
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
	//printf("%ld",MIN(strlen(str1),strlen(str2)));
   //printf("%d",lenexists(str1,str2,8));
   printf("%d",binarysearch(str1,str2));
    return 0;
}