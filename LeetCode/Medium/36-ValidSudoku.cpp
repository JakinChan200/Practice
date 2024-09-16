//36
//Given a 9x9 sudoku board, return whether or not it is valid

//Each row must contain 1-9 without repetition
//Each Column must contain 1-9 without repetition
//Each 3x3 must contain 1-9 without repetition

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << " " << nums[i];
    }
    cout << endl;
}

void resetCounters(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        nums[i] = 0;
    }
}

bool isValidSudoku(vector<vector<char>> &board){
    //'.' = 46
    //'0' = 48
    
    vector<int> counters(9, 0);

    //Check rows
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] != '.'){
                if(counters[board[i][j]-49] > 0){
                    return false;
                }
                counters[board[i][j]-49]++;
            }
        }
        resetCounters(counters);
    }

    //Check Columns
    for(int i = 0; i < board[0].size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[j][i] != '.'){
                if(counters[board[j][i]-49] > 0){
                    return false;
                }
                counters[board[j][i]-49]++;
            }
        }
        resetCounters(counters);
    }

    //Check 3x3 grids
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = i*3; k < i*3+3; k++){
                for(int l = j*3; l < j*3+3; l++){
                    if(board[k][l] != '.'){
                        if(counters[board[k][l]-49] > 0){
                            return false;
                        }
                        counters[board[k][l]-49]++;
                    }
                }
            }
            resetCounters(counters);
        }
    }
    return true;
}

int main(int argc, char** argv){
    vector<vector<char>> board = 
                                {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> board2 = 
                                {{'8','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'2','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    cout << isValidSudoku(board2);
    return 0;
}