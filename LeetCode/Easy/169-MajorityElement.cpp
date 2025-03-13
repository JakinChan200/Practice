//169
//Given an integer array, return the element that appears more than half the time

#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int counter = 0;
    int num;

    for(int i = 0; i < nums.size(); i++){
        if(counter == 0){
            counter++;
            num = nums[i];
        }else{
            if(nums[i] == num){
                counter++;
            }else{
                counter--;
            }
        }
    }
    return num;

}