//200
//Given a 2D grid where 1 is land and 0 is water, return the number of islands
//Only Horizontal and Vertical adjacent is considered part of the same island

#include <bits/stdc++.h>

using namespace std;

void fillGrid(vector<vector<char>> &grid, vector<vector<bool>> &tracker, int row, int col){
    tracker[row][col] = true;

    if(row != 0 && grid[row-1][col] == '1' && tracker[row-1][col] == false){
        fillGrid(grid, tracker, row-1, col);
    }

    if(row != grid.size()-1 && grid[row+1][col] == '1' && tracker[row+1][col] == false){
        fillGrid(grid, tracker, row+1,col);
    }

    if(col != 0 && grid[row][col-1] == '1' && tracker[row][col-1] == false){
        fillGrid(grid, tracker, row, col-1);
    }

    if(col != grid[0].size()-1 && grid[row][col+1] == '1' && tracker[row][col+1] == false){
        fillGrid(grid, tracker, row, col+1);
    }
}

int numIslands(vector<vector<char>> &grid){
    vector<vector<bool>> tracker(grid.size(), vector<bool>(grid[0].size(), false));
    int numIslands = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1' && tracker[i][j] == false){
                numIslands++;
                fillGrid(grid, tracker, i, j);
            }
        }
    }
    return numIslands;
}

int main(int argc, char** argv){
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','1'}};

    int numIs = numIslands(grid);
    cout << numIs << endl;

    return 0;
}
