//268
//Given an array nums, [0, n], return the only number that is missing from the array

#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> & nums){
    sort(nums.begin(), nums.end()+1);

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i){
            return i;
        }
    }
    return nums.size();
}

// int missingNumber(vector<int> & nums){
//     int sum = 0;

//     for(int i = 0; i < nums.size(); i++){
//         sum += nums[i];
//     }
    
//     return nums.size() * (nums.size() + 1) / 2 - sum;
// }