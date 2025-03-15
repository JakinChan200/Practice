//299
//Given an integer array ,find all the elements that appear more than 1/3 of the time

#include <vector>
#include <map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    map<int, int> mp;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        mp[nums[i]]++;
    }

    vector<int> ans;
    for(auto element : mp){
        if(element.second > n / 3){
            ans.push_back(element.first);
        }
    }
    return ans;
}