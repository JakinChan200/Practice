//48
//Given a n x n matrix, rotatie it 90 degrees clockwise in place

#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate(vector<vector<int>> &matrix){

    int offset = 0;
    int size = matrix.size();
    int offset1;
    int offset2;

    for(int i = 0; i < size/2; i++){
        for(int j = offset; j < size-offset-1; j++){
            offset1 = size-1-offset; //Distance from edge
            offset2 = size-1-j; //Iterating along the edge

            int temp = matrix[offset][j];
            matrix[offset][j] = matrix[offset2][offset];
            matrix[offset2][offset] = matrix[offset1][offset2];
            matrix[offset1][offset2] = matrix[j][offset1];
            matrix[j][offset1] = temp;

            // cout << offset << " " << j << endl;
            // cout << j << " " << matrix.size()-1-offset << endl;
            // cout << matrix.size()-1-offset << " " << matrix.size()-1-j << endl;
            // cout << matrix.size()-1-j << " " << offset << endl;
        }
        offset++;
    }
}

int main(int argc, char** argv){
    // vector<vector<int>> matrix = {{1, 2, 3},
    //                                 {4, 5, 6},
    //                                 {7,8, 9}};

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};

    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);
    return 0;    
}