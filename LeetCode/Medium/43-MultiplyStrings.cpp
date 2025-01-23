//43
//Given two non-negative integers num1 and num2 represented as strings, multiply them and return as a string

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << " " << nums[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

string multiply(string num1, string num2){
    if(num1 == "0" || num2 == "0"){
        return "0";
    }

    int intLength = max(num1.size(), num2.size());
    int tableSize = intLength*2;

    vector<vector<int>> table(3, vector<int>(tableSize, 0));

    for(int i = 0; i < num1.size(); i++){
        table[0][tableSize-num1.size()+i] = num1[i] - '0';
    }

    for(int i = 0; i < num2.size(); i++){
        table[1][tableSize-num2.size()+i] = num2[i] - '0';
    }

    // printVector(table);

    for(int i = tableSize-1; i >= 0; i--){
        for(int j = tableSize-1; j >= tableSize - intLength; j--){
            if(table[1][i] == 0 || table[0][j] == 0){
                continue;
            }
            table[2][i - (tableSize-1-j)] += (table[1][i] * table[0][j]);
        }
        // printVector(table);
    }

    // cout << "before Carry" << endl;
    // printVector(table);

    for(int i = tableSize-1; i > 0; i--){
        table[2][i-1] += table[2][i] / 10;
        table[2][i] = table[2][i] % 10;
    }

    // printVector(table);

    string answer = "";
    bool isLeading = true;
    for(int i = 0; i < tableSize; i++){
        if(isLeading && table[2][i] == 0){
            continue;
        }

        if(table[2][i] != 0){
            isLeading = false;
        }
        answer += to_string(table[2][i]);
    }

    return answer;
}

int main(int argc, char** argv){
    string num1 = "2";
    string num2 = "3";

    cout << multiply(num1, num2) << endl;
    return 0;
}