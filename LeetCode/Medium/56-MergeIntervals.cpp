//56
//Given a 2d vector if intervals, combine all overlapping intervals and return the result

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> merge(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answers;
    answers.push_back(intervals[0]);

    int counter = 0;
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= answers[counter][1] && answers[counter][1] <= intervals[i][1]){
            answers[counter][1] = intervals[i][1];
        }else if(intervals[i][0] > answers[counter][1]){
            answers.push_back(intervals[i]);
        }
        counter = answers.size()-1;
    }
    return answers;
}

int main(int argc, char** argv){
    // vector<vector<int>> input = {{1, 3},
    //                             {3, 6},
    //                             {8, 10},
    //                             {15, 18}};

    vector<vector<int>> input = {{1, 4},
                                {2, 3}};

    vector<vector<int>> answer = merge(input);
    print2DVector(answer);
}