#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void BuildMinSegmentTree(int arr[],int *st,int n){
    for(int i=0;i<n;i++){
        st[n+i-1] = i;
        //printf("%d ",st)
    }
    for(int i=n-2;i>=0;i--){
        if(arr[st[2*i+1]]>arr[st[2*i+2]]){
            st[i] = st[2*i+2];
        }
        else{
            st[i] = st[2*i+1];
        }
    }
}

void BuildMaxSegmentTree(int arr[],int *st,int n){
    for(int i=0;i<n;i++){
        st[n+i-1] = i;
    }
   for(int i=n-2;i>=0;i--){
        if(arr[st[2*i+1]]<arr[st[2*i+2]]){
            st[i] = st[2*i+2];   
        }
        else{
            st[i] = st[2*i+1];
        }
    }
}

void update(int arr[],int size,int *st,int i,int x){
        arr[i] = x;
     //   printf("huhudhue");
       // i = (int)(sizeof(arr)/sizeof(int) + i-2)/2;
        i = ((size - 1 + i - 1)/2);
        int flag = 0;
        while (i>=0)
        {
            if(arr[st[2*i+1]]<arr[st[2*i+2]]){
                st[i] = st[2*i+1];
            }
            else{
                st[i] = st[2*i+2];
            }
            if(i<1)
                break;
            i = (i-1)/2;
        }
}

int rmq1(int arr[],int *st,int i,int j,int s,int e,int p,int size){
    
    if(j<s || i>e){
        return size;
    }
    else if(i<=s && e<=j){
        return st[p];
    }
    int m = (s+e)/2;
    int l1 = rmq1(arr,st,i,j,s,m,2*p+1,size);
    int l2 = rmq1(arr,st,i,j,m+1,e,2*p+2,size);
    if(arr[l1]<arr[l2]){
        return l1;
    }
    else{
        return l2;
    }
}

int RangeMinQuery(int arr[],int *st,int i,int j,int n){
    return rmq1(arr,st,i,j,0,n-1,0,n);
}

int NextRightMin(int arr[],int i,int *st,int n){
   // int n = sizeof(arr)/sizeof(int);
    int p=0,s=0;
    int e = n-1;
    int j = n;
    while(p<n-1){
        int m = (s+e)/2;
        if(i<=m){
            if(arr[st[p+2]]<arr[i]){
                j = 2*p+2;
            }
            p = 2*p+1;
            s = 0;
            e = m;
        }
        else{
            p = 2*p+2;
            s = m + 1;
        }
    }
    while(j<n-1){
        if(arr[st[2*j+1]]<arr[i]){
            j = 2*j + 1;
        }
        else{
            j   = 2*j + 2;
        }
    }
    return j;
}

int main()
{
    int A[]={4,7,3,2,8,12,1,16,10000};
    int size = 8;
    int *SegTree = malloc((2*size-1)*sizeof(int));
    BuildMinSegmentTree(A,SegTree,size);    
   // printf("\n%d",RangeMinQuery(A,SegTree,2,5,size));
   printf("%d",NextRightMin(A,0,SegTree,8));
    return 0;
}