//217
//Given an array, return true if any value appears at least twice

#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int> &nums){
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }
    return false;
}

// bool containsDuplicate(vector<int> &nums){
//     set<int> intSet;

//     for(int i = 0; i < nums.size(); i++){
//         intSet.insert(nums[i]);
//     }

//     if(intSet.size() != nums.size()){
//         return true;
//     }
//     return false;
// }

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << containsDuplicate(nums) << endl;
    return 0;
};