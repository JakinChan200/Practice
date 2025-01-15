//202
//Given an integer, square each digit and add it
//Keep doing this until a cycle forms or it results in 1
//If it is 1, return true, false otherwise

#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n){
    set<int> nums;

    nums.insert(n);

    while(n != 1){
        int sum = 0;
        while(n > 0){
            sum += pow(n % 10, 2);
            n /= 1;
        }

        if(nums.find(sum) != nums.end()){
            return false;
        }

        n = sum;
    }

    return true;
}