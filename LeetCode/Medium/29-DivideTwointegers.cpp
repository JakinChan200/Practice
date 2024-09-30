//29
//Given two integers divident and divisor, divide the two integers without using multiplication, division, and mod operator
//Truncate decimals

#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor){
    int answer = 0;
    int numNegatives = 0;

    if(dividend == INT_MIN && divisor == 1){
        return INT_MIN;
    }

    if(dividend < 0){
        numNegatives++;
    }

    if(divisor < 0){
        numNegatives++;
    }

    long divid = abs((long)dividend);
    long divis = abs((long)divisor);

    cout << divid << " " << divis << endl;
    while (divid >= divis) {
        long temp = divis, multiple = 1;
        while (divid >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        divid -= temp;
        answer += (int)multiple;
    }
    // while(divid >= divis){
    //     int counter = 0;
    //     while(divid > (divis << (counter + 1))){
    //         counter++;
    //     }
    //     divid -= divis << counter;
    //     answer +=  1 << counter;
    // }
    // while(dividend - divisor > 0){
    //     int counter = 1;
    //     int tempDivisor = divisor;



    //     while((tempDivisor << 1) < dividend && counter << 1 < INT_MAX){
    //         tempDivisor <<= 1;
    //         counter <<= 1;
    //     }

    //     if(answer + counter > INT_MAX-1){
    //         answer = INT_MAX;
    //         dividend = -1;
    //     }else{
    //         answer += counter;
    //     }

    //     dividend -= tempDivisor;
    //     cout << dividend << " " << divisor << endl;
    // }

    // if(answer >= (1 << 31)){
    //      answer = INT_MAX;
    // }

    cout << answer << endl;
    if(answer < 0){
        answer = INT_MAX;
    }

    cout << answer << endl;
    if(numNegatives == 1){
        answer = ~answer + 1;
    }

    return answer;
}

int main(int argc, char** argv){
    int dividend = 10;
    int divisor = 3;

    int answer = divide(dividend, divisor);
    cout << answer << endl;
    return 0;
}