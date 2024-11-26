//383
//Given string ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine
//Each letter can only be used once

#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine){
    vector<int> letters(26, 0);
    for(int i = 0; i < magazine.size(); i++){
        letters[magazine[i] - 'a']++;
    }

    for(int i = 0; i < ransomNote.size(); i++){
        if(letters[ransomNote[i] - 'a'] <= 0){
            return false;
        }
        letters[ransomNote[i] - 'a']--;
    }
    return true;
}

int main(int argc, char** argv){
    string ransomNote = "a";
    string magazine = "aab";

    bool answer = canConstruct(ransomNote, magazine);
    cout << answer << endl;
    return 0;
}