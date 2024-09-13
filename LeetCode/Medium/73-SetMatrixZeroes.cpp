//73
//Given a m x n matrix, if the element is 0, set its row and column to 0. Must be done in place

#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> &matrix){
    cout << "Matrix:" << endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(j != 0){
                cout << " ";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void setZeroes(vector<vector<int>> &matrix){
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    vector<int> rows(rowSize, 0);
    vector<int> cols(colSize, 0);

    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    // for(int i = 0; i < matrix.size(); i++){
    //     for(int j = 0; j < matrix[0].size(); j++){
    //         if(rows[i] == 1 || cols[j] == 1){
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }

    for(int i = 0; i < rows.size(); i++){
        if(rows[i] == 1){
            for(int j = 0; j < colSize; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < cols.size(); i++){
        if(cols[i] == 1){
            for(int j = 0; j < rowSize; j++){
                matrix[j][i] = 0;
            }
        }
    }
}


int main(int argc, char** argv){
    vector<vector<int>> matrix = {{1, 1, 1},
                                    {1, 0, 1},
                                    {1, 0, 1},
                                    {1, 1, 1}};
    
    setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}