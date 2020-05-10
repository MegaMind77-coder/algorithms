#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int

vector<vector<int>> graph;
vector<int> weight;
int ans = -1e18;
int ans2 = -1e18;
int n;

int dfs(int src, vector<bool>& visited) {
    visited[src] = 1;
    int minn = 1e18;
    for(auto edge : graph[src]) {
        if(!visited[edge]){
            minn = min(minn, dfs(edge, visited));
        }
    }
    ans = max(ans, weight[src] - minn);
    return min(weight[src], minn);
}

int dfs2(int src, vector<bool>& visited) {
    visited[src] = 1;
    int maxx = -1e18;
    for(auto edge : graph[src]) {
        if(!visited[edge]){
            maxx = max(maxx, dfs2(edge, visited));
        }
    }
    ans2 = max(ans2, maxx - weight[src]);
    return max(weight[src], maxx);
}

int32_t main() {
    fastio();
    cin >> n;
    weight.assign(n+1, 0);
    graph.resize(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> weight[i];
    }
    int root = 1;
    for(int i = 1; i <= n; i ++) {
        int parent; 
        cin >> parent;
        if(parent == -1) {
            root = i;
            continue;
        }
        graph[parent].push_back(i);
        graph[i].push_back(parent);
    }

    vector<bool> visited(n+1, 0);
    int minn = dfs(root, visited);
    visited.assign(n+1, 0);
    int maxx = dfs2(root, visited);
    cout << max(ans, ans2) << endl;

    return 0;
}