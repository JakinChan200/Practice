//190
//Given an uint32_t, return the reversed bit version

#include <bits/stdc++.h>

using namespace std;

uint32_t reverseBits(uint32_t n){
    uint32_t answer;

    for(int i = 0; i < 32; i++){
        answer <<= 1;
        answer |= n & 1;
        n >>= 1;
    }

    return answer;
}

int main(int argc, char** argv){
    uint32_t temp = 43261596;

    cout << reverseBits(temp);
    return 0;
};