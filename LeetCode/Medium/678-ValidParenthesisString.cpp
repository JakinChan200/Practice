//678
//Given a string "(", ")", "*", where "*" can be open, closed, or "", return boolean if it is valid

#include <bits/stdc++.h>

using namespace std;

bool checkValidString(string s) {
    int cmin = 0;
    int cmax = 0;

    for(char c : s){
        if(c == '('){
            cmax++;
            cmin++;
        }

        if(c == ')'){
            cmax--;
            cmin = max(cmin - 1, 0);
        }

        if(c == '*'){
            cmax++;
            cmin = max(cmin - 1, 0);
        }

        if(cmax < 0) return false;
    }

    return cmin == 0;
}