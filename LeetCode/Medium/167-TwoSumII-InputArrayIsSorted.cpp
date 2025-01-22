//167
//Given an array of ascending numbers, return the index of the two numbers that result in the sum
//Cannot use the same element twice

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int end = numbers.size()-1;
    int start = 0;

    while(numbers[start] + numbers[end] != target){
        if(numbers[start] + numbers[end] < target){
            start++;
        }else{
            end--;
        }
    }

    return {start+1, end+1};
}