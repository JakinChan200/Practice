//208
//Implement the Trie class

#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == nullptr){
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == nullptr){
                return false;
            }
            node = node->child[index];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char c : prefix){
            int index = c - 'a';
            if(node->child[index] == nullptr){
                return false;
            }
            node = node->child[index];
        }
        return true;
    }
};

int main(int argc, char** argv){

}