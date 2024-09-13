//371
//Given integers a and b, return the sum without using + and -

#include <bits/stdc++.h>

using namespace std;

int getSum(int a, int b){
    while(b > 0){
        int carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

int main(int argc, char** argv){
    int a = 2;
    int b = 3;

    cout << getSum(a,b);
    return 0;
}