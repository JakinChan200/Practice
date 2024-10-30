//Given an array, a good subarray is where contiguous sunbsequent elements 
//are a difference of 1 from each other
//Return the sum of all good subarrays

#include <bits/stdc++.h>

using namespace std;

int sumGoodSubArray(vector<int> nums){
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int runningSum = nums[i];
        for(int j = i+1; j < nums.size(); j++){
            if(abs(nums[j] - nums[j-1]) <= 1){
                runningSum += nums[j];
                sum += runningSum;
            }else{
                 j = nums.size();
                 break;
            }
        }
    }
    return sum;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 8};

    cout << sumGoodSubArray(nums) << endl;
    return 0;
}