//Given a number, it is colorful if all possible consecutive substrings 
//where it digits are multiplied together, the products are unique. 
//Given a number, print whether it is colorful

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    cout << endl;
    return;
}

vector<int> splitDigits(int num){
    int numLength = to_string(num).size();
    vector<int> answer(numLength);
    for(int i = numLength-1; i >= 0; i--){
        answer[i] = num % 10;
        num /= 10;
    }
    return answer;
}

bool isColorful(int num){
    vector<int> nums = splitDigits(num);
    set<int> combinations;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0 || nums[i] == 1){
            return false;
        }

        int product = 1;
        for(int j = i; j < nums.size(); j++){
            product *= nums[j];
            if(combinations.find(product) != combinations.end()){
                return false;
            }
            combinations.insert(product);
        }
    }
    return true;
}

int main(int argc,  char** argv){
    int num = 2345;
    cout << isColorful(num);
    return 0;
}


//Notes
//https://leetcode.com/discuss/general-discussion/1108184/is-there-a-problem-for-colorful-number-in-leetcode
//https://tutorialhorizon.com/algorithms/colorful-numbers/