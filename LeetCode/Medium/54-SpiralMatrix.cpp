//54
//Given an m x n matrix, return all elements of the matrix in spiral order

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

void printVector(vector<int> nums){
    cout << "{";
    if(nums.size() == 0){
        cout << "}" << endl;
        return;
    }

    cout << nums[0];
    for(int i = 1; i < nums.size(); i++){
        cout << ", " << nums[i];
    }
    cout << "}" << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix){
    int offset = 0;
    int row = 0;
    int col = 0;
    vector<int> answers;

    if(matrix.size() > 0){
        answers.push_back(matrix[0][0]);
    }
    
    while(answers.size() < matrix[0].size() * matrix.size()){
        for(col++; col < (matrix[0].size() - offset); col++){
            answers.push_back(matrix[row][col]);
        }
        
        col--;
        if(answers.size() >= matrix[0].size() * matrix.size()) return answers;
        for(row++; row < matrix.size() - offset; row++){
            answers.push_back(matrix[row][col]);
        }

        row--;
        if(answers.size() >= matrix[0].size() * matrix.size()) return answers;
        for(col--; col >= offset; col--){
            answers.push_back(matrix[row][col]);
        }

        col++;
        if(answers.size() >= matrix[0].size() * matrix.size()) return answers;
        for(row--; row > offset; row--){
            answers.push_back(matrix[row][col]);
        }
        row++;
        offset++;
    }
    return answers;
}

int main(int argc, char** argv){
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};

    vector<vector<int>> matrix1 = {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};

    // printMatrix(matrix);
    vector<int> answers = spiralOrder(matrix);
    printVector(answers);
    return 0;
}