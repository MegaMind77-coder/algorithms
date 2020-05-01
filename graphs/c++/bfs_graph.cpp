#include<bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <vector <int> > adj_list;

void add_edge(int u, int v){
    adj_list[u].push_back(v);
}

void bfs(int u){
    queue <int> que;
    que.push(u);
    visited[u] = true;

    while(!que.empty()){
        int f = que.front();
        que.pop();

        cout << f << endl;

        for(auto i = adj_list[f].begin(); i!=adj_list[f].end(); i++  ){
            if(!visited[*i]){
                que.push(*i);
                visited[*i] = true;
            }   
        }

    }
}

int main(){ 
    int n, e; 
    cin >> n >> e; 

    visited.assign(n, false); 
    adj_list.assign(n, vector<int>()); 

    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        add_edge(a, b); 
    } 

    for (int i = 0; i < n; i++) { 
        if (!visited[i]) 
            bfs(i); 
    } 
    return 0; 
} 