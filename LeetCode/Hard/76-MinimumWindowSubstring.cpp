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
    vector<int> map(128, 0);

    for(int i = 0; i < t.size(); i++){
        map[t[i]]++;
    }

    int lowIndex = 0;
    int highIndex = 0;
    int numLetters = t.size();
    int minLength = INT_MAX;
    int minStart = 0;
    int i = 0;
    while(i < s.size()){
        if(map[s[i++]]-- > 0){
            numLetters--;
        }

        while(numLetters == 0){
            if(i - lowIndex < minLength){
                minStart = lowIndex;
                minLength = i - minStart;
            }

            if(map[s[lowIndex++]]++ == 0){
                numLetters++;
            }
        }
    }

    return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
}


// void increaseLowerBound(int &indexLow, int &indexHigh, vector<int> &freq, string s){
//     while(indexLow < indexHigh){
//         if(freq[s[indexLow]] >= 0){
//             return;
//         }
//         if(freq[s[indexLow]] > INT_MIN){
//             freq[s[indexLow]]++;
//         }
//         indexLow++;
//     }
// }

// string minWindow(string s, string t){
//     vector<int> freq(128, INT_MIN);
//     int numLetters = t.size();
//     int indexLow = 0;
//     int indexHigh = 0;
//     vector<int> minLength(3, 0);

//     for(int i = 0; i < t.size(); i++){
//         freq[t[i]] == INT_MIN ? freq[t[i]] = 1 : freq[t[i]]++;
//     }

//     for(int i = 0; i < s.size(); i++){
//         if(freq[s[i]] > 0){
//             freq[s[i]]--;
//             numLetters--;
//             indexHigh = i;
//         }else if(freq[s[i]] > INT_MIN){
//             freq[s[i]]--;
//             indexHigh = i;

//         }

//         // printFreq(freqLowerCase);
//         // cout << numLetters << " " << indexLow << " " << indexHigh << endl;

//         if(numLetters <= 0){
//             increaseLowerBound(indexLow, indexHigh, freq, s);
//             if(minLength[0] == 0 || indexHigh-indexLow+1 < minLength[0]){
//                 minLength = {indexHigh-indexLow+1, indexLow, indexHigh};
//             }
//         }
//     }

//     if(minLength[0] > 0){
//         return s.substr(minLength[1], minLength[0]);
//     }
//     return "";
// }

int main(int argc,char** argv){
    string s = "ab";
    string t = "b";

    string answer = minWindow(s, t);
    cout << answer << endl;
    return 0;
}