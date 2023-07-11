//String Compression: Go from aabcccccaaa to a2b1c5a3.
//If new string longer, then return original

#include <string>
#include <iostream>

using namespace std;

string compressString(string word){
    string newVersion = "";
    int counter = 1;
    for(int i = 0; i < word.size(); i++){
        if(i == 0){
            newVersion += word[i];
        }else if(word[i] != word[i-1]){
            newVersion += to_string(counter) + word[i];
            counter = 1;
        }else if(word[i] == word[i-1]){
            counter++;
        }
    }
    newVersion += to_string(counter);
    return newVersion;
}
int main(int argc, char** argv){
    if(argc != 2){
        cout << "Wrong number of arguments." << endl;
        return 1;
    }

    string shorterVersion = compressString((string)argv[1]);

    //cout << "The shorter version of the string is: " << (shorterVersion.size() < sizeof((string)argv[1])) ? shorterVersion : (string)argv[1] << endl;
    if(shorterVersion.size() < sizeof(argv[1])){
        cout << "The shorter version of the string is: " << shorterVersion << endl;
    }else{
        cout << "The shorter version of the string is: " << argv[1] << endl;
    }
    return 0;
}

//Issues
/*
None so far...
*/