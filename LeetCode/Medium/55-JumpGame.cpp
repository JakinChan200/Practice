//55
// Given an integer nums and each element represents the maximum jump length at the position

#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int> &nums){
    int counter = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(counter == 0){
            return false;
        }

        if(counter > nums[i]){
            counter--;
        }else{
            counter = nums[i];
        }
    }
    return true;
}

int main(int argc, char** argv){
    vector<int> nums = {2, 3, 1, 1, 4};

    bool answer = canJump(nums);
    cout << answer << endl;

    return 0;
}