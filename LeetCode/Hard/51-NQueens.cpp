//51
//Given integer n, return all the ways that n queens can be placed on a nxn board
//Format is in a string vector

#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<string> &board){
    for(int i = 0; i < board.size(); i++){
        cout << board[i] << endl;
    }
}

void printAllBoards(vector<vector<string>> &answers){
    for(int i = 0; i < answers.size(); i++){
        printBoard(answers[i]);
        cout << endl;
    }
}

vector<string> buildBoard(int n){
    vector<string> board(n, string(n, '.'));

    return board;
}

bool isOpen(vector<string> &board, int row, int col){
    int b = board.size();

    for(int i = 0; i < board.size(); i++){
        if(board[i][col] == 'Q'){
            return false;
        }

        // if(board[row][i] == 'Q'){
        //     return false;
        // }

        //Diagonal top left to bottom right
        // cout << i << " " << (i + col - row) << endl;
        int col1 = i + col - row;
        if(col1 >= 0 && col1 < board.size() && board[i][col1] == 'Q'){
            // board[i][i + col - row] = 'Q';
            return false;
        }

        //Diagonal bottom left to top right
        // cout << b-i-1 << " " << i + col + row - b + correction << endl;
        int col2 = i + col + row - b + 1;
        if(col2 >= 0 && col2 < board.size() && board[b-i-1][col2] == 'Q'){
            // board[b-i-1][i + col + row - b + 1] = 'Q';
            return false;
        }
    }
    return true;
}

void addQueen(vector<string> board, vector<vector<string>> &answers, int n, int row){
    if(row >= board.size()){
        answers.push_back(board);
        return;
    }

    for(int i = 0; i < n; i++){
        if(isOpen(board, row, i)){
            board[row][i] = 'Q';
            addQueen(board, answers, n, row+1);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> answers;

    vector<string> board = buildBoard(n);
    addQueen(board, answers, n, 0);

    return answers;
}

int main(int argc, char** argv){
    int n = 4;

    vector<vector<string>> answers = solveNQueens(n);
    printAllBoards(answers);

    return 0;
}

//For some reason, 
//  row - (board.size()/2)
//breaks but 
//  int h = board.size()/2
//  row - h
//doesn't break

//Interstingly, they just kept track of the diagonals that were used instead of iterating through them

// . Q . . .
// . . . . .
// . . . . .
// . . . . .
// . . . . .