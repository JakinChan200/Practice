//17
//Given a string containing digits 2-9, return all possible combinations

#include <bits/stdc++.h>

using namespace std;

vector<string> letterCombinations(string digits){
    vector<vector<string>> combs = {{}, {}, {"a", "b", "c"},
                                            {"d", "e", "f"},
                                            {"g", "h", "i"},
                                            {"j", "k", "l"},
                                            {"m", "n", "o"},
                                            {"p", "q", "r", "s"},
                                            {"t", "u", "v"},
                                            {"w", "x", "y", "z"}};

    set<string> combinations;

    vector<string> answer;
    if(digits.size() == 0){
        return answer;
    }

    for(int i = 0; i < combs[digits[0] - '0'].size(); i++){
        combinations.insert(combs[digits[0] - '0'][i]);
    }

    for(int i = 1; i < digits.size(); i++){
        for(auto item : combinations){
            if(item.size() != i){
                continue;
            }

            for(int j = 0; j < combs[digits[i] - '0'].size(); j++){
                combinations.insert("" + item + combs[digits[i] - '0'][j]);
            }
            combinations.erase(item);
        }
    }

    for(string item : combinations){
        answer.push_back(item);
    }

    return answer;
}
