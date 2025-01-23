//66
//Given an array that represents digits, increment the number in the one's place by 1 and return

#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    digits[digits.size()-1]++;
    int carry = 0;

    for(int i = digits.size()-1; i >= 0; i--){
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] = digits[i] % 10;
        
        if(carry == 0){
            return digits;
        }
    }

    digits.insert(digits.begin(), carry);
    return digits;
}