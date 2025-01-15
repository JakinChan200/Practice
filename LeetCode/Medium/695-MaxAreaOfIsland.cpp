//695
//Given an m x n binary matrix grid, where 1s are land connected adjacently horizontal or vertical
//Return the maximum area of an island
//0 if no island

#include <bits/stdc++.h>

using namespace std;

int fillIsland(int i, int j, vector<vector<int>>& grid){
    int numCells = 1;
    grid[i][j] = 2;

    if(i > 0 && grid[i-1][j] == 1){
        numCells += fillIsland(i-1, j, grid);
    }

    if(i < grid.size()-1 && grid[i+1][j] == 1){
        numCells += fillIsland(i+1, j, grid);
    }

    if(j > 0 && grid[i][j-1] == 1){
        numCells += fillIsland(i, j-1, grid);
    }

    if(j < grid[0].size()-1 && grid[i][j+1] == 1){
        numCells += fillIsland(i, j+1, grid);
    }

    return numCells;
}

void printGrid(vector<vector<int>>& grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j] << "";
        }
        cout << "\n";
    }
    cout << "\n";
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int maxArea = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                maxArea = max(maxArea, fillIsland(i, j, grid));
                // printGrid(grid);
            }
        }
    }

    return maxArea;
}