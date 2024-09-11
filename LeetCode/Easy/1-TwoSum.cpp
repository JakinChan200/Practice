//1
//Given a vector and a target, return the index of the two numbers that add up to target
#include <bits/stdc++.h>

using namespace std;

vector<int> TwoSum(vector<int> &nums, int target){
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

//O(2n + logn) solution
//If there are multiples of a number, the answer must be both of them if the answer involves one of them
vector<int> TwoSum2(vector<int> &nums, int target){
    map<int,int> indexes;
    //if(nums.size() == 2) return {0, 1};
    
    for(int i = 0; i < nums.size(); i++){
        if(indexes.find(nums[i]) == indexes.end()){
            indexes[nums[i]] = i;
        }else{
            if(nums[i] * 2 == target){
                return {indexes[nums[i]], i};
            }
        }
    }

    sort(nums.begin(), nums.end());
    
    int lower = 0;
    int higher = nums.size()-1;
    while(lower+1 < higher && nums[lower] + nums[higher] != target){
        if(target - nums[lower] < nums[higher]){
            higher--;
        }else{
            lower++;
        }
    }

    return {indexes[nums[lower]], indexes[nums[higher]]};
}

//Solution for O(n)
vector<int> Solution(vector<int> &nums, int target){
    unordered_map<int, int> indexes;
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++){
        int difference = target - nums[i];
        if(indexes.find(difference) != indexes.end()){
            ans = {indexes[difference], i};
            break;
        }else{
            indexes[nums[i]] = i;
        }
    }
    return ans;
}

int main(int argc, char* argv[]){
    int numInputs = -1;

    do{
        cout << "How many numbers?" << endl;
        cin >> numInputs;
    }while(numInputs < 0);

    vector<int> nums(numInputs);
    int curNum;

    for(int i = 0; i < numInputs; i++){
        curNum = -1;
        // do{
            cout << "Enter number " << i+1 << endl;
            cin >> curNum;
        // }while(curNum < 0);

        nums[i] = curNum;
    }

    int target = 0;
    // do{
        cout << "What is the target?" << endl;
        cin >> target;
    // }while(target < 0);

    vector<int> answer = TwoSum2(nums, target);

    cout << "The answer is: ";
    cout << answer[0] << " and " << answer[1] << endl;

    return 0;
}