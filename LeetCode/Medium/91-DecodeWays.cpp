//91
//Given a string, where "1" -> A, "2" -> B ...
//Return how many ways the string can be decoded given that "25" could be "2" and "5"

#include <bits/stdc++.h>

using namespace std;

int numDecodings(string s){
    vector<int> numPerm(s.size()+1, 0);
    if(s[0] == '0'){
        return 0;
    }

    numPerm[0] = 1;
    numPerm[1] = 1;

    for(int i = 2; i <= s.size(); i++){
        // if(s[i] == '0'){
        //     if(s[i-1] == '0' || stoi(s.substr(i-1, 2)) > 26){
        //         return 0;
        //     }
        // }
        
        if(s[i-1] != '0'){
            numPerm[i] += numPerm[i-1];
        }

        if(stoi(s.substr(i-2, 2)) <= 26 && s[i-2] != '0'){
            numPerm[i] += numPerm[i-2];
        }

        // if(i == 1){
        //     if(stoi(s.substr(i-1, 2)) <= 26 && s[i] != '0'){
        //         numPerm[i] = 2;
        //     }
        // }
        // if(i > 1){
        //     if(s[i] == '0'){
        //         numPerm[i] = numPerm[i-2];
        //     }else if(stoi(s.substr(i-1, 2)) <= 26 && s[i-1] != '0'){
        //         numPerm[i] = numPerm[i-1] + numPerm[i-2];
        //     }else{
        //         numPerm[i] = numPerm[i-1];
        //     }
        // }
    }
    return numPerm[numPerm.size()-1];
}

int main(int argc, char** argv){
    string s = "2101";

    int answer = numDecodings(s);
    cout << answer << endl;
    return 0;
}