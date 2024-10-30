//Suppose you have a string that you want to put on a Google Doc. 
//However, the Google Doc has a page width. 
//So if the string length, exceeds the page width, it will go to the next line.
//Given the input string and page width, return the number of lines needed.

//part 2: Now let's say we have a table with column a and column b. 
//We now have two string inputs: one for column a and one for column b. 
//We also have the table width, where the table width will be 
//the width of column a plus the width of column b. 
//What width should column a be to minimize the amount of rows needed to display?

#include <bits/stdc++.h>

using namespace std;

//assumes every character is the same width, and pageWidth is the number of characters
//Commented parts are for printing out a test
int numLinesNeeded(string s, int pageWidth){
    vector<string> codeTest;    //Testing the Code
    int lineCounter = 0;
    int lineBreakIndex = 0;
    int recentSpace = 0;

    for(int i = 0; i < s.size(); i++){
        if(i - lineBreakIndex > pageWidth){
            if(recentSpace == lineBreakIndex){
                codeTest.push_back(s.substr(lineBreakIndex, i-lineBreakIndex-2) + '-');
                lineBreakIndex = i-2; //Adding a hyphen
                recentSpace = lineBreakIndex;
            }else{
                codeTest.push_back(s.substr(lineBreakIndex, recentSpace - lineBreakIndex));
                lineBreakIndex = recentSpace; //resetting to last space
            }
            lineCounter++;
        }else if(s[i] == ' '){
            recentSpace = i+1;
        }
    }

    if(lineBreakIndex < s.size()){
        lineCounter++;
        codeTest.push_back(s.substr(lineBreakIndex, s.size() - lineBreakIndex));
    }
    for(int i = 0; i < codeTest.size(); i++){
        cout << i+1 << codeTest[i] << " " << codeTest[i].size() << endl;
    }
    return lineCounter;
}

int columnWidth(string columnA, string columnB, int tableWidth){
    return ((double)tableWidth / (columnA.size() + columnB.size())) * columnA.size();
}

int main(int argc, char** argv){
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean porta elit nulla, ac fermentum lacus volutpat non. Aenean ac velit quis lectus fringilla aliquam quis id sapien. Integer mollis elit eu sodales faucibus. Nam in dictum leo, ac tempor mauris. Curabitur non velit a purus vestibulum finibus non rhoncus libero. In sed urna at lectus facilisis porta vel vehicula lacus. Ut dui dolor, malesuada ac cursus ac, posuere sed nibh.";
    string t = "sdrtfgvhbjnkrxdctfgvhjbkntcfygvhbjnkmeetdrfgyhubijktfrgyvbhunjcgvhbjnkmldsadad ftyguhjimkorf6tygubhnjidrftygbhunjtgyuhnj";
    int tableWidth = 100;
    int pageWidth = 70;

    int columnAWidth = columnWidth(s, t, tableWidth);
    cout << columnAWidth << endl;
    cout << "ColumnBWidth " << tableWidth - columnAWidth << endl;
    cout << numLinesNeeded(s, columnAWidth) << endl;
    cout << numLinesNeeded(t, tableWidth - columnAWidth) << endl;
    return 0;
}