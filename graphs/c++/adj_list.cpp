#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj_list[], int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void print_graph(vector<int> adj_list[], int V){
    for(int i=0;i<V;i++){
        cout << i <<'\t';
        for(auto x: adj_list[i]){
            cout << x << '\t';
        }
        printf("\n");
    }
}

int main(){

    int num_vertices = 5;
    vector <int> adj_list[num_vertices];
    addedge(adj_list, 0, 1); 
    addedge(adj_list, 0, 4); 
    addedge(adj_list, 1, 2); 
    addedge(adj_list, 1, 3); 
    addedge(adj_list, 1, 4); 
    addedge(adj_list, 2, 3); 
    addedge(adj_list, 3, 4);

    print_graph(adj_list, num_vertices); 
    return 0;
}