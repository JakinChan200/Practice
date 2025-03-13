//75
//Given an integer array with 0, 1, and 2, sort it in place

#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid <= high){
        if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
    }
}