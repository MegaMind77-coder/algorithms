#include<bits/stdc++.h>
using namespace std;
//we check if the graph is 2-colorable or not to check if its biparite

bool bfs(int node, vector<vector<int>>& graph, vector<int>& color, vector<bool>& visited){
    
    int nodes = graph.size();
    
    queue <int> que; //queue is declared for bfs
    que.push(node);
    visited[node] = true;
    color[node] = 0; //only 2 colors 0 and 1 since it is 2-colorable

    while(!que.empty()){
        
        int u = que.front();
        que.pop();
        
        for(auto it= graph[u].begin(); it!= graph[u].end(); it++){
            if(!visited[*it]){
                que.push(*it);
                visited[*it] = true;
                if(color[u] == 0){ //child nodes are given color different from father
                    color[*it] = 1;
                }
                else{
                    color[*it] = 0;
                }
            }
            else if(color[u] == color[*it]){ //if the nodes is already visited and has same color as parent node
            //false is returned as it wouldn't be 2-colorable then
                return false;
            }
        }
    }
    return true;  //loop compltes connected component is 2-colorable
} 

bool isBipartite(vector<vector<int>>& graph) {

    if(graph.size() == 0){
        return false;
    }
    else{
        int nodes = graph.size();
        vector<int> color(nodes, -1); //stores the color of nodes
        vector<bool> visited(nodes, false); //stores bool value to check if a node is visited or not
        for(int i = 0; i<nodes; i++){ //loop would for unconnected nodes as well
            if(visited[i] == false){
                if(bfs(i, graph, color, visited) == false){  //bfs applied to check if conected component is 2-colorable
                    return false;
                }
            }
        }
        return true; //if loop is completed without returning false it means that it is 2-colorable and hence true is returned
    }
    return false;
}

int main(){
    int vertices;
    cout << "please enter the number of vertices:";
    cin >> vertices;
    vector<vector<int>>graph(vertices);
    int node;
    int num_edge;
    for(int i=0;i<vertices;i++){
        cout << "please enter the number of edges connected to vertex" + to_string(i) + ": ";
        cin >> num_edge;
        graph[i].resize(num_edge);
        cout << "enter connected vertices: ";
        for(int j=0;j<num_edge;j++){
            cin >> graph[i][j];
        }
    }

    if(isBipartite(graph)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}