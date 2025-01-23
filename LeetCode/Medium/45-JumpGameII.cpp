//45
//Given a 0-index aray of integers nums of length n, where each element is the maximum length you can jump
//Return the minimum number of jumps to reach the end

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << " " << nums[i];
    }
    cout << "\n";
}

int jump(vector<int> &nums){
    int n = nums.size();
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for(int i = 0; i < n-1; i++){
        farthest = max(farthest, i + nums[i]);
        if(i == current_end){
            jumps++;
            current_end = farthest;
        }
    }

    return jumps;
}

// int jump(vector<int>& nums) {
//     vector<int> numJumps(nums.size(), 10000);
//     numJumps[0] = 0;

//     // printVector(numJumps);

//     for(int i = 0; i < nums.size(); i++){
//         int jump = numJumps[i] + 1;
//         for(int j = i+1; j <= i+nums[i]; j++){
//             // cout << j << endl;
//             if(j >= nums.size()){
//                 break;
//             }
//             if(jump < numJumps[j]){
//                 numJumps[j] = jump;
//             }
//         }
//         // printVector(numJumps);
//     }

//     return numJumps[numJumps.size()-1];
// }

int main(int argc, char** argv){
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << jump(nums) << endl;
    return 0;
}