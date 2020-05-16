#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>>& graph, vector<int>& color, vector<bool>& visited){
    
    int nodes = graph.size();
    
    queue <int> que;
    que.push(node);
    visited[node] = true;
    color[node] = 0;

    while(!que.empty()){
        
        int u = que.front();
        que.pop();
        
        for(auto it= graph[u].begin(); it!= graph[u].end(); it++){
            if(!visited[*it]){
                que.push(*it);
                visited[*it] = true;
                if(color[u] == 0){
                    color[*it] = 1;
                }
                else{
                    color[*it] = 0;
                }
            }
            else if(color[u] == color[*it]){
                return false;
            }
        }
    }
    
    return true;
}


bool isBipartite(vector<vector<int>>& graph) {

    if(graph.size() == 0){
        return false;
    }
    else{
        //bool visited[nodes] = {false};
        int nodes = graph.size();
        vector<int> color(nodes, -1);
        vector<bool> visited(nodes, false);
        for(int i = 0; i<nodes; i++){
            if(visited[i] == false){
                if(bfs(i, graph, color, visited) == false){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
