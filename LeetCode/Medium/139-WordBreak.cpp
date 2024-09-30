//139
//Given a string s and a dictionary of strings, return true if s can be segmented into a space separated sequence of one or more dictionary words

#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict){
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
    unordered_set<string> set(wordDict.begin(), wordDict.end());

    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j < i; j++){
            if(dp[j] && set.count(s.substr(j, i-j))){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

// bool wordBreak(string s, vector<string> &wordDict){
//     if(s.length() == 0){
//         return true;
//     }

//     for(int i = 0; i < wordDict.size(); i++){
//         if(wordDict[i].length() <= s.length() && wordDict[i] == s.substr(0, wordDict[i].length())){
//             if(wordBreak(s.substr(wordDict[i].length()), wordDict)){
//                 return true;
//             }
//         }
//     }

//     return false;
// }

int main(int argc, char** argv){
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    bool answer = wordBreak(s, wordDict);
    cout << answer << endl;
    return 0;
}
