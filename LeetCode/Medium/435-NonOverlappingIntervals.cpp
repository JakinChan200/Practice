//435
//Given an array of intervals, return the minimum number of intervals
//you need to remove to make the rest of the intervals overlapping
//overlapping does not include when the end and start of an interval are equal

#include <bits/stdc++.h>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    int removeCounter = 0;
    int prev = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++){
        if(prev > intervals[i][0]){
            prev = min(prev, intervals[i][1]);
            removeCounter++;
        }else{
            prev = intervals[i][1];
        }
    }

    return removeCounter;
}

int main(int argc, char** argv){
    vector<vector<int>> intervals = {{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {1, 3}};

    cout << eraseOverlapIntervals(intervals);

    return 0;
}