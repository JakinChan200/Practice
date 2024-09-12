//1684
//Given the string allowed with a bunch of chars,return the number of strings in words that only use letters in allowed

#include <bits/stdc++.h>

using namespace std;

int countConsistentStrings(string allowed, vector<string> & words){
    vector<int> allowedLetters(26,0);
    for(char c : allowed){
        allowedLetters[c - 'a'] = 1;
    }

    bool isAllowed = true;
    int allowedCount = 0;
    for(string word: words){
        isAllowed = true;
        for(char letter : word){
            if(allowedLetters[letter] == 0){
                isAllowed = false;
            }
        }
        if(isAllowed){
            allowedCount++;
        }
    }
    return allowedCount;
}

int countConsistentStrings(string allowed, vector<string> & words){
    set<int> letters;
    for(int i = 0; i < allowed.size(); i++){
        letters.insert(allowed[i]);
    }

    int lettersSize = letters.size();
    int finalCount = 0;
    if(lettersSize == 0 || words.size() == 0){
        return 0;
    }

    for(int i = 0; i < words.size(); i++){
        bool isAllowed = true;

        for(int j = 0; j < words[i].size(); j++){
            if(!isAllowed){
                break;
            }

            letters.insert(words[i][j]);
            if(lettersSize != letters.size()){
                letters.erase(words[i][j]);
                isAllowed = false;
            }
        }
        if(isAllowed){
            finalCount++;
        }
    }
    return finalCount;
}