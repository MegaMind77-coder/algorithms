#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void build(int arr[],int *st,int node,int l,int r){
    if(l==r){
        st[node] = arr[l]; 
    }
    else{
        int mid = (l+r)/2;
        build(arr,st,2*node+1,l,mid);
        build(arr,st,2*node+2,mid+1,r);
        st[node] = st[2*node+1] + st[2*node+2];
    }
}

void update(int arr[],int *st,int node,int l,int r,int idx,int val){
    if(l==r){
        st[node] = val;
        arr[idx] = val;
       // return;
       // printf("hell yeah");  
    }
    else{
        int mid = (l+r)/2;
        if(l<=idx && idx <= mid){
            update(arr,st,2*node+1,l,mid,idx,val);
        }
        else{
            update(arr,st,2*node+2,mid+1,r,idx,val);
        }
        st[node] = st[2*node+1] + st[2*node+2];
    }
}

int RangeSumQuery(int arr[],int *st,int node,int l,int r,int i,int j){
    if(i<=l && r<=j){
        return st[node];     
    }
    if(i>r || j<l){
        return 0;
    }
    int mid = (l+r)/2;
    int sum_l = RangeSumQuery(arr,st,2*node+1,l,mid,i,j);
    int sum_r = RangeSumQuery(arr,st,2*node+2,mid+1,r,i,j);
    return sum_l+sum_r;
}

int main()
{   
    int arr[]={1,3,-2,8,-7};
    int n = sizeof(arr)/sizeof(int);
    int *st = (int *)malloc(4*MAX*sizeof(int));
    build(arr,st,0,0,n-1);
    for(int i=0;i<2*n-1;i++){
        printf("%d ",st[i]);
    }
    printf("\n%d",RangeSumQuery(arr,st,0,0,n-1,3,4));
    return 0;
}