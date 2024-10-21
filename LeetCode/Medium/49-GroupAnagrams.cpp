//49
//Given an array of strings,groups the anagrams together, may return the answer in any order

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<string>> &strs){
    for(int i = 0; i < strs.size(); i++){
        for(int j = 0; j < strs[i].size(); j++){
            cout << strs[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<string>> groupAnagrams(vector<string> &strs){
    unordered_map<string, vector<string>> map;
    vector<vector<string>> answers;

    for(int i = 0; i < strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        map[temp].push_back(strs[i]);

        // if(map.find(temp) == map.end()){
        //     vector<string> temp2;
        //     temp2.push_back(strs[i]);
        //     map.insert(pair<string, vector<string>>(temp, temp2));
        // }else{
        //     map.at(temp).push_back(strs[i]); 
        // }
    }

    for(auto item : map){
        answers.push_back(item.second);
    }

    return answers;
}

int main(int argc, char** argv){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> answers = groupAnagrams(strs);
    print2DVector(answers);
    return 0;
}