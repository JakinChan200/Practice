//424
//Given a string s and an integer k, return the length of the longest substring of the same
//uppercase character given that you can replace any character k times

#include <bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k){
    unordered_map<char, int> count;
    int l = 0;
    int r = 0;
    int maxCount = 0;
    int maxLen = 0;

    while(r < s.size()){
        count[s[r]]++;
        maxCount = max(maxCount, count[s[r]]);

        if((r - l + 1) - maxCount > k){
            count[s[l]]--;
            l++;
        }
        maxLen = max(maxCount, r-l+1);
        r++;
    }

    return maxLen;
}

int main(int argc, char** argv){
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);
    return 0;
}