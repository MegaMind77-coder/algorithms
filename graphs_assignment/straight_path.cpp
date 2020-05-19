#include<bits/stdc++.h>
#define node pair<pair<int, int>, int> 
#define MAX 1003
using namespace std;
int row_op[4] = {-1, 1, 0, 0}; //row_op is the change in the row by up, down, right, left movement 
int col_op[4] = {0, 0, 1, -1}; //col_op is the chane in the col by up, down, right, left movement 
int dist[MAX][MAX][4]; //stores the dist travelled to reach an index , for each position(x, y ) we store 
//the distance required to reach that posotion using, the ith operation
char grid[MAX][MAX]; //stores the grid given as input by the user 

void bfs(int st_row, int st_col, int n, int m){
    for(int i=0;i<n;i++){     //initializes distances to -1
        for(int j=0;j<m;j++){
            for(int x=0;x<4;x++){
                dist[i][j][x] = -1;
            }
        }
    }

    for(int i=0;i<4;i++){    //initializes all distances to starting vertex as 0
        dist[st_row][st_col][i] = 0;
    }

    queue <node> que;  //normal bfs queue initialized 
    int row_cord;   
    int col_cord;
    grid[st_row][st_col] = '*';
    for(int i=0;i<4;i++){
        row_cord = st_row + row_op[i];     
        col_cord = st_col + col_op[i];
        if(row_cord >= 0 && row_cord <n && col_cord >=0 && col_cord < m && grid[row_cord][col_cord] !=  '*'){
            que.push(make_pair(make_pair(row_cord, col_cord), i));
            dist[row_cord][col_cord][i] = 0;
        }
    }
    while(!que.empty()){
        node top = que.front();
        que.pop();
        int oper = top.second;
        int d = dist[top.first.first][top.first.second][oper];
        for(int i=0;i<4;i++){
            row_cord = top.first.first + row_op[i];
            col_cord = top.first.second + col_op[i];
            if(row_cord >= 0 && row_cord <n && col_cord >=0 && col_cord < m && grid[row_cord][col_cord] !=  '*'){ //if it lies in the 
            //the cordinates of the grid.
                if(oper == i){
                    if(dist[row_cord][col_cord][i] == -1 || dist[row_cord][col_cord][i] > d){ //if the node is unvisited we add it to the queue 
                    //else if a smaller replacement is found to reach the node using the direction 'i' we make the changes
                        que.push(make_pair(make_pair(row_cord, col_cord), i)); 
                        dist[row_cord][col_cord][i] = d;
                    }
                }
                else{
                    if(dist[row_cord][col_cord][i] == -1 || dist[row_cord][col_cord][i] > d+1){
                        que.push(make_pair(make_pair(row_cord, col_cord), i));
                        dist[row_cord][col_cord][i] = d+1;
                    }
                }                
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m; // n and m taken as input
    int st_row, st_col, end_row, end_col;
    for(int i =0; i<n; i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'V'){ // 'v' is the starting vertex
                st_row = i;
                st_col = j;
            }
            if(grid[i][j] == 'H'){ // 'h' is the final vertex
                end_row = i;
                end_col = j;
            }
        }
    }
   
    bfs(st_row, st_col, n, m); //bfs function that claculates the dist to final vertex using bfs traversal
    
    int ans = INT_MAX;
    for(int i=0;i<4;i++){
        if(dist[end_row][end_col][i] != -1){
            ans = min(ans, dist[end_row][end_col][i]); //calculates the min value out of the 4 ways the final vertex is beig uproached
        } 
    }
    if(ans == INT_MAX){  //if ans is int_max it means the vertex is unvisited and thus cannot be visited, hence we print -1 else we print final ans
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}