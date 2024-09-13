//79
//Given an m x n grid of chars and a string word, return true if word exists in the grid
//You may only move to adjacent (horizontal and vertical) cells
//The same cell may not be used more than once

#include <bits/stdc++.h>

using namespace std;

bool goThroughWord(vector<vector<char>>& board, int row, int col, string word, set<pair<int, int>> &coords, int wordIndex){
    coords.insert(pair<int,int>(row,col));
    
    if(wordIndex == word.length()-1){
        return true;
    }

    bool isAbove = false;
    bool isBelow = false;
    bool isLeft = false;
    bool isRight = false;

    if(row != 0 && board[row-1][col] == word[wordIndex+1]){
        if(coords.count(pair<int,int>(row-1,col)) == 0){
            isAbove = goThroughWord(board, row-1, col, word, coords, wordIndex+1);
        }
    }

    if(row != board.size()-1 && board[row+1][col] == word[wordIndex+1]){
        if(coords.count(pair<int,int>(row+1,col)) == 0){
            isBelow = goThroughWord(board, row+1, col, word, coords, wordIndex+1);
        }
    }

    if(col != 0 && board[row][col-1] == word[wordIndex+1]){
        if(coords.count(pair<int,int>(row,col-1)) == 0){
            isLeft = goThroughWord(board, row, col-1, word, coords, wordIndex+1);
        }
    }

    if(col != board[0].size()-1 && board[row][col+1] == word[wordIndex+1]){
        if(coords.count(pair<int,int>(row,col+1)) == 0){
            isRight = goThroughWord(board, row, col+1, word, coords, wordIndex+1);
        }
    }

    if(!(isAbove || isBelow || isLeft || isRight)){
        coords.erase(pair<int,int>(row, col));
    }
    return isAbove || isBelow || isLeft || isRight;
}

bool exist(vector<vector<char>>& board, string word) {
    set<char> characters;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            characters.insert(board[i][j]);
        }
    }

    for(int i = 0; i < word.size(); i++){
        if(characters.count(word[i]) == 0){
            return false;
        }
    }

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == word[0]){
                set<pair<int, int>> coords;
                if(goThroughWord(board, i, j, word, coords, 0)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(int argc, char** argv){
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, 
                                    {'S', 'F', 'E', 'S'},
                                    {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";

    bool answer = exist(board, word);
    cout << answer;

    return 0;
}