//207
//Given a number numCourses, labeled from 0 to numCourses-1, and
//a 2D array prerequisites, where [1, 0] means you need to take course 0 before 1
//Return whether or not you can make a schedule

#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> paths(numCourses);
    vector<int> numInDegrees(numCourses, 0);
    queue<int> nodes;
    int numCoursesTaken = 0;

    for(int i = 0; i < prerequisites.size(); i++){
        paths[prerequisites[i][0]].push_back(prerequisites[i][1]);
        numInDegrees[prerequisites[i][1]]++;
    }

    for(int i = 0; i < numInDegrees.size(); i++){
        if(numInDegrees[i] == 0){
            nodes.push(i);
        }
    }

    while(!nodes.empty()){
        int temp = nodes.front();
        nodes.pop();
        numCoursesTaken++;

        for(int i = 0; i < paths[temp].size(); i++){
            numInDegrees[paths[temp][i]]--;
            if(numInDegrees[paths[temp][i]] == 0){
                nodes.push(paths[temp][i]);
            }
        }
    }

    return numCoursesTaken == numCourses;
}

int main(int argc, char** argv){
    int numCourses = 2;
    vector<vector<int>> prerequisites({{1, 0}});

    cout << canFinish(numCourses, prerequisites);
    return 0;
}