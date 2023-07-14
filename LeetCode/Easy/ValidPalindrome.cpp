//After turning all letters to lowercase and removing all non-numebrs and letter, is it a palindrome?
#include <bits/stdc++.h>

using namespace std;

string processString(string s){
    string answer = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 65 && s[i] <= 90){
            answer += s[i]+32;
        }else if(s[i]>= 48 && s[i] <= 57 || s[i] >= 97 && s[i] <= 122){
            answer += s[i];
        }
    }
    return answer;
}

bool isPalindrome(string s){
    int indexFront = 0;
    int indexBack = s.size()-1;

    while(indexFront < indexBack){
        if(s[indexFront] != s[indexBack]){
            return false;
        }
        indexFront++;
        indexBack--;
    }
    return true;
}

int main(){
    string s = " ";

    string processedString = processString(s);
    cout << "The Processed string is: " << processedString << endl;

    if(isPalindrome(processedString)){
        cout << "The solution is a valid palindrome." << endl;
    }else{
        cout << "The solution is not a valid Palindrome. " << endl;
    }
    return 0;
}