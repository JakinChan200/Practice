//16
//Given an integer array numbers of length n and an integer target, find three integers in nums that are the closest to target
//return the sum

#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = INT_MAX / 2;

    for(int i = 0; i < nums.size() - 2; i++){
        int left = i+1;
        int right = nums.size()-1;

        while(left < right){
            int currSum = nums[left] + nums[right] + nums[i];
            if(abs(closestSum - target) > abs(currSum - target)){
                closestSum = currSum;
            }

            if(currSum < target){
                left += 1;
            }else{
                right -= 1;
            }
        }
    }
    return closestSum;
}