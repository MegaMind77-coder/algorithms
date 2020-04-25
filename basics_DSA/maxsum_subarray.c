#include<stdio.h>

int sumtill(int arr[],int i){
    int j=0;
    int sum=0;
    for(j;j<i+1;j++){
        sum+=arr[j];
    }
    return sum;
}

int max_sum_subarray(int arr[],int n){
    int ans = 0,sum =0;
    int i=0;
    sum += arr[i];
    for(int j=1;j<n;j++){
        if(sum + arr[j] > 0){
            sum += arr[j];
        }
        else{
            sum = 0;
        }
        if(sum>ans){
            ans = sum;
        }
    }
    return ans;
}

int main()
{
    int arr[]={1,-3,2,-5,7,6,-1,-4,11,-23};
    int n = sizeof(arr)/sizeof(int);
    printf("%d",max_sum_subarray(arr,n));
    return 0;
}