#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int row_op[4] = {-1, 1, 0, 0};
int col_op[4] = {0, 0, 1, -1};
int operations[4] = {'u', 'd', 'l', 'r'};

int main(){

    ll n, q;
    cin >> n >> q;
    vector <pair <ll, ll> > building(n);
    ll x, y;
    for(ll i = 0; i <n; i++){
        cin >> x >> y;
        building.push_back(make_pair(x, y));
    }

}