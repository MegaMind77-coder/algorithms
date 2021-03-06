#include<bits/stdc++.h>
using namespace std;
//idea is calculate number of connected components
//again we use the array of row and column opertaion 
//on moving up, down , right , left 

//we use dfs to calculate the number of connected components
int row_op[4] = {-1, 1, 0, 0};
int col_op[4] = {0, 0, 1, -1};

void dfs(int r, int c, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& visited){ //recursive  dfs
    visited[r][c] =  true;
    for(int i = 0; i<4; i++){
        if(r+row_op[i]>=0 && r+row_op[i] <rows && c+col_op[i]>=0 && c+col_op[i]<cols){
            if(grid[r+row_op[i]][c+col_op[i]] == '1' && visited[r+row_op[i]][c+col_op[i]] == false){
                dfs(r+row_op[i], c+col_op[i], rows, cols, grid, visited);  
            }
        }
    }
}



int count_components(vector<vector<char>>& grid, vector<vector<bool>>& visited, int rows, int cols){
    int count = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == '1' && visited[i][j] == false){ //if node is unvisited we apply dfs
            //after the loop if unvisted '1' are left we count them in separate connected components
                dfs(i, j, rows, cols, grid, visited);
                count += 1;
            }
        }
    }
    
    return count; //number of connected components are returned
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0){
        return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    vector <vector<bool>> visited(rows, vector<bool>(cols, false));
    return count_components(grid, visited, rows, cols);
}

//please enter a matrix of size 4*5
//as given in leetcode testcases

int main(){
    int edge_breadth = 4;
    int edge_length = 5;
    //assuming matrix edge is of size 4 as said in the question
    vector <vector<char>> grid(edge_breadth);
    for(int i=0; i<edge_breadth; i++){
        grid[i].resize(edge_length);
        for(int j=0; j<edge_length; j++){
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid) << endl;
}