//70
//Given a number n stairs, you can either take a single step or a double step. Return the number of different ways to climb the stairs.

#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    if(n == 1){
        return 1;
    }

    int One = 1;
    int Two = 1;

    for(int i = 1; i < n; i++){
        int temp = One + Two;
        One = Two;
        Two = temp;
    }
    return Two;
}