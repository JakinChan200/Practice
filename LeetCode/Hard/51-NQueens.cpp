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
    string tempRow (n, '.');
    vector<string> board(n, tempRow);

    return board;
}

bool isOpen(vector<string> &board, int row, int col){
    int b = board.size();
    int correction = 1;

    for(int i = 0; i < board.size(); i++){
        if(board[i][col] == 'Q'){
            return false;
        }

        if(board[row][i] == 'Q'){
            return false;
        }

        //Diagonal top left to bottom right
        // cout << i << " " << (i + col - row) << endl;
        if((i + col - row) >= 0 && (i + col - row) < board.size() && board[i][i + col - row] == 'Q'){
            // board[i][i + col - row] = 'Q';
            return false;
        }

        //Diagonal bottom left to top right
        // cout << b-i-1 << " " << i + col + row - b + correction << endl;
        if(i + col + row - b + 1 >= 0 && i + col + row - b + 1 < board.size() && board[b-i-1][i + col + row - b + 1] == 'Q'){
            // board[b-i-1][i + col + row - b + 1] = 'Q';
            return false;
        }
    }
    return true;
}

void addQueen(vector<string> board, vector<vector<string>> &answers, int n, int row){
    for(int i = 0; i < n; i++){
        if(isOpen(board, row, i)){
            vector<string> temp = board;
            temp[row][i] = 'Q';
            if(row == board.size()-1){
                answers.push_back(temp);
            }else{
                addQueen(temp, answers, n, row+1);
            }
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


// . Q . . .
// . . . . .
// . . . . .
// . . . . .
// . . . . .