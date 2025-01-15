//973
//Given an array of points [x,y], and a number k, return a 2D array of the k closest to the origin
//Use euclidean distance

#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(const pair<double, int> a, const pair<double, int> b){
        return a.first > b.first;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k){
    priority_queue<pair<double, int>, vector<pair<double, int>>, Compare> coords;

    for(int i = 0; i < points.size(); i++){
        coords.push(pair<double, int>((double)pow((double)pow(points[i][0], 2) + pow(points[i][1], 2), 0.5), i));
    }

    vector<vector<int>> closest;

    for(int i = 0; i < k; i++){
        closest.push_back(points[coords.top().second]);
        coords.pop();
    }

    return closest;
}