//72
//Given strings word1 and word2, return the minimum number of operations required to convert word1 to word2
//This includes inserting, deleting, or replacing a character

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << " " << nums[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
int minDistance(string word1, string word2){
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= m; i++){
        dp[i][0] = i;
    }

    for(int j = 1; j <= n; j++){
        dp[0][j] = j;
    }

    print2DVector(dp);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(word1[i-1] == word2[j-1]){ //If same letter
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }                   //replace       delete       insert
        }
        print2DVector(dp);
    }

    return dp[m][n];
}

int main(int argc, char** argv){
    string word1 = "horse";
    string word2 = "ros";


    cout << minDistance(word1, word2);
    return 0;
}