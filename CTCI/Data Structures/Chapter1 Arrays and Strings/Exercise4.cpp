//Given a string, check if it is a permutation of a palindrome

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct letter{
    char letter;
    int num;
};

//vector<vector<letter>> letterList(10);
vector<vector<string>> letterList(10);
vector<int> letterLists(200, 0);

bool checkPalindrome(const string input){
    int oddCount = 0;
    for(int i = 0; i < input.length(); i++){
        if(letterLists[input[i]] != 0){
            if(letterLists[input[i]]%2 == 0){
                letterLists[input[i]] += 1;
                oddCount++;
            }else{
                letterLists[input[i]] += 1;
                oddCount--;
            }
        }else{
            letterLists[input[i]] += 1;
            oddCount++;
        }
    }
    cout << oddCount << endl;
    return oddCount <= 2 ? true : false;
}

string combineArguments(char** arguments, int numArguments){
    string answer = arguments[1];
    for(int i = 2; i < numArguments; i++){
        answer += " ";
        answer += arguments[i];
    }
    return answer;
}

int main(int argc, char** argv){
    if(!argc > 1){
        cout << "Not enough arguments." << endl;
        return 1;
    }

    if(checkPalindrome(combineArguments(argv, argc))){
        cout << "A Palindrome exists." << endl;
    }else{
        cout << "A Palindrome does not exist." << endl;
    }
    return 0;
}

//Issues
/*
Does not work against a mixture of upper and lowercase
prob fix this later
*/