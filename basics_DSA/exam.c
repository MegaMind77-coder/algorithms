#include<stdio.h>
#define MAX 10000
int differbyone(int arr[],int l,int n){
    int count = 0;
  //  int i=0;
 //   int j=0;
    for(int i=0;i<=n-l;i++){
        int min = arr[i];
        int max = arr[i];
        int j = i ;
        //if(j-i+1>=l && j==i){
       //     count+=1;
       // }
        while(j<n){
            if(arr[j]<min){
                min = arr[j];
            }
            if(arr[j]>max){
                max = arr[j];
            }

            if(max - min == j-i && j-i+1>=l){
                count+=1;
            }
            j++;
        }
    }
    return count;
}

int main()
{
    int arr[MAX];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int l;
    scanf("%d",&l);
    printf("%d",differbyone(arr,l,n));    
}