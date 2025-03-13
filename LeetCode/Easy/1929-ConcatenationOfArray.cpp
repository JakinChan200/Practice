//1929
//Given an integer array, return an array of double the length, with the elements as if the initial array was concatenated

#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans(nums.size()*2);

    for(int i = 0; i < nums.size(); i++){
        ans[i] = ans[i+ nums.size()] = nums[i];
    }

    return ans;
}