//46
//Given an array nums of distinct integers, return all permutations in any order

#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int> &nums, int start, vector<vector<int>> &result){
    if(start == nums.size()){
        result.push_back(nums);
        return;
    }

    for(int i = start; i < nums.size(); i++){
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}