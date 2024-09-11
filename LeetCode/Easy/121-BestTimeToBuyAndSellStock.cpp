//121
//Given an array price[], pick a day to buy and sell where profit is maximized
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices){
    int maxProf = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i; j < prices.size(); j++){
            maxProf = prices[j] - prices[i] > maxProf ? prices[j] - prices[i] : maxProf;
        }
    }

    return maxProf;
}

int Solution(vector<int> &prices){
    int minimum = INT_MAX;
    int maxProf = 0;

    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < minimum){
            minimum = prices[i];
        }

        maxProf = prices[i] - minimum > maxProf ? prices[i] - minimum : maxProf;
    }
    return maxProf;
}

int main(int argc, char* argv[]){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "The max profit is: " << maxProfit(prices) << endl;
    return 0;
}