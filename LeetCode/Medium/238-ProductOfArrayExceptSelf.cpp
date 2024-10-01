//238
//Given an integer array num,return an array answer such that answer[i] is equal to the product of all of the elements of num except nums[i]
//It needs to run in O(n) and no division operation

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i <nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int> &nums){
    vector<int> answer(nums.size(), 1);

    int j = nums.size()-2;
    int runningCounter = 1;
    int runningLeftCounter = 1;

    for(int i = 1; i < nums.size(); i++){
        runningLeftCounter *= nums[i-1];
        answer[i] *= runningLeftCounter;

        runningCounter *= nums[j+1];
        answer[j] *= runningCounter;
        j--;
    }

    return answer;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 3, 4};

    vector<int> answers = productExceptSelf(nums);
    printVector(answers);
    return 0;
}

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
