//153
//Given an array n of unique increasing numbers rotated between 1 and n times, return the minimum
//Must run in O(logn) time

#include <bits/stdc++.h>

using namespace std;

int findMin2(vector<int> &nums, int i, int j){
    if(i == j){
        return nums[i];
    }

    // cout << i << " " << (j-i)/2 + i << " " << (j - i) / 2 + i + 1 << " " << j << endl;
    // cout << i << " " << j << endl;
    return min(findMin2(nums, i, (j-i)/2 + i), findMin2(nums, (j - i) / 2 + i + 1, j));
}

int findMin(vector<int> &nums){
    return findMin2(nums, 0, nums.size()-1);
}

int main(int argc, char** argv){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << findMin(nums);
    return 0;
}