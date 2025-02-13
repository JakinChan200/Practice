//47
//Given a collection of numbers, nums,that might contain duplicates,return all possible unique permutations in any order

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
}


void backwards(vector<vector<int>> &answers, int index, vector<int> nums, set<vector<int>> &solutions){
    if(solutions.find(nums) == solutions.end()){
        solutions.insert(nums);
        answers.push_back(nums);
    }
    
    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i-1]){
            continue;
        }
        swap(nums[index], nums[i]);
        backwards(answers, index+1, nums, solutions);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums){
    vector<vector<int>> answer;
    set<vector<int>> solutions;
    sort(nums.begin(), nums.end());
    backwards(answer, 0, nums, solutions);
    return answer;
}
