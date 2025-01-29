//78
//Given an integer array nums,retunr the power set (all possible subsets)

#include <vector>
#include <set>
#include <iostream>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << " " << nums[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << " " << nums[i];
    }
    cout << "\n";
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> powerSet;

    for(int i = 0; i < nums.size(); i++){
        int n = powerSet.size();
        powerSet.push_back({nums[i]});

        for(int j = 0; j < n; j++){
            vector<int> temp = powerSet[j];
            temp.push_back(nums[i]);
            powerSet.push_back(temp);
        }
    }

    powerSet.insert(powerSet.begin(), vector<int>());
    return powerSet;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 3};

    print2DVector(subsets(nums));
    return 0;
}