//11
//Given an integer array height of length n, there are n vertical lines described by its height in int
//Return the largest volume that can be created with any two lines as boundaries

#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height){
    int i = 0;
    int j = height.size()-1;
    int maxVolume = (j-i) * min(height[i], height[j]);

    while(i < j){
        maxVolume = max(maxVolume, (j-i) * min(height[i], height[j]));
        
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }

    return maxVolume;
}

int main(int argc, char** argv){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height);
    return 0;
}