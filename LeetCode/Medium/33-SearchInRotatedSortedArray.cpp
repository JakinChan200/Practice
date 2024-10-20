//33
//Given a rotated array, return the index of the number, and -1 if it doesn't exist

#include <bits/stdc++.h>

using namespace std;

int search2(vector<int> &nums, int target, int i, int j){
    if(i == j){
        if(nums[i] == target){
            return i;
        }else{
            return -1;
        }
    }

    return max(search2(nums, target, i, i + ((j-i) / 2)), search2(nums, target, i + ((j-i) / 2) + 1, j));
}


int search(vector<int> &nums, int target){
    // return search2(nums, target, 0, nums.size()-1);
    int left = 0;
    int right = nums.size()-1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(target == nums[mid]){
            return mid;
        }
        if(nums[left] <= nums[mid]){
            if(target < nums[mid] && target >= nums[left]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{
            if(target <= nums[right] && target > nums[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }

    return -1;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 3};
    int target = 2;

    cout << search(nums, target) << endl;
    return 0;
}