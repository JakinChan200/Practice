//746
//Given an array cost, where cost[i] is the cost, and you can decide 1 or two steps
//Starting from index 0 or 1, return the minimum cost to reach the top floor

#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> sum(cost.size()+1, 0);

    for(int i = 2; i < sum.size(); i++){
        sum[i] = min(sum[i-1] + cost[i-1], sum[i-2] + cost[i-2]);
    }

    return sum[sum.size()-1];
}