//215
//Return the kth largest, not necessarily the kth distinct element

#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k-1];
}
