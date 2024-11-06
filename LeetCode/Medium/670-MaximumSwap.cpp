//Given an integer num, you can swap two digits at most to get the maximum valued number
//Return that max value

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> digits){
    for(int i = 0; i < digits.size(); i++){
        cout << digits[i] << endl;
    }
}

vector<int> breakDownNum(int num){
    vector<int> solution;

    while(num > 0){
        solution.emplace_back(num%10);
        num /= 10;
    }

    reverse(solution.begin(), solution.end());
    return solution;
}

int buildNum(vector<int> digits){
    int solution = 0;

    for(int i = 0; i < digits.size(); i++){
        solution *= 10;
        solution += digits[i];
    }

    return solution;
}

int maximumSwap(int num){
    vector<int> digits = breakDownNum(num);
    int indexOfMax = digits.size()-1;
    int left = -1;
    int right = -1;

    for(int i = digits.size()-2; i >= 0; i--){
        if(digits[i] > digits[indexOfMax]){
            indexOfMax = i;
        }else if(digits[i] < digits[indexOfMax]){
            left = i;
            right = indexOfMax;
        }
    }
    if(left == -1) return num;
    swap(digits[left], digits[right]);
    return buildNum(digits);
}

int main(int argc, char** argv){
    int num = 2736;

    cout << maximumSwap(num) << endl;
    return 0;
}