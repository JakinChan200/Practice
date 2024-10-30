//2684
//Given a m x n matrix consisting of positive integers
//You can only move to the right, upright, or downright and the destination must have a bigger number
//Starting from any tile, what is the longest path

#include <bits/stdc++.h>

using namespace std;

void print2Dvector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int maxPath(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &paths){
    // if(row >= grid.size() || col >= grid[0].size() - 1){
    //     return 0;
    // }

    if(paths[row][col] > -1){
        return paths[row][col];
    }

    int rowSize = grid.size();
    int colSize = grid[0].size();
    int curMax = 0;

    //bottom right
    if(row < rowSize-1 && col < colSize-1 && grid[row+1][col+1] > grid[row][col]){
        curMax = maxPath(grid, row+1, col+1, paths)+1;
    }

    //top right
    if(row != 0 && col < colSize-1 && grid[row-1][col+1] > grid[row][col]){
        curMax = max(curMax, maxPath(grid, row-1, col+1, paths)+1);
    }

    //right
    if(col < colSize-1 && grid[row][col+1] > grid[row][col]){
        curMax = max(curMax, maxPath(grid, row, col+1, paths)+1);
    }

    paths[row][col] = curMax;
    return curMax;
}


int maxMoves(vector<vector<int>> &grid){
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
    int runningMax = 0;

    for(int i = 0; i < grid.size(); i++){
        runningMax = max(runningMax, maxPath(grid, i, 0, visited));
    }
    return runningMax;
}

int main(int argc, char** argv){
    vector<vector<int>> grid = {{2, 4, 3, 5},
                                {5, 4, 9, 3},
                                {3, 4, 2, 11},
                                {10, 9, 13, 15}};
    
    // vector<vector<int>> grid = {{3, 2, 4},
    //                             {2, 1, 9},
    //                             {1, 1, 7}};

    cout << maxMoves(grid);
    return 0;
}