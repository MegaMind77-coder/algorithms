#include<stdio.h>
#define max 1000000
int main()
{
    int arr[]={-1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int prefix_sum[n+1];
    prefix_sum[0] = 0;
    for(int i=1;i<n+1;i++){
        prefix_sum[i]=prefix_sum[i-1]+arr[i-1];
    }

    int k=0;
    int maxima =0;
    int imax = 0;
    int jmax = 1;
    for(int j=1; j<n+1 ; j++){
        if(maxima < prefix_sum[j]-prefix_sum[k]){
            maxima  = prefix_sum[j]-prefix_sum[k];
            jmax=j;
            imax=k;
        }
        if(prefix_sum[j]-prefix_sum[k]<0){
            k = j;
        }
    }
    if(jmax=n){
        jmax=n-1;
    }

    printf("%d between %d and %d " , maxima,imax,jmax);
}