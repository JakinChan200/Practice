//242
//Check if two inputs are rearranged versions of each other
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main(int argc, char* argv[]){
    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s, t)){
        cout << "Strings " << s << " and " << t << " are anagrams." << endl;  
    }else{
        cout << "Strings " << s << " and " << t << " are not anagrams." << endl;  
    }
    return 0;
}