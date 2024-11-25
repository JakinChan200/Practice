//50
//Given x and n, return the power

#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n){
    if(n < 0){
        x = 1 / x;
    }

    long num = labs(n);
    double answer = 1;

    while(num > 0){
        if(num & 1){
            answer *= x;
        }
        x *= x;
        num >>= 1;
    }

    return answer;
}

int main(int argc, char** argv){
    double x = 2.0;
    int n = 10;

    double answer = myPow(x, n);
    cout << answer << endl;
    return 0;
}