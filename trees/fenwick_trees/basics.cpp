#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

void update(int idx,int change,int *BIT,int size){
   // cout << BIT[idx] << "\t";
    for(;idx<=size; idx+=(idx & (-idx))){
        BIT[idx] += change;
    }
}

void build(int arr[],int *BIT,int n){
    for(int i=0;i<n+1;i++){
       // int change = arr[i] - BIT[i];
        update(i,arr[i],BIT,n);
    }
}

int Sum_till_index(int *BIT,int idx,int n){
    int sum = 0;
    for(;idx>0;idx -= (idx&(-idx))){
        sum += BIT[idx];
    //    cout << "ssup";
    }
    return sum;
}

int main(){
    int arr[] = {0,4,-3,2,-1,-2,6,-3,7,4};
    int n = sizeof(arr)/sizeof(int);
    int BIT[10000];
    for(int i=0;i<n;i++){
        BIT[i] = 0;
    }
   // update(1,arr[1],BIT,n);
   //                    update(2,arr[2],BIT,n);
   // build(arr,BIT,n);
    for(int i=1;i<n;i++){
        update(i,arr[i],BIT,n); //building the fenwick_tree 
   }
   //for(int i=0;i<n;i++){
     //  cout << BIT[i] << " ";
  // }
   cout << Sum_till_index(BIT,3,n);
    return 0;
}