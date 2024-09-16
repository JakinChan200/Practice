//347
//Given an integer array nums and intefer k,return the k most frequent elements in any order

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    cout << "{";
    if(nums.size() == 0){
        cout << "}" << endl;
        return;
    }
    cout << nums[0];

    for(int i = 1; i < nums.size(); i++){
        cout << ", " << nums[i];
    }
    cout << "}" << endl;
}

struct compareTo{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> numbers;

    for(int i = 0; i < nums.size(); i++){
        numbers[nums[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,compareTo> NumFrequency;
    for(auto nummies : numbers){
        NumFrequency.push(nummies);
    }

    vector<int> answer(k);
    for(int i = 0; i < k; i++){
        answer[i] = NumFrequency.top().first;
        NumFrequency.pop();
    }
    return answer;
}

int main(int argc,char** argv){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> answers = topKFrequent(nums, k);
    printVector(answers);
    return 0;
}