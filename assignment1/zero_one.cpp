#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

int segtree[4*MAX];

void build_segtree(int node_idx, int s, int e){ // recursive function to build seg tree, we store the number of ones between any two indexes in the 
//segtree 
    if(s == e){
        segtree[node_idx] = 1; 
        return;
    }
    int mid = (s+e)/2;
    build_segtree( 2*node_idx+1, s, mid); 
    build_segtree( 2*node_idx+2, mid+1, e);
    segtree[node_idx] = segtree[2*node_idx+1] + segtree[2*node_idx+2]; //stores number of ones between the tow indexes as the value of segtree
}

void update(int arr[], int idx, int node_idx, int s, int e){
    if(s == e){
        arr[idx] = 0; //changes corresponding value in the array
        segtree[node_idx] = 0; //reaches the corresponding index in the array
        return;
    }
    int mid = (s+e)/2; 
    if(idx <=  mid){
        update(arr, idx, 2*node_idx+1, s, mid); //goes to the left incase the index lies on the left
    }
    else{
        update(arr, idx, 2*node_idx+2, mid+1, e);
    }
    segtree[node_idx] = segtree[2*node_idx+1] + segtree[2*node_idx+2];//goes to the right incase the index lies on the right

}

int query(int k, int s, int e, int size, int node_idx){ //this query calculates the inex of the kth one
    if(k > segtree[node_idx]){ //if nmber ones asked greater than the total number of ones return -1
        return -1;
    }
    if(s == e && k == 1){ //if s and e are equal it reaches a leaf node, and if it is the last required one the corresponding idx is 
    //returned
        return s; //return index
    }
    int mid = (s+e)/2;
    if(k<= segtree[2*node_idx+1]){ //we go to the left and search for k, if lesser than left element
       return query(k ,s, mid, size, 2*node_idx+1);
    }
    else{
       return query(k-segtree[2*node_idx+1], mid+1, e, size, 2*node_idx+2); //if greater than k, we go to the right and subtract ones of the left
    }
}

int main(){
    int n,k,q;
    int option;
    cin >> n;
    cin >> q;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = 1;
    }
    build_segtree(0, 0, n-1);
    int i;
    while(q--){
        cin >> option;
        if(option == 0){
            cin >> i;
            update(arr, i-1, 0, 0, n-1);
        }
        else{
            cin >> k;
            int x = query(k,0,n-1,n,0);
            if(x == -1){
                cout << -1 << '\n';
            }
            else{
            cout << x +1 << '\n';
            }
        }
    }
    return 0;
}

//0(logn) solution using segtrees