#include<stdio.h>

int continuous_max(int arr[],int n){
    //int n = sizeof(arr)/sizeof(int);
    int i=0;
    int max = 0;
    int min = arr[i];
    for(int j=1;j<n;j++){
        if(arr[j-1]<min){
            min = arr[j-1];
        }
        if(max<arr[j]-min){
            max = arr[j] - min;
        }
    }
    return max;
}

int main()
{
    int arr[] = {1,6,4,100,24,50,198};
    int n = sizeof(arr)/sizeof(int);
    printf("%d",continuous_max(arr,n));
    return 0;
}