//62
//Given an m and n (sides to a grid), how many unique paths to go from top left to bottom right?

#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n){
    int paths = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if(m == 1){
        return 1;
    }


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0){
                dp[i][j] = 1;
            }else{
                if(j != 0){
                    dp[i][j] += dp[i][j-1];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
    }

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         if(i != 0 && i != m-1){
    //             paths++;
    //         }

    //         if(j != 0 && j != n-1){
    //             paths++;
    //         }
    //     }
    // }
    return dp[dp.size()-1][dp[dp.size()-1].size()-1];
}

int main(int argc, char** argv){
    int m = 3;
    int n = 2;

    int answer = uniquePaths(m, n);
    cout << answer << endl;
}