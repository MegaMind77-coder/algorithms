#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
    //printf("%d",a);
}

int partition(int A[],int i,int j,int a){
    int l = i;
    int r = j;
    while(l<=r){
        while(l<=r && A[l]<=a)
            l++;
        while(l<=r && A[r]>a)
            r--;
        if(l<=r){
            swap(&A[l],&A[r]);
            l++;
            r--;
        }
    }
    swap(&A[i],&A[l-1]);
    return l-1;
}


int findelementbyrank(int A[],int i,int j,int r){
    time_t t;
    srand((unsigned) time(&t));
    if(i<j){
        int pivot = rand() % (j-i+1) + i;
        swap(&A[pivot],&A[i]);
        int k = partition(A,i,j,A[i]);
        if(r == j-k+1){
            return A[k];
        }
        else if(r<j-k+1){
            return findelementbyrank(A,k+1,j,r);
        }
        else{
            return findelementbyrank(A,i,k-1,r-j+k-1);
        }
    }
    return -1;
}

int main()
{
    int arr[]={6,7,3,4,5,1,0,2,3};
    int n = sizeof(arr)/sizeof(int);
    printf("%d\n",findelementbyrank(arr,0,n-1,3));
    return 0;
}