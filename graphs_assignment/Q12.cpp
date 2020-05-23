#include <bits/stdc++.h>
typedef long long int ll;
#define MAX 10007
using namespace std;
//logic: using kruskal's algorithm , we can think of the a venn diagram that stores where in the one circle could be 
//edges of for men and another could be a circle of edges of women
//intersection would be edges of type 3
// by applying kruskal's algorithm we can find, the min road of type(1&3) required by men and 
// type(2&3) required by women
// we can also calculte the min edges of type3 required
// destroyed edges = total edges - type(1&3) - type(2&3) + type3



int parent[MAX]; //used to store the parent nodes of each vertex
int root(int node){  //finding parent node also does path compression
    
    while(parent[node] != node){
        parent[node ] = parent[parent[node]]; //path compression
        node = parent[node]; //changing node
    }
    return node;
}

void union1(int node1, int node2){ //merges two disjoint set having different parent nodes
    int p1 = root(node1);
    int p2 = root(node2);
    parent[p2] = p1;
}

int kruskal_mod(vector <pair<int, int>> edge_type, int count){  //kruskal algorithm counts the min_number of nodes needed
    
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
    for(int i=0; i<edges ; i++){ //loop initializes three vectors containg edges of type1, type2, type3
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
    type3 = kruskal_mod(edge3, type3); //type3 calculated
  //  cout << type3 << endl;
    int type2_3 = 0, type1_3 = 0;
    type1_3 = kruskal_mod(edge1, type3); //type(1&3)
   // cout << type1_3 << endl;
    for(int i=0; i<vertices+1; i++){
        parent[i] = i;
    }
    type3 = 0;
    type3 = kruskal_mod(edge3, type3);
    type2_3 = kruskal_mod(edge2, type3); //type(2&3)
    //cout << type1_3 << " " << type2_3 << endl;

    if(type2_3 < vertices-1 || type1_3 < vertices-1){ //if total number of vertices are less than v-1 that means the graph would be unconnected
        cout << -1 << endl;
    }
    else{
        int total_destroyed = 0;
        total_destroyed = edges - type1_3 - type2_3 + type3;
        cout << total_destroyed << endl;
    }
    return 0;
}