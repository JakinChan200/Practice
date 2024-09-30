//3110
//Given a string s, return the sum of the absolute difference between the ASCII values of adjacent characters

#include <bits/stdc++.h>

using namespace std;

int scoreOfString(string s){
    int score = 0;

    for(int i = 0; i < s.size()-1; i++){
        score += abs(s[i] - s[i+1]);
    }

    return score;
}

int main(int argc, char** argv){
    string s = "zaz";

    int score = scoreOfString(s);
    cout << score << endl;
    return 0;
}