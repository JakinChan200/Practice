//if a value in a matrix is 0, the entire row and column is zero
#include <iostream>
#include <vector>


using namespace std;

//Convert all the values in row and column to 0
void convertRowCol(vector<vector<int>> *matrix, int row, int column){
    for(int i = 0; i < (*matrix).size(); i++){
        (*matrix)[i][column] = 0;
    }

    for(int i = 0; i < (*matrix)[row].size(); i++){
        (*matrix)[row][i] = 0;
    }
    return;
}

//Find all the Zeros in the Matrix and store their rows and columns
void convertMatrix(vector<vector<int>> *matrix){
    vector<vector<int>> ZeroCoords(0, vector<int>(0, 0));
    for(int i = 0; i < (*matrix).size(); i++){
        for(int j = 0; j < (*matrix)[0].size(); j++){
            if((*matrix)[i][j] == 0){
                vector<int> temp = {i, j};
                ZeroCoords.push_back(temp);
            }
        }
    }

    for(int i = 0; i < ZeroCoords.size(); i++){
        convertRowCol(matrix, ZeroCoords[i][0], ZeroCoords[i][1]);
    }
    return;
}

int main(int argc, char** argv){
    //Pruning wrong inputs
    if(argc != 3){
        cout << "Wrong number of arguments." << endl;
        return 1;
    }

    //Create matrix
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    
    //Initialize Matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = rand()%10;
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    //Call convertMatrix
    vector<vector<int>> *matr = &matrix;
    convertMatrix(matr);

    //Print results
    cout << "\nResult" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    return 0;

}

//Issues
/*
Not a great use of space
Runtime is also not so great -> can maybe skip iterating over the row again if convert the row in original pass, but then needs to retroactively convert values you already passed
*/