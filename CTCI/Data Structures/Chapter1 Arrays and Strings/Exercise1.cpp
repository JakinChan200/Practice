//Determine if a string has all unique characters

#include <iostream>
#include <String>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

//CharSlots is the amount of indexes in the hashtable
int charSlots = 20;
vector<vector<char>> totalChars(charSlots, vector<char> (0, 0));

//Compares temp with all the chars seen recently to check if it is unique
//return a boolean value
bool checkUnique(char temp){
    int index = temp%charSlots;
    for(int i = 0; i < totalChars[index].size(); i++){
        if(temp == totalChars[index][i]){
            return false;
        }
    }
    totalChars[index].push_back(temp);
    return true;
}

int main (int argc, char **argv){
    //Root out edge cases
    if(argc == 1){
        cout << "No string input detected." << endl;
        return 1;
    }else if(argc >= 3){
        cout << "Too many string inputs, only one at a time please." << endl;
        return 1;
    }   

    //Run through every char in a string and check if it is unique
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!checkUnique(argv[1][i])){
            printf("The String %s does not only contain unique characters.\n", argv[1]);
            return 0;
        }
    }
    printf("The String %s contains only unique characters.\n", argv[1]);
    return 0;
}

/*
Issues:
command line struggles with certain characters such as ';' and '''

*/