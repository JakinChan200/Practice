//90
//Given an intger array nums that may contain duplicates, return the power set (all possible subsets)

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void backTrack(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result){
    result.push_back(current);
    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i-1]){
            continue;
        }

        current.push_back(nums[i]);
        backTrack(nums, i + 1, current, result);
        current.pop_back();
    }

}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());
    backTrack(nums, 0, current, result);
    return result;
}