//74
//Given a 2D matrix and a target int, return whether or not it exists
//Must be in Olog(m * n)

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();
    
    int left = 0;
    int right = (m * n)-1;

    while(left <= right){
        int middle = left + (right - left) / 2;
        int middleRow = middle / n;
        int middleCol = middle % n;
        cout << middle << endl;

        if(matrix[middleRow][middleCol] == target){
            return true;
        }
        
        if(matrix[middleRow][middleCol] < target){
            left = middle+1;
        }else{
            right = middle-1;
        }

        cout << "left: " << left  << " right: " << right << "\n";
    }

    // if(matrix[left / matrix.size()][left % matrix.size()] == target){
    //     return true;
    // }

    return false;
}

int main(int argc,  char** argv){
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                    {10, 11, 16, 20},
                                    {23, 30, 34, 60}};
    int target = 13;

    cout << searchMatrix(matrix, target);
    return 0;
}