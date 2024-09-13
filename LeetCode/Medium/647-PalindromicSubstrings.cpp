//647
//Given a string s, return the number of palindromic substrings in it

#include<bits/stdc++.h>

using namespace std;

int isPalindrome(string s, int low, int high){
    int count = 0;

    while(low >= 0 && high < s.length() && s[low] == s[high]){
        low--;
        high++;
        count++;
    }
    return count;
}

int countSubstrings(string s){
    int numPalindromes = 0;

    for(int i = 0; i < s.length(); i++){
        numPalindromes += isPalindrome(s, i, i);
        numPalindromes += isPalindrome(s, i, i+1);
    }
    return numPalindromes;
}

int main(int argc, char** argv){
    string s = "abc";

    cout << countSubstrings(s);
    return 0;
}