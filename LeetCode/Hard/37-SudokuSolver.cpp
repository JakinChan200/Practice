//37
//Given a Sudoku Board. solve it - there is only one unique solution

#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<char>> &board, int curr){
    if(curr == 81){
        return true;
    }

    int row = curr / 9;
    int col = curr % 9;

    if(board[row][col] == '.'){
        return solve(board, curr + 1);
    }

    for(char c = '1'; c <= '9'; c++){
        if(isValid(board, row, col, c)){
            board[row][col] = c;
            if(solve(board, curr + 1)){
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

bool isValid(vector<vector<char>> &board, int row, int col, char character){
    for(int i = 0; i < 9; i++){
        if(character == board[row][i] || character == board[i][col] || 
            character == board[3 * (row / 3) + (i / 3)][3 * (col / 3) + i % 3]){
           return false; 
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board){
    solve(board, 0);
}

int main(int argc, char** argv){
    return 0;
}