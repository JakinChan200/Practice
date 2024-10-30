//Given a string, print out the frequency of each starting letter in alphabetical order.
//If the frequency is 0, omit it. Capitalization shoulf be considered the same letter

#include <bits/stdc++.h>

using namespace std;

void printFrequency(string s){
    vector<int> freq(26, 0);
    
    for(int i = 0; i < s.size(); i++){
        freq[tolower(s[i]) - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            cout << char('a' + i) << ": " << freq[i] << endl;
        }
    }
    return;
}

int main(int argc, char** argv){
    string s = "dxrfcgvhbjnkmlCRTYVGHUBJnkmldrtfyvgH";
    // string s = "aaaaaaaAAAAAAAAgA";

    printFrequency(s);
    return 0;
}