//1143
//Given 2 strings, return the length of the longest common subsequence. If there is none, return 0

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int longestCommonSubsequence(string text1, string text2){
    int n = text1.size();
    int m = text2.size();

    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                curr[j] = prev[j-1] + 1;
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        print2DVector(prev);
        print2DVector(curr);
        prev = curr;
    }

    return prev[m];
}

int main(int argc, char** argv){
    string text1 = "abcde";
    string text2 = "ace";

    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}