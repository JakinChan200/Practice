//128
//Given an unsorted array of integers, return the length of the longest consecutive elements

#include <bits/stdc++.h>

using namespace std;

// int longestConsecutive(vector<int> &nums){
//     if(nums.size() <= 1){
//         return nums.size();
//     }

//     set<int> numSet;

//     for(int i = 0; i < nums.size(); i++){
//         numSet.insert(nums[i]);
//     }

//     int currLongest = 1;
//     int currStreak = 1;

//     for(int num : numSet){
//         if(nums[i]+1 == nums[i+1]){
//             currStreak += 1;
//             currLongest = max(currStreak, currLongest);
//         }else{
//             currStreak = 1;
//         }
//     }
//     return currLongest;
// }

int longestConsecutive(vector<int> &nums){
    if(nums.size() == 0){
        return 0;
    }
    sort(nums.begin(), nums.end());

    int currLongest = 1;
    int currStreak = 1;

    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i]+1 == nums[i+1]){
            currStreak += 1;
            currLongest = max(currStreak, currLongest);
        }else if(nums[i] == nums[i+1]){
            continue;
        }else{
            currStreak = 1;
        }
    }
    return currLongest;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 0, 1};

    cout << longestConsecutive(nums) << endl;
    return 0;
};