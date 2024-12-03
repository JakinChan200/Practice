//1431
//Given a vector where each element represents the number of candies a kid has
//and an int representing the extra candies
//return a boolean vector where each element is whether candies[i] + extra candies is the max candies in the vector or greater

#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int x = candies.size();
    vector<bool> res(x);
    int max = *max_element(candies.begin(), candies.end());
    x= 0;
    for (int i : candies) {
        res[x++] = (i + extraCandies) >= max ? true : false;
    }
    return res;
}

int main(int argc, char** argv){
    return 0;
}