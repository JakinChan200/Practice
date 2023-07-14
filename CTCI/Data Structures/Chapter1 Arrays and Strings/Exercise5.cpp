//Check if two strings are 1 edit away (remove a char, add a char, replace a char)

#include <string>
#include <iostream>

using namespace std;

bool checkStrings(string word1, string word2){
    string shorter = word1;
    string longer = word2;

    //Make sure the shorter word is in the "shorter" variable
    if(word2.size() < word1.size()){
        shorter = word2;
        longer = word1;
    }

    //If the difference in word length is greater than 1, return false
    //Otherwise, note the difference
    if(longer.size() - shorter.size() >= 2) return false;
    int numChanges = longer.size()-shorter.size();

    //Iterate both words, if not equal, check if the next one is the same, and reset the base
    //Track the number of differences in numChanges
    int j = 0;
    for(int i = 0; i < shorter.size() && j < longer.size(); i++, j++){
        if(shorter[i] == longer[i]){
            continue;
        }else{
            if(shorter[i] == longer[j+1]){
                j++;
            }else if(longer[j] == shorter[i+1]){
                i++;
            }
            numChanges++;
        }
        if(numChanges > 1) return false;
    }
    return true;
}

int main(int argc, char** argv){
    if(argc != 3){
        cout << "Incorrect amount of arguments." << endl;
        return 1;
    }

    if(checkStrings((string)argv[1], (string)argv[2])){
        cout << "There are only 1 or less changes between the strings" << endl;
    }else{
        cout << "There are more than 1 changes between the strings" << endl;
    }

    return 0;
}


//Issues
/*
If trying to expand this to multiple changes, there might be error where one will reach the end of the word before the other.
In that case, it is imperative to track the differences at the end instead of at the beginning, or both.
*/