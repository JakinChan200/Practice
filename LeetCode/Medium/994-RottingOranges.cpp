//994
//Given an mxn grid, where each cell is a 0, 1, or 2, each move any 1 (fresh orange) adjacent to a 2 (rotten orange) becomes rotten
//Return how long until no cell has a fresh orange. If impossible, return -1;

#include <bits/stdc++.h>

using namespace std;

int countFreshOranges(vector<vector<int>> &grid){
    int numFreshOranges = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            numFreshOranges += grid[i][j] == 1;
        }
    }

    return numFreshOranges;
}

int fillGrid(vector<vector<int>> &grid, int counter){
    int newRottenOranges = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == counter){
                if(i > 0 && grid[i-1][j] == 1){
                    newRottenOranges++;
                    grid[i-1][j] = counter+1;
                }
                
                if(i < grid.size()-1 && grid[i+1][j] == 1){
                    newRottenOranges++;
                    grid[i+1][j] = counter+1;
                }

                if(j > 0 && grid[i][j-1] == 1){
                    newRottenOranges++;
                    grid[i][j-1] = counter+1;
                }

                if(j < grid[0].size()-1 && grid[i][j+1] == 1){
                    newRottenOranges++;
                    grid[i][j+1] = counter+1;
                }
            }
        }
    }
    return newRottenOranges;
}

void printGrid(vector<vector<int>> &grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << " " << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int orangesRotting(vector<vector<int>> &grid){
    int turns = 2;
    int newRottenOranges = fillGrid(grid, turns);

    while(newRottenOranges != 0){
        // printGrid(grid);
        turns++;
        newRottenOranges = fillGrid(grid, turns);
    }

    if(countFreshOranges(grid) > 0){
        return -1;
    }

    return turns - 2;
}

int main(int argc, char** argv){
    // vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid) << endl;

    printGrid(grid);
    // cout << countFreshOranges(grid) << endl;

    return 1;
}

