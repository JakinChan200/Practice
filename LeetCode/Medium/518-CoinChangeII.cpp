//518
//Given an integer array coins and an integer amount, return the amount of combinations

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<long long> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int change(int amount, vector<int> &coins){
    vector<long long> dp(amount+1, 0);
    dp[0] = 1;

    for(int coin : coins){
        for(int j = coin; j <= amount; j++){
            if(dp[j] < INT_MAX - dp[j - coin]){
                dp[j] += dp[j - coin];
            }
        }
    }

    return dp[amount];
}

int main(int argc, char** argv){
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    int answer = change(amount, coins);
    cout << answer << endl;
    return 0;
}
