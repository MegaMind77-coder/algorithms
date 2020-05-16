#include<bits/stdc++.h>
#define heap_node pair<int, pair<char, pair<int, int> > >
#define MAX 1007
using namespace std;
char graph_matrix[MAX][MAX];
int row_op[4] = {-1, 1, 0, 0};
int col_op[4] = {0, 0, 1, -1};
char operation[4] = {'u', 'd', 'l', 'r'};
priority_queue<heap_node, vector<heap_node>, greater<heap_node> > min_heap;
int distances[MAX][MAX];

void djikstra_mod(int start_i, int start_j, int dest_i, int dest_j, int n, int m){
    int i = 0;
    char oper;
    int row_cord, col_cord;
   // cout << start_i << " " << start_j <<'\n';
    while(i < 4){
        row_cord = start_i + row_op[i];
        col_cord = start_j + col_op[i];
        
        //cout << x_cord << " " << y_cord <<" "<< i << graph_matrix[x_cord][y_cord] << '\n';
        if(row_cord >= 0 && row_cord <= n-1 &&  col_cord >= 0 && col_cord <= m-1){
            if( graph_matrix[row_cord][col_cord] == '.'){
                //cout << operation[i];

                min_heap.push(make_pair(0, make_pair(operation[i], make_pair(row_cord, col_cord))));
                distances[row_cord][col_cord] = 0;
            }
            else if(graph_matrix[row_cord][col_cord] == 'H'){
                cout << 0;
                break;
            }
        }
        i += 1;
    }
    i = 0;
    
    while(!min_heap.empty()){

        heap_node min_node = min_heap.top();
        min_heap.pop();
        char op = min_node.second.first;
        int node_row = min_node.second.second.first;
        int node_col = min_node.second.second.second;
        int initial = distances[node_row][node_col];
        cout << op;
        //cout << node_x << node_y;
        //cout << node_row << " " << node_col << initial << '\n';
		if (graph_matrix[node_row][node_col] == '*'){
			continue;
		}
        graph_matrix[node_row][node_col] = '*';
        i = 0;
        while(i < 4){
            row_cord = node_row + row_op[i];
            col_cord = node_col + col_op[i];
            
            if(row_cord >= 0 && row_cord <= n-1 &&  col_cord >= 0 && col_cord <= m-1){

                if( graph_matrix[row_cord][col_cord] == '.' && op == operation[i]){
                    //cout << row_cord << " " << col_cord << "yo" << '\n';
                    if(initial < distances[row_cord][col_cord]){

                        min_heap.push(make_pair(initial, make_pair(operation[i], make_pair(row_cord, col_cord))));
                        distances[row_cord][col_cord] = initial;

                    }

                }
                else if(  graph_matrix[row_cord][col_cord] == '.' && op != operation[i]){
                    if(initial + 1< distances[row_cord][col_cord]){

                        min_heap.push(make_pair(initial + 1, make_pair(operation[i], make_pair(row_cord, col_cord))));
                        distances[row_cord][col_cord] = initial+1;

                    }
                }
                else if( graph_matrix[row_cord][col_cord] == 'H' && op == operation[i]){
                    if(initial < distances[row_cord][col_cord]){

                        distances[row_cord][col_cord] = initial;

                    }
                }
                else if( graph_matrix[row_cord][col_cord] == 'H' && op != operation[i]){
                    if(initial +1 < distances[row_cord][col_cord]){
                        distances[row_cord][col_cord] = initial + 1;

                    }
                }
            }
            i += 1;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int start_i, start_j;
    int dest_i, dest_j;
    char node;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin >> graph_matrix[i][j];
            distances[i][j] = MAX;
            if(graph_matrix[i][j] == 'V'){
                start_i = i;
                start_j = j;
            }
            if(graph_matrix[i][j] == 'H'){
                dest_i = i;
                dest_j = j;
            }
        }
    }

    distances[start_i][start_j] = 0;
    graph_matrix[start_i][start_j] = '*';

    djikstra_mod(start_i, start_j, dest_i, dest_j, n, m);

    if(distances[dest_i][dest_j] == MAX){
        cout << -1;
    }
    else{
        cout << distances[dest_i][dest_j];
    }
    return 0;
}