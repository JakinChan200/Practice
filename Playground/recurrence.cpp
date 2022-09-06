#include <iostream>
#include <math.h>

using namespace std;

float factorial(int n){
    float answer = 1;
    for(int i = n; i > 1; i--){
        answer *= i;
    }
    return answer;
}

float combination(int n, int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

int main(int argc, char** argv){
    float frac;
    for(int i = 0; i < 20; i++){
        //frac = (float)i/20;
        cout << "t: " << (float)frac << " " << combination(stoi(argv[1]), stoi(argv[2]))*pow(frac, stoi(argv[2])) << endl;
    }
    //float comb = combination(stoi(argv[1]), stoi(argv[2]));
    //cout << comb << endl;
}