//300
//Given an array nums, return the length of the longest strictly increasing subsequence (can delete numbers)

#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int> &nums){
    vector<int> answers(nums.size(), 1);
    int runningMax = 1;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            if(nums[i] < nums[j] && answers[i] + 1 > answers[j]){
                answers[j] = answers[i] + 1;
            }
        }
        runningMax = max(answers[i], runningMax);
    }
    return runningMax;
}

int main(int argc, char** argv){
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};

    cout << lengthOfLIS(nums);
    return 0;
}