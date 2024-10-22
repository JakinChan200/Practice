//152
//Given an integer array nums, find a subarray that has the largest product and return the product

#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &nums){
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int runningMax = nums[0];

    for(int i = 1; i < nums.size(); i++){
        int temp  = minProduct;
        minProduct = min(nums[i], min(minProduct*nums[i], maxProduct*nums[i]));
        maxProduct = max(maxProduct*nums[i], max(nums[i], temp*nums[i]));

        runningMax = max(runningMax, maxProduct);
    }
    return max(maxProduct, runningMax);
}

int main(int argc, char** argv){
    vector<int> nums = {-2, 3, -4};

    cout << maxProduct(nums);

    return 0;
}