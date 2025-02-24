//150
//Given an expression in reverse polish notation, returh the result

#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> operands;

    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*"){
            operands.push(stoi(tokens[i]));
            continue;
        }

        int first = operands.top();
        operands.pop();
        int second = operands.top();
        operands.pop();

        if(tokens[i] == "+"){
            operands.push(first + second);
        }else if(tokens[i] == "-"){
            operands.push(second - first);
        }else if(tokens[i] == "*"){
            operands.push(first * second);
        }else{
            operands.push(second / first);
        }
    }

    return operands.top();
}