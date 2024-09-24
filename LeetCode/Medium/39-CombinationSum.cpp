//39
//Given an arrray of distinct integers, and a target integer, return a list of all unique combinations of candidates where the chosen numbers sum to target

#include<bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<int>> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i][0];
        for(int j = 1; j < vect[i].size(); j++){
            cout << ", " << vect[i][j];
        }
        cout << endl;
    }
}

void findNumbers(vector<int> &candidates, int target, vector<vector<int>> &answers, vector<int> &curr, int i){
    if(target == 0){
        answers.push_back(curr);
    }

    while(i < candidates.size() && target - candidates[i] >= 0){
        curr.push_back(candidates[i]);
        findNumbers(candidates, target - candidates[i], answers, curr, i);
        i++;
        curr.pop_back();
    }
}   

vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());

    for(int i = 0; i < candidates.size()-1; i++){
        if(candidates[i] == candidates[i+1]){
            candidates.erase(candidates.begin()+i+1);
        }
    }

    vector<int> r;
    vector<vector<int>> res;
    findNumbers(candidates, target, res, r, 0);

    return res;
}

int main(int argc, char** argv){
    
    vector<int> candidates = {2,3, 6, 7};
    int target = 7;

    vector<vector<int>> answers = combinationSum(candidates, target);

    print2DVector(answers);
    return 0;
}