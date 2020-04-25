#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int i,int j,int p){
    int l=i;
    int r=j;
    while(l<=r){
        while(arr[l]<=p){
            l++;
        }
        while(arr[r]>p){
            r--;
        }
        if(l<=r){
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
    swap(&arr[i-1],&arr[l-1]);
    return l-1;
}

void quicksort(int arr[],int i,int j){
    time_t t;
    srand((unsigned) time(&t));
    if(i<j){
        int pivot = rand()%(j-i+1) + i;
        
        swap(&arr[i],&arr[pivot]);
        int p = partition(arr,i+1,j,arr[i]);
        quicksort(arr,i,p-1);
        quicksort(arr,p+1,j);
    }
}

int main()
{
    int arr[]={2,0,1,9,5,8,3,4,7};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}