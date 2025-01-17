//567
//Given two strings, return true if s2 contains a permutation of s1

#include <bits/stdc++.h>

using namespace std;

bool isMatching(vector<int> &freq, vector<int> &freq2){
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    vector<int> freq(26, 0);
    vector<int> freq2(26, 0);
    
    for(int i = 0; i < s1.size(); i++){
        freq[s1[i] - 'a']++;
    }

    for(int i = 0; i < s2.size(); i++){
        freq2[s2[i] - 'a']++;
        if(i >= s1.size()){
            freq2[s2[i-s1.size()] - 'a']--;

        }

        if(isMatching(freq, freq2)){
            return true;
        }
    }

    return false;
}