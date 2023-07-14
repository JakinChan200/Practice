//Given two string, check if one is a permutation of the other  

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Compare two substrings
bool isEqual(string checkFirst, string checkSecond){
    vector<vector<char>> charStorage(10, vector<char>(0, 0));
    sort(checkFirst.begin(), checkFirst.end());
    sort(checkSecond.begin(), checkSecond.end());
    return checkFirst == checkSecond;
}

//Window slide through the larger string
//use isEqual to compare a substr of the larger string to the smaller string
bool isPermutation(string smallerString, string largerString){
    for(int i = 0; (i + smallerString.size()) <= largerString.size(); i++){
        if(isEqual(smallerString, largerString.substr(i, smallerString.size()))){
            return true;
        }
    }
    return false;
}

//Check for correct amount of arguments, call isPermutation with the two substrings, and print the result
int main(int argc, char** argv){
    if(argc != 3){
        cout << "Need two total arguments." << endl;
        return 1;
    }

    bool isPerm = false;
    if(strlen(argv[1]) <= strlen(argv[2])){
        if(isPermutation(argv[1], argv[2])){
            isPerm = true;
        }
    }else{
        if(isPermutation(argv[2], argv[1])){
            isPerm = true;
        }
    }

    cout << argv[1] << " and " << argv[2] << " are " << (isPerm ? "" : "not ") << "permutations of each other." << endl; 
    return 0;
}