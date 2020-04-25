#include<stdio.h>
#define MAX 1000000

void merge(int arr[],int i,int k,int j){
    //int n = sizeof(arr)/sizeof(int);
   // printf("%d %d\n",i,j);
    int l = i;
    int r = k+1;
    int B[j-i+1];
    int p = 0;
    while(l<=k && r<=j){
        if(arr[l]<=arr[r]){
            B[p] = arr[l];
            p++;
            l++;
        }
        if(arr[l]>arr[r]){
            B[p] = arr[r];
            p++;
            r++;
        }
    }
   // printf("%d %d\n",B[0],p);
    while(l<=k){
        B[p++] = arr[l++];
    }
    while(r<=j){
        B[p++] = arr[r++];
    }
    for(int y=0;y<j-i+1;y++){
     //   printf("%d\n",B[y]);
    }
    int x=0;
    for(i;i<j+1;i++){
        arr[i] = B[x++];
      //  printf("%d %d\n",B[i],arr[i]);
    }
 // printf("\n");
}

void mergesort(int arr[],int i,int j)
{
    if(i<j){
        int k = (i+j)/2;
        mergesort(arr,i,k);
        mergesort(arr,k+1,j);
        merge(arr,i,k,j);
    }
    else
    {
        return;
    }
}

int checksum(int arr[],int n,int x){
    int l = 0;
    int r = n-1;
    while(l<=r){
        if((arr[l]+arr[r])<x){
            l++;
        }
        else if(arr[l]+arr[r]>x){
            r--;
        }
        else if(arr[l]+arr[r]==x){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[MAX] = {5,6,33,7,9,10,11,46};
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    printf("%d",checksum(arr,n,44));
}