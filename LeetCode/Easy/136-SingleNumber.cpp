//136
//Given an array of integers, where each element appears twice except for one, return the single one
//Must be linear runtime and constant extra space

#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int sum = 0;
    for(auto element : nums){
        sum ^= element;
    }

    return sum;
}