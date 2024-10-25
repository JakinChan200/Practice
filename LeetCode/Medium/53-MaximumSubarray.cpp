//53
//Given an integer array nums, find the subarray with the largest sum, and return its sum

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums){
    // vector<int> dp(nums.size(), 0);
    // dp[0] = nums[0];
    int runningMax = nums[0];
    int n  = nums.size();

    for(int i = 1; i < n; i++){
        nums[i] = max(nums[i], nums[i-1] + nums[i]);
        runningMax = max(runningMax, nums[i]);
    }

    return runningMax;
}

int main(int argc, char** argv){
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums = {5, 4, -1, 7, 8};

    cout << maxSubArray(nums);
    return 0;
}