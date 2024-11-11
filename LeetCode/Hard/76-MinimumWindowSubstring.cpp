//76
//Given two strings s and t of lengths m and n, return the minimum window substring of s
//such that all characters in t is included in the window
//If not possible, return empty string ""

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
        cout << endl;
}

void printFreq(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == INT_MIN){
            cout << "0 ";
        }else{
            cout << nums[i] << " ";
        }
    }
        cout << endl;
}

string minWindow(string s, string t){
    vector<int> freq(128, 0);
    int numLetters = t.size();
    int indexLow = 0;
    vector<int> minLength(2, INT_MAX);

    for(int i = 0; i < t.size(); i++){
        freq[t[i]]++;
    }

    for(int i = 0; i < s.size(); i++){
        if(freq[s[i]]-- > 0){
            numLetters--;
        }

        while(numLetters == 0){
            if(i-indexLow+1 < minLength[0]){
                minLength = {i-indexLow+1, indexLow};
            }
            if(freq[s[indexLow++]]++ == 0){
                numLetters++;
            }
        }
    }

    return minLength[0] == INT_MAX ? "" : s.substr(minLength[1], minLength[0]);
}

int main(int argc,char** argv){
    string s = "ab";
    string t = "b";

    string answer = minWindow(s, t);
    cout << answer << endl;
    return 0;
}