//525
//Return the length of the largest subarray with the same number of 0s and 1s

#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    int sum = 0;
    int maxLength = 0;
    unordered_map<int, int> seen{{0, -1}};

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i] == 1 ? 1 : -1;
        if(seen.count(sum)){
            maxLength = max(maxLength, i-seen[sum]);
        }else{
            seen[sum] = i;
        }
    }

    return maxLength;
}