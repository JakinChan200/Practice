//2220
//Given a start and a goal int, return the number of bit flips to get from the start int to the goal int

#include <bits/stdc++.h>

using namespace std;

int minBitFlips(int start, int goal){
    int numChanges = 0;

    while(start > 0 || goal > 0){
        numChanges += (start & 1) != (goal & 1);
        start = start >> 1;
        goal = goal >> 1;
    }

    return numChanges;
}

int main(int argc, char** argv){
    int start = 3;
    int goal = 4;

    cout << minBitFlips(start, goal) << endl;
    return 0;
}