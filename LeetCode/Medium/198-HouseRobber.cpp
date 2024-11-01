//198
//Given a vector representing profit from robbing a house, what is the max profit
//You cannot rob two adjacent houses

#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums){
    int runningMax = 0;

    for(int i = 0; i < nums.size(); i++){
        if(i == 2){
            nums[i] += nums[0];
        }
        if(i >= 3){
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        runningMax = max(runningMax, nums[i]);
    }

    return runningMax;
}

int main(int argc, char** argv){

    return 0;
}