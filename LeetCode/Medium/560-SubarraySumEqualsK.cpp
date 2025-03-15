//560
//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k

#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int, int> mp = {{0, 1}};
    int runningSum = 0;
    int numSubArrays = 0;

    for(int i = 0; i < nums.size(); i++){
        runningSum += nums[i];
        if(mp.contains(runningSum - k)){
            numSubArrays += mp[runningSum - k];
        }

        mp[runningSum]++;
    }
    return numSubArrays;
}