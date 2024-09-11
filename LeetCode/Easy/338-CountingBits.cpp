//338
//Given an integer n, return an array where each index stores the amount of 1s in the binary representation of that number up to n

#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr){
    cout << "[";

    if(arr.size() > 0){
        cout << arr[0];
    }

    for(int i = 1; i < arr.size(); i++){
        cout << ", " << arr[i];
    }

    cout << "]" << endl;
}

vector<int> countBits(int n){
    vector<int> final(n+1);
    int temp;
    int counter = 0;

    for(int i = 0; i <= n; i++){
        temp = i;
        counter = 0;

        while(temp > 0){
            counter += temp & 1;
            temp >>= 1;
        }
        final[i] = counter;
    }
    return final;
}

int main(int argc, char** argv){
    int num = 5;
    
    cout << "The answer is: " << endl;
    printArray(countBits(num));

    return 0;
};