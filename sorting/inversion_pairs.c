#include<stdio.h>

int overlap(int arr[],int i,int k,int j){
    int l=i;
    int r=k+1;
    int pairs = 0;
    int B[j-l+1];
    int p=0;
    while(l<=k && r<=j){
        if(arr[l]<=arr[r]){
            B[p++]=arr[l++];
            pairs += (r-(k+1));
        }
        else if(arr[l]>arr[r]){
            B[p++]=arr[r++];
           // pairs+=1;
        }
    }
    //printf("%d",pairs);
   if(l<=k){
       pairs = pairs + (k-l+1)*(j-k);
    }
    while(l<=k){
        B[p++] = arr[l++];
    }
    while(r<=j){
        B[p++] = arr[r++];
    }
    int x=0;
    for(i;i<j+1;i++){
        arr[i]=B[x++];
    }
   // printf("%d \n",pairs);
    return pairs;
}

int mergesort(int arr[],int i,int j){
    if(i<j){
        int k = (i+j)/2;
        return mergesort(arr,i,k)+mergesort(arr,k+1,j)+overlap(arr,i,k,j);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[]={1,4,5,2,6,9,8};
    int n = sizeof(arr)/sizeof(int);
    printf("%d",mergesort(arr,0,n-1));
    return 0;
}