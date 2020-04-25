#include<bits/stdc++.h>
#define MAX 100000
typedef long long ll;

using namespace std;

ll min_st[4*MAX];
ll max_st[4*MAX];

ll min(ll a, ll b){
    if(a>b){
        return b;
    }
    return a;
}

ll max(ll a, ll b){
    if(a>b){
        return a;
    }
    return b;
}
//builds a max and min segtree
void build_min_max_st(int node_idx,ll arr[], int s, int e){
    if(s == e){
        min_st[node_idx] = arr[s];
        max_st[node_idx] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    build_min_max_st(2*node_idx+1, arr, s, mid);
    build_min_max_st(2*node_idx+2, arr, mid+1, e );
    min_st[node_idx] = min(min_st[2*node_idx+1], min_st[2*node_idx+2]);
    max_st[node_idx] = max(max_st[2*node_idx+1], max_st[2*node_idx+2]);
}

//normal update function to update both data in both min and max segtree
void update(int idx, ll arr[], ll data, int node_idx, int s, int e){
    if(s == e){
        arr[idx] = data;
        min_st[node_idx] = data;
        max_st[node_idx] = data;
        return;
    }

    int mid = (s+e)/2;
    if(idx <= mid){
        update(idx, arr, data, 2*node_idx+1, s, mid);
    }
    else{
        update(idx, arr, data, 2*node_idx+2, mid+1, e);
    }

    min_st[node_idx] = min(min_st[2*node_idx+1], min_st[2*node_idx+2]);
    max_st[node_idx] = max(max_st[2*node_idx+1], max_st[2*node_idx+2]);
}

ll max_query(int node_idx, int s, int e, int l, int r){ //return max element between any two indexes
    if(l>e || r<s){
        return INT_MIN; //if invalid query we return the lowest value possible
    }
    if(s >= l && e<= r){
        return max_st[node_idx];
    }
    int mid = (s+e)/2;
    ll left = max_query(2*node_idx+1, s, mid, l , r); 
    ll right =  max_query(2*node_idx+2, mid+1, e, l, r);
    return max(left, right);
}

ll min_query(int node_idx, int s, int e, int l, int r){ //returns min element beween any two indexes
    if(l>e || r<s){
        return INT_MAX;
    }
    if(s>=l && e<=r){
        return min_st[node_idx];
        //printf("yo");
    }
    int mid = (s+e)/2;
    ll left = min_query(2*node_idx+1, s, mid, l , r);
    ll right =  min_query(2*node_idx+2, mid+1, e, l, r);
    return min(left, right);
}

bool checkfunc(ll arr[] ,int start_idx, int last_idx, ll c, int size){ 
    //this fnc checks if the particular subarray betwee the indexes satifies the property,
    ll min = min_query(0, 0, size-1, start_idx, last_idx);
    ll max = max_query(0, 0, size-1, start_idx, last_idx);
    if(arr[start_idx]-c<=min && arr[start_idx]+c>=max){ //if min and max of the subarray satisfy the poperty all elment in the subarray 
    //would
        return true;
    }
    return false; //else we retuen false
}

void query(ll arr[],int size, int x, ll c){

    if(c>=0){
        int l, r;
        l = x;
        r = size-1;
        int mid_idx;
        while(l<=r){//binary search for max length, till left and right pointer coincide
            mid_idx = (l+r)/2;
           // cout << mid_idx << "\n";
            bool i = checkfunc(arr, x, mid_idx, c, size);//checks if the the particular subarray satisfies the property 

            if(i && (mid_idx == size-1 || checkfunc(arr, x, mid_idx+1, c, size)== false)){//if the 
                break;
            }
            else if(i){ 
                l = mid_idx + 1;//it increases the left pointer, if prevoius subarray satisfies the poperty
                //thus incresing the lenth to be cheecked 
            }
            else{
                r = mid_idx - 1; //we reduce right pointer if i is false, to check for lesser length
            }
        }
        int max_len = mid_idx-x + 1;
        ll maximum =  max_query(0, 0, size-1, x, mid_idx);
        ll minimum =  min_query(0, 0, size-1, x, mid_idx);
        ll z = max(arr[x]-minimum, maximum-arr[x]);//z is the max value, or the worst case value of the c,the max value would satisfy the 
        //the propert for any element in the subarray
        printf("%d %lld\n",max_len, z);
    }
    else{
        printf("%d %d\n",-1,-1);
    }
}


//0(lognlogn) comlexity for the query function,
//logn to for check function and logn for BS , hence 0(lognlogn)
//log to cal z
int main(){
    int n, m;
    cin >> n >> m;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    build_min_max_st(0, arr, 0, n-1);
    char option;
    int x;
    ll y,c;
    while(m--){
        cin >> option;
        if(option == 'U'){
            cin >> x >> y;
            update(x-1, arr, y, 0, 0, n-1);
        }
        else{
            cin >> x >> c;
            query(arr, n, x-1, c);
        }
    }
    return 0;
}