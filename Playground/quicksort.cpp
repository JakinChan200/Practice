//Given a string, check if it is a permutation of a palindrome

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct coord{
    vector<int> lo;
};

vector<coord> entries;

int Partition(int axis, int lower, int higher){
    if(higher - lower <= 1){
        return lower;
    }

    //int pivot = average of 3 numbers;
    int pivot = (entries[lower].lo[axis] + entries[higher].lo[axis] + entries[(higher+lower)/2].lo[axis])/3;

    cout << entries[lower].lo[axis] << " + " << entries[higher].lo[axis] << " + " << entries[(higher+lower)/2].lo[axis] << " = " << pivot << endl;
    int lowerIndex = lower-1;
    for(int i = lower; i <= higher; i++){
        if(entries[i].lo[axis] < pivot){
            lowerIndex++;
            coord temp = entries[lowerIndex];
            entries[lowerIndex] = entries[i];
            entries[i] = temp;
        }
    }
    return lowerIndex;
}

void SortEntries(){
    int pivot50 = Partition(0, 0, entries.size()-1);

    int pivot25 = Partition(1, 0, pivot50);
    int pivot75 = Partition(1, pivot50+1, entries.size()-1);


    int pivot12 = Partition(2, 0, pivot25);
    int pivot37 = Partition(2, pivot25+1, pivot50);
    int pivot62 = Partition(2, pivot50+1, pivot75);
    int pivot87 = Partition(2, pivot75+1, entries.size()-1);
    
    cout << "\nPivot12: " << pivot12 << endl;
    cout << "Pivot25: " << pivot25 << endl;
    cout << "Pivot37: " << pivot37 << endl;
    cout << "Pivot50: " << pivot50 << endl;
    cout << "Pivot62: " << pivot62 << endl;
    cout << "Pivot75: " << pivot75 << endl;
    cout << "Pivot87: " << pivot87 << endl;
    return;
}

int main(int argc, char** argv){
    //Populate entries
    cout << "numbers" << endl;
    for(int i = 0; i < 20; i++){
        coord temp;
        temp.lo.push_back(rand()%20);
        temp.lo.push_back(rand()%20);
        temp.lo.push_back(rand()%20);
        cout << temp.lo[0] << ", " << temp.lo[1] << ", " << temp.lo[2] << endl;
        entries.push_back(temp);
    }

    SortEntries();

    //Print results
    for(int i = 0; i < entries.size(); i++){
        cout << entries[i].lo[0] << ", " << entries[i].lo[1] << ", " << entries[i].lo[2] << endl;
    }
    return 0;
}