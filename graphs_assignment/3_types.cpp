#include <bits/stdc++.h>
typedef long long int ll;
#define MAX 10007
using namespace std;

int parent[MAX];
int root(int node){
    
    while(parent[node] != node){
        parent[node ] = parent[parent[node]]; //path compression
        node = parent[node]; //changing node
    }
    return node;
}

void union1(int node1, int node2){
    int p1 = root(node1);
    int p2 = root(node2);
    parent[p2] = p1;
}

int kruskal_mod(vector <pair<int, int>> edge_type, int count){
    
    for(int i=0; i<edge_type.size(); i++){
        int u = edge_type[i].first;
        int v = edge_type[i].second;
        if(root(u) != root(v)){
            union1(u, v);
            count += 1;
        }
    }
    return count;
}

int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    vector <pair<int, int>> edge1, edge2, edge3;
    int u, v, type;
    for(int i=0; i<edges ; i++){
        cin >> u >> v >> type;
        if(type == 1){
            edge1.push_back(make_pair(u, v));
        }
        else if(type == 2){
            edge2.push_back(make_pair(u, v));
        }
        else{
            edge3.push_back(make_pair(u, v));
        }
    }

    for(int i=0; i<vertices+1; i++){
        parent[i] = i;
    }   

    int type3 = 0;
    type3 = kruskal_mod(edge3, type3);
  //  cout << type3 << endl;
    int type2_3 = 0, type1_3 = 0;
    type1_3 = kruskal_mod(edge1, type3);
   // cout << type1_3 << endl;
    for(int i=0; i<vertices+1; i++){
        parent[i] = i;
    }
    type3 = 0;
    type3 = kruskal_mod(edge3, type3);
    type2_3 = kruskal_mod(edge2, type3);
    //cout << type1_3 << " " << type2_3 << endl;

    if(type2_3 < vertices-1 || type1_3 < vertices-1){
        cout << -1 << endl;
    }
    else{
        int total_destroyed = 0;
        total_destroyed = edges - type1_3 - type2_3 + type3;
        cout << total_destroyed << endl;
    }
    return 0;
}