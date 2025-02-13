//40
//Given a collection of candidate numbers and target, return all unique combinations in candidates that sum to target
//Each number can only be used once

#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int target, vector<int> &candidates, vector<vector<int>> &solutions, vector<int> &current, int index){
    // printVector(current);
    if(target == 0){
        // sort(current.begin(), current.end());
        solutions.push_back(current);
        return;
    }

    if(target < 0 || index >= candidates.size()){
        return;
    }

    for(int i = index; i < candidates.size(); i++){
        if(i > index && candidates[i] == candidates[i-1]){
            continue;
        }
        current.push_back(candidates[i]);
        backtracking(target-candidates[i], candidates, solutions, current, i+1);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    vector<vector<int>> answers;
    backtracking(target, candidates, answers, current, 0);

    return answers;
}