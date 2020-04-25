#include<stdio.h>
#include<stdlib.h>

void BuildSegmentTree(int arr[],int *st,int n){
    for(int i=0;i<n;i++){
        st[n+i-1] = 1;
        //printf("%d ",st)
    }
    for(int i=n-2;i>=0;i--){
        st[i] = st[2*i+1] + st[2*i+2];
    }
}

void update(int arr[],int size,int *st,int i,int x){
        arr[i] = x;
     //   printf("huhudhue");
       // i = (int)(sizeof(arr)/sizeof(int) + i-2)/2;
       st[size-1+i-1] = x;
        i = ((size - 1 + i - 1)/2)-1;
       // int flag = 0;
        while (i>=0)
        {
            st[i] = st[2*i+1] + st[2*i+2];
            if(i<1)
                break;
            i = (i)/2;
        }
}

int query(int *st,int p,int s,int e,int num){
    if(st[p]<num){
        return -1;
    }
    if(s == e){
        if(st[p] == num-1){
            return s;
        }
        else{
            return -1;
        }
    }
    int m = (s+e)/2;
    if(num<=st[2*p+1])
    {
        return query(st,2*p+1,s,m,num);
    }
    else
    {
        return query(st,2*p+2,m+1,e,num-st[2*p+1]);
    }
    
}

int main(){
    int size;
    scanf("%d",&size);
    int arr[size+1];
    for(int i=0;i<size;i++){
        arr[i] = 1;
    }
    arr[size] = 1000;
    int *SegTree = (int *)malloc((2*size-1)*sizeof(int));
    BuildSegmentTree(arr,SegTree,size);

    int q;
    scanf("%d",&q);
    int op,k;
    while(q--){
        scanf("%d %d",&op,&k);
        if(op==1){
            printf("%d\n",query(SegTree,0,0,size-1,k));
        }
        else{
            update(arr,size,SegTree,k,0);
        }
    }
}