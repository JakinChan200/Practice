//212
//Given an m x n board of characters ad a list of string words, return all the words on the board
//Each word must be constructed from adjacent (vertical or horizontal)
//The same letter cell may not be used more than once in a word

#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode *children[26];
    string word;

    TrieNode() : word("") {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void printWords(vector<string> words){
    if(words.size() == 0){
        return;
    }

    cout << "{";
    cout << words[0];
    for(int i = 1; i < words.size(); i++){
        cout << ", " << words[i];
    }
    cout << "}";
}

void goThroughWord(vector<vector<char>>& board, int row, int col, TrieNode *p, vector<string> &finalWords){    
    char c = board[row][col];
    if (c == '0' || !p->children[c - 'a']) return;
    p = p->children[c - 'a'];
    if (p->word.size() > 0) {
        finalWords.push_back(p->word);
        p->word = "";
    }

    board[row][col] = '0';

    if(row != 0) goThroughWord(board, row-1, col, p, finalWords);
    if(row != board.size()-1) goThroughWord(board, row+1, col, p, finalWords);
    if(col != 0) goThroughWord(board, row, col-1, p, finalWords);
    if(col != board[0].size()-1) goThroughWord(board, row, col+1, p, finalWords);

    board[row][col] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {    
    TrieNode *root = new TrieNode();
    for (int j = 0; j < words.size(); j++) {
        string word = words[j];
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i] - 'a';
            if (curr->children[c] == nullptr) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = word;
    }

    vector<string> finalWords;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            goThroughWord(board, i, j, root, finalWords);
        }
    }
    return finalWords;
}

int main(int argc, char** argv){
    vector<vector<char>> board = {{'o','a','a','n'},
                                    {'e','t','a','e'},
                                    {'i','h','k','r'},
                                    {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};

    vector<string> answer = findWords(board, words);
    printWords(answer);
    return 0;
}


// class Solution {
//     struct TrieNode {
//         TrieNode *children[26];
//         string word;

//         TrieNode() : word("") {
//             for (int i = 0; i < 26; i++) {
//                 children[i] = nullptr;
//             }
//         }
//     };

// public:
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
//         TrieNode *root = buildTrie(words);
//         vector<string> result;
//         for (int i = 0; i < board.size(); i++) {
//             for (int j = 0; j < board[0].size(); j++) {
//                 dfs(board, i, j, root, result);
//             }
//         }
//         return result;
//     }

//     /** Inserts a word into the trie. */
//     TrieNode *buildTrie(vector<string> &words) {
//         TrieNode *root = new TrieNode();
//         for (int j = 0; j < words.size(); j++) {
//             string word = words[j];
//             TrieNode *curr = root;
//             for (int i = 0; i < word.length(); i++) {
//                 char c = word[i] - 'a';
//                 if (curr->children[c] == nullptr) {
//                     curr->children[c] = new TrieNode();
//                 }
//                 curr = curr->children[c];
//             }
//             curr->word = word;
//         }
//         return root;
//     }

//     void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
//         char c = board[i][j];
//         if (c == '#' || !p->children[c - 'a']) return;
//         p = p->children[c - 'a'];
//         if (p->word.size() > 0) {
//             result.push_back(p->word);
//             p->word = "";
//         }

//         board[i][j] = '#';
//         if (i > 0) dfs(board, i - 1, j, p, result);
//         if (j > 0) dfs(board, i, j - 1, p, result);
//         if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
//         if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
//         board[i][j] = c;
//     }
// };