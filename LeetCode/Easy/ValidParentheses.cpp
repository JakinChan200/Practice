//Parentheses '()[]{}' must be opened and closed in the correct order
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s){
    stack<char> parans;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            parans.push(s[i]);
        }else{
            if(parans.empty()) return false;
            switch(s[i]){
                case '}':
                    if(parans.top() != '{') return false;
                    parans.pop();
                    break;
                case ']':
                    if(parans.top() != '[') return false;
                    parans.pop();
                    break;
                case ')':
                    if(parans.top() != '(') return false;
                    parans.pop();
                    break;
                default:
                    break;
            }
        }
    }

    return parans.empty() ? true : false;
}

int main(int argc, char* argv[]){
    cout << "Enter parantheses: " << endl;
    string parantheses;
    cin >> parantheses;

    string answer = isValid(parantheses) ? "true" : "false";
    cout << "The string validity is " << answer << endl;
    return 0;
}