//1046
//Given an array of integers, smack the biggest rocks together
//If its the same, delete both
//If one is bigger than the other, only the difference remains
//Return the final weight if only one rock remains or 0 if none

#include <vector>
#include <algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int endIndex = stones.size()-1;

    while(endIndex >= 1){
        sort(stones.begin(), stones.end() - (stones.size()-1-endIndex));
        if(stones[endIndex] == stones[endIndex-1]){
            // stones[endIndex] = INT_MAX;
            // stones[endIndex-1] = INT_MAX;
            endIndex -= 2;
        }else{
            stones[endIndex-1] = stones[endIndex] - stones[endIndex-1];
            // stones[endIndex] = INT_MAX;
            endIndex -= 1;
        }
    }
    if(endIndex == -1){
        return 0;
    }
    return stones[0];
}