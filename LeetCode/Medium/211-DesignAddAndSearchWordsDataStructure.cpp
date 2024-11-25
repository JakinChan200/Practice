//211
//Design a data structure that supports adding new words and finding if a sttring matches any previously added string

#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
    vector<WordDictionary*> child;
    bool isWord;
public:
    WordDictionary() {
        child = vector<WordDictionary*>(26, nullptr);
        isWord = false;
    }
    
    void addWord(string word) {
        WordDictionary *node = this;
        for(auto c : word){
            if(node->child[c - 'a'] == nullptr){
                node->child[c - 'a'] = new WordDictionary();
            }
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        WordDictionary *node = this;
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto ch : node->child){
                    if(ch && ch->search(word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }else if(node->child[c - 'a'] == nullptr){
                return false;
            }
            node = node->child[c - 'a'];
        }
        return node && node->isWord;
    }
};

int main(int argc, char** argv){
    return 0;
}