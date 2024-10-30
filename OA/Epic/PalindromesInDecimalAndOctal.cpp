//Given 2 number inputs, validate that they are positive whole numbers, 
//and then check every number between them in both base 10 (Decimal) and base 8 (Octal). 
//Print all the numbers that are palindromes in both forms.

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int num){
    int temp = num;
    int reversed = 0;

    while(temp > 0){
        int digit = temp % 10;
        reversed = (reversed * 10) + digit;
        temp /= 10;
    }

    return reversed == num;
}

int convertDecimalToOctal(int decimal){
    int octal = 0;
    int digit = 0;

    while(decimal > 0){
        int remainder = decimal % 8;
        decimal /= 8;

        double temp = pow(10, digit);
        octal += (temp * remainder);
        digit++;
    }

    return octal;
}

bool isPositiveWholeNumbers(double num){
    return (unsigned int)num == num;
}

void printValidNumbers(int start, int end){
    if(!isPositiveWholeNumbers(start) || !isPositiveWholeNumbers(end)){
        cout << "Not positive and whole numbers." << endl;
        return;
    }
    
    if(end < start){
        int temp = end;
        end = start;
        start = temp;
    }
    
    for(int i = start+1; i < end; i++){
        if(isPalindrome(i) && isPalindrome(convertDecimalToOctal(i))){
            cout << i << endl;
        }
    }

    return;
}

int main(int argc, char** argv){
    int start = 12;
    int end = 1;

    printValidNumbers(start, end);

    // cout << isPalindrome(9, 8) << endl;
    // cout << isPalindrome(9, 10) << endl;
    // cout << convertDecimalToOctal(9);

    return 0;
}

//Notes
/*
For some reason,
pow(10,3) could equal 100
and remainder could equal 6

but 
pow(10,3) * remainder
will equal 599

and 

int temp = pow(10, 3) 
temp * remainder will equal 99

????????

taking the result of pow() as a double fixed it tho
*/