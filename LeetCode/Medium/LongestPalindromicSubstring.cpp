//5
//Given a string,return the longest palindromic substriong in s

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s){
    if(s.size() <= 1){
        return s;
    }

    int longest = 1;
    int lowIndex = 0;
    int highIndex = 0;

    for(int i = 0; i < s.size(); i++){
        int low = i-1;
        int high = i+1;

        //Center is i
        while(low >= 0 && high < s.size() && s[low] == s[high]){
            if((high - low) + 1 > longest){
                lowIndex = low;
                highIndex = high;
                longest = (high - low) + 1;
            }
            low--;
            high++;
        }

        low = i;
        high = i+1;

        //Center is between two letters
        while(low >= 0 && high < s.size() && s[low] == s[high]){
            if((high - low) + 1 > longest){
                lowIndex = low;
                highIndex = high;
                longest = (high - low) + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(lowIndex, longest);
}

int main(int argc, char** argv){
    string word = "bb";
    cout << longestPalindrome(word);
}