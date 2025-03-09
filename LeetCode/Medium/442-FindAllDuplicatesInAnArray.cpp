//442
//Given an integer array nums of length n, filled with integers 1 to n, and each appears at most twice
//return an array of the elements that appear twice

#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> answers;

    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) -1;
        if(nums[index] < 0){
            answers.push_back(index+1);
        }else{
            nums[index] = -nums[index];
        }
    }
    return answers;
}