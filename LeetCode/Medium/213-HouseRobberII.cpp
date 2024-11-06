//213
//Given an array, where each element represents profit from robbing a house, what is the max profit?
//You cannot rob two adjacent houses, and it is circular (the last house is next to the first one)

#include <bits/stdc++.h>

using namespace std;

int getMaxProfit(vector<int> nums, int firstIndex, int secondIndex){
    int currMax = 0;

    for(int i = firstIndex; i <= secondIndex; i++){
        if(i == firstIndex+2){
            nums[i] += nums[firstIndex];
        }else if(i >= firstIndex+3){
            nums[i] = max(nums[i]+nums[i-2], nums[i]+nums[i-3]);
        }
        currMax = max(currMax, nums[i]);
    }
    return currMax;
}

int rob(vector<int> &nums){
    if(nums.size() == 1) return nums[0];

    return max(getMaxProfit(nums, 0, nums.size()-2), getMaxProfit(nums, 1, nums.size()-1));
}

int main(int argc,char** argv){
    vector<int> nums = {1, 2, 3, 1};

    cout << rob(nums);
    return 0;
}