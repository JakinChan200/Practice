//485
//GTiven a binary array nums, return the maximum number of consecutive 1s in the array

#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){
    int runningLargest = nums[0] == 1 ? 1 : 0;
    int n = nums.size();

    for(int i = 1; i < n; i++){
        if(nums[i] == 1){
            nums[i] += nums[i-1];
        }else{
            runningLargest = max(nums[i-1], runningLargest);
        }
    }

    return max(runningLargest, nums[n-1]);
}

int main(int argc, char** argv){
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(nums);
    return 0;
}