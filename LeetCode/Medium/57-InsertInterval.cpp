//57
//Given an array of non-overlapping intervals, and a new interval,
//Integrate the new interval and fix all overlapping
//Return the new intervals

#include <bits/stdc++.h>

using namespace std;

void print2DVectors(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newIntervals){
    vector<vector<int>> answers;

    int index = 0;
    while(index < intervals.size() && intervals[index][1] < newIntervals[0]){
        answers.push_back(intervals[index]);
        index++;
    }

    while(index < intervals.size() && newIntervals[1] >= intervals[index][0]){
        newIntervals = {min(intervals[index][0], newIntervals[0]), max(intervals[index][1], newIntervals[1])};
        index++;
    }
    answers.push_back(newIntervals);

    while(index < intervals.size()){
        answers.push_back(intervals[index]);
        index++;
    }

    return answers;
}

// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newIntervals){
//     intervals.push_back(newIntervals);
//     sort(intervals.begin(), intervals.end());

//     vector<vector<int>> answers;
//     answers.push_back(intervals[0]);

//     int counter = 0;
//     for(int i = 1; i < intervals.size(); i++){
//         if(intervals[i][0] <= answers[counter][1] && answers[counter][1] <= intervals[i][1]){
//             answers[counter][1] = intervals[i][1];
//         }else if(intervals[i][0] > answers[counter][1]){
//             answers.push_back(intervals[i]);
//         }
//         counter = answers.size()-1;
//     }
//     return answers;
// }

int main(int argc, char** argv){
    vector<vector<int>> intervals = {{1, 2},
                                {3, 5},
                                {6, 7},
                                {8, 10},
                                {12, 16}};

    // vector<vector<int>> intervals = {{1, 4},
    //                             {2, 3}};

    vector<int> newInterval = {4, 8};
    vector<vector<int>> answers = insert(intervals, newInterval);
    print2DVectors(answers);

    return 0;
}