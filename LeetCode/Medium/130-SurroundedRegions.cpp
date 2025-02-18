//130
//Given a matrix m x n containing letters 'X' and 'O', capture regions that are surrounded
//A cell is connnected horizontally or verically
//To form a region, connect every 'O' cell
//A region is surrounded with 'X' cells if none of the region cells are on the edge of the board

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void fill(vector<vector<char>> &board, int row, int col){
    if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || board[row][col] != 'O'){
        return;
    }

    board[row][col] = '#';

    fill(board, row-1, col);
    fill(board, row+1, col);
    fill(board, row, col-1);
    fill(board, row, col+1);
}

void solve(vector<vector<char>> &board){

    for(int i = 0; i < board.size(); i++){
        fill(board, i, 0);
        fill(board, i, board[0].size()-1);
    }

    for(int i = 0; i < board[0].size(); i++){
        fill(board, 0, i);
        fill(board, board.size()-1, i);
    }

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
        }
    }
}