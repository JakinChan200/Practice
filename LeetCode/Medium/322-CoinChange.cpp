//322
//Given an array of coin values, and the target amount, return the minimum amount of coins to reach that amount

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << " " << nums[i];
    }
    cout << endl;
}

int coinChange(vector<int> &coins, int amount){
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i = 0; i < dp.size(); i++){
        for(auto c : coins){
            if(i-c >= 0){
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    printVector(dp);
    return dp[amount] == amount+1 ? -1 : dp[amount];
}

int main(int argc, char** argv){
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);
    return 0;
}