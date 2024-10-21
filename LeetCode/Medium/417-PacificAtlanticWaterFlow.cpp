//417
//Given a m x n matrix, where Pacific is top and left, and Atlantic is right and bottom,
//Each cell has a number (height above sea level), and water can only flow to an equal or lower height adjacent (not diagonal)
//Return all coordinates where it flows to both oceans

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVectorBool(vector<vector<bool>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int row, int col){
    if(visited[row][col]){
        return;
    }

    visited[row][col] = true;
    if(row != 0 && heights[row-1][col] >= heights[row][col]) dfs(heights, visited, row-1, col);
    if(col != 0 && heights[row][col-1] >= heights[row][col]) dfs(heights, visited, row, col-1);
    if(row != heights.size()-1 && heights[row+1][col] >= heights[row][col]) dfs(heights, visited, row+1, col);
    if(col != heights[row].size()-1 && heights[row][col+1] >= heights[row][col]) dfs(heights, visited, row, col+1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
    vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<int>> answers;

    for(int i = 0; i < heights.size(); i++){
        dfs(heights, atlantic, i, heights[0].size()-1);
        dfs(heights, pacific, i, 0);
    }

    for(int i = 0; i < heights[0].size(); i++){
        dfs(heights, atlantic, heights.size()-1, i);
        dfs(heights, pacific, 0, i);
    }

    // print2DVectorBool(atlantic);
    // print2DVectorBool(pacific);

    for(int i = 0; i < heights.size(); i++){
        for(int j = 0; j < heights[i].size(); j++){
            if(atlantic[i][j] && pacific[i][j]){
                answers.push_back({i,j});
            }
        }
    }
    return answers;
}

int main(int argc, char** argv){
    vector<vector<int>> heights = {{1,2,2,3,5},
                                    {3,2,3,4,4},
                                    {2,4,5,3,1},
                                    {6,7,1,4,5},
                                    {5,1,1,2,4}};
    
    // vector<vector<int>> heights = {{10, 10, 10},
    //                                 {10, 1, 10},
    //                                 {10, 10, 10}};

    vector<vector<int>> answers = pacificAtlantic(heights);
    print2DVector(answers);

    return 0;
}

//Ran into an issue where it wraps around, and the in progress does not show
//For example, in the second heights, 0,1 would not reach the altlantic cause 0,2 would be the one calling it, and 0,2 did not update paths yet
//If we preemptively update 0,2 and return because it is on the edge, in the first heights, 1,4 would fail, because it would call 1,3, and then they are stuck unless I update as I go

// int findPaths(vector<vector<int>> &heights, vector<vector<int>> &paths, int row, int col){
//     // cout << row << " " << col << " " << paths[row][col] << endl;
//     if(paths[row][col] != -1){
//         return paths[row][col];
//     }

//     bool pacific = false;
//     bool atlantic = false;

//     paths[row][col] = 0;

//     if(row == 0 || col == 0){
//         pacific = true;
//         // paths[row][col] += 1;
//     }

//     if(row == heights.size()-1 || col == heights[row].size()-1){
//         atlantic = true;
//         // paths[row][col] += 2;
//     }

//     // if(row == 0 && col == 1) cout << "0 " << pacific << " " << atlantic << endl;

//     if(row != 0 && heights[row-1][col] <= heights[row][col]){
//         int temp = findPaths(heights, paths, row-1, col);
//         if(temp == 3){
//             pacific = true;
//             atlantic = true;
//         }else{
//             if(temp == 1) pacific = true;
//             if(temp == 2) atlantic = true;
//         }
//         // if(row == 0 && col == 1) cout << "1 " << pacific << " " << atlantic << endl;
//     }

//     if(col != 0 && heights[row][col-1] <= heights[row][col]){
//         int temp = findPaths(heights, paths, row, col-1);
//         if(temp == 3){
//             pacific = true;
//             atlantic = true;
//         }else{
//             if(temp == 1) pacific = true;
//             if(temp == 2) atlantic = true;
//         }
//         // if(row == 0 && col == 1) cout << "2 " << pacific << " " << atlantic << endl;
//     }

//     if(row != heights.size()-1 && heights[row+1][col] <= heights[row][col]){
//         int temp = findPaths(heights, paths, row+1, col);
//         if(temp == 3){
//             pacific = true;
//             atlantic = true;
//         }else{
//             if(temp == 1) pacific = true;
//             if(temp == 2) atlantic = true;
//         }
//         // if(row == 0 && col == 1) cout << "3 " << pacific << " " << atlantic << endl;
//     }

//     if(col != heights[row].size()-1 && heights[row][col+1] <= heights[row][col]){
//         int temp = findPaths(heights, paths, row, col+1);
//         if(temp == 3){
//             pacific = true;
//             atlantic = true;
//         }else{
//             if(temp == 1) pacific = true;
//             if(temp == 2) atlantic = true;
//         }
//         // if(row == 0 && col == 1) cout << "4 " << pacific << " " << atlantic << endl;
//     }

//     if(pacific) paths[row][col] += 1;
//     if(atlantic) paths[row][col] += 2;

//     // cout << "row: " << row << " col: " << col << endl;
//     // cout << paths[row][col] << endl;

//     return paths[row][col];
// }

// int findAtlantic(vector<vector<int>> &heights, vector<vector<int>> &atlantic, int row, int col){
//     if(atlantic[row][col] != -1){
//         return atlantic[row][col];
//     }

//     atlantic[row][col] = 0;

//     if(col == heights[row].size()-1 || row == heights.size()-1){
//         atlantic[row][col] = 1;
//         return 1;
//     }

//     if(row != 0 && atlantic[row-1][col] <= atlantic[row][col] && findAtlantic(heights, atlantic, row-1,col)){
//         atlantic[row][col] = 1;
//         return 1;
//     }

//     if(col != 0 && atlantic[row][col-1] <= atlantic[row][col] && findAtlantic(heights, atlantic, row,col-1)){
//         atlantic[row][col] = 1;
//         return 1;
//     }

//     if(row != atlantic.size()-1 && atlantic[row+1][col] <= atlantic[row][col] && findAtlantic(heights, atlantic, row+1, col)){
//         atlantic[row][col] = 1;
//         return 1;
//     }

//     if(col != atlantic[0].size()-1 && atlantic[row][col+1] <= atlantic[row][col] && findAtlantic(heights, atlantic, row, col+1)){
//         atlantic[row][col] = 1;
//         return 1;
//     }

//     return 0;
// }

// int findPacific(vector<vector<int>> &heights, vector<vector<int>> &pacific, int row, int col){
//     if(pacific[row][col] != -1){
//         return pacific[row][col];
//     }

//     pacific[row][col] = 0;

//     if(col == 0 || row == 0){
//         pacific[row][col] = 1;
//         return 1;
//     }

//     if(row != 0 && pacific[row-1][col] <= pacific[row][col] && findPacific(heights, pacific, row-1,col)){
//         pacific[row][col] = 1;
//         return 1;
//     }

//     if(col != 0 && pacific[row][col-1] <= pacific[row][col] && findPacific(heights, pacific, row,col-1)){
//         pacific[row][col] = 1;
//         return 1;
//     }

//     if(row != pacific.size()-1 && pacific[row+1][col] <= pacific[row][col] && findPacific(heights, pacific, row+1, col)){
//         pacific[row][col] = 1;
//         return 1;
//     }

//     if(col != pacific[0].size()-1 && pacific[row][col+1] <= pacific[row][col] && findPacific(heights, pacific, row, col+1)){
//         pacific[row][col] = 1;
//         return 1;
//     }

//     return 0;
// }