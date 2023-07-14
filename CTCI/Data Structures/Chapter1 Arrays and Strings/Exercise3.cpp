//Given a string, replace the spaces with "%20"

#include <string>
#include <iostream>
#include <cstring>

using namespace std;

//replace the spaces with "%20"
string processString(string term){
    string noSpaceString = "";
    for(int i = 0; i < term.length(); i++){
        if(term[i] == 32){
            noSpaceString += "%20";
        }else{
            noSpaceString += term[i];
        }
    }
    return noSpaceString;
}

//Puttina an array of words into a string
string buildString(char** input, int numWords){
    string words = input[1];
    for(int i = 2; i <= numWords; i++){
        words += " ";
        words += input[i];
    }
    return words;
}

//Combination of buildString and processString
string replaceSpaces(char** input, int numWords){
    string words = input[1];
    for(int i = 2; i <= numWords; i++){
        words += "%20";
        words += input[i];
    }
    return words;
}

int main(int argc, char **argv){
    //Check if too few arguments
    if(argc <= 2){
        cout << "Missing or too many arguments." << endl;
        return 1;
    }

    //Check if the number entered is only numbers
    for(int i = 0; i < strlen(argv[argc-1]); i++){
        if(argv[argc-1][i] > 57 || argv[argc-1][i] < 48){
            cout << "Last argument must be a number." << endl;
            return 1;
        }
    }

    //Checking if the answer is what the amount of letters it was supposed to be
    //string answer = processString(buildString(argv, argc-2));
    string answer = replaceSpaces(argv, argc-2);
    int numChars = stoi(argv[argc-1]);
    if(answer.length() != numChars){
        cout << "The output string does not match the predicted length. You inputted " << numChars << ", but the actual length was " << answer.length() << endl;
        return 1;
    }

    cout << "The output string is: \"" << answer << "\"" << endl;

    return 0;
}

//Issues
/*
Interpreted question wrong, the number is supposed to be how many letters total in initial string and not the final string

*/