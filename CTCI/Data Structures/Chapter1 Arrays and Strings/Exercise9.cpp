//Check if string s2 is a rotation of string s1 using one call to isString
#include <string>
#include <iostream>

using namespace std;

bool isSubString(string s1, string s2){
    if(s1.size() != s2.size()){
        return false;
    }

    bool isCurCorrect = false;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s2[0]){
            if(s1.substr(i, s1.size()-i) == s2.substr(0, s1.size()-i) && s1.substr(0, i) == s2.substr(s1.size()-i, i)){
                return true;
            }
        }
    }
    // int counter = 0;
    // while(counter < s1.size() && s1[0] != s2[0]){
    //     if(counter >= s1.size()){ return false;}
    //     string temp = s1.substr(s1[1], s1.size());
    //     temp += s1[0];
    //     s1 = temp;
    // }



    // for(int i = 0; i < s1.size(); i++){
    //     if(s1[i] != s2[i]){
            
    //     }
    // }
    return false;
}

int main(int argc, char** argv){
    if(argc != 3){
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }
    
    bool isTrue = isSubString(argv[1], argv[2]);

    if(isTrue){
        cout << argv[1] << " is a substring of " << argv[2] << "." << endl;
    }else{
        cout << argv[1] << " is not a substring of " << argv[2] << "." << endl;
    }
    return 0;
}

//Issues
/*
Used 2 Hints
    1. The word is essentially split into two parts, with one part in front of the other
    2. Is there a way to split the word into two parts

    I tried to iterate through the entire word trying everything => the solution now is a lot simpler

Spaces don't work
*/

