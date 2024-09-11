//191
//Given an int, return how many 1s are in the binary representation

#include <bits/stdc++.h>

using namespace std;

int hammingWeight(int n){
    int numOnes = 0;

    while(n){
        numOnes += n & 1;
        n = n >> 1;
    }
    return numOnes;
}


int main(int argc, char** argv){
    int number = 3;

    cout << "The number: " << number << " has " << hammingWeight(number) << " bits set to 1." << endl;
    return 1;
}