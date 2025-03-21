//704
//Given a sorted vector and a target, return the index of the target or -1 if it does not exist
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;

    while(low <= high){
        int mid = (high - low) / 2 + low;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << "The index of the target is: " << search(nums, target) << endl;
}
