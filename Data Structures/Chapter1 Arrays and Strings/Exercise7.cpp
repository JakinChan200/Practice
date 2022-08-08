//Given a NxN matrix, rotate it 90 degrees in place

#include <vector>
#include <iostream>

using namespace std;

void rotateMatrix(vector<vector<int>> *matrix, int start, int length){
    if(length <= 1) return;

    for(int i = start; i-start < length-1; i++){
        int temp = (*matrix)[start][i];
        (*matrix)[start][i] = (*matrix)[i][start+length-1];
        (*matrix)[i][start+length-1] = (*matrix)[start+length-1][start+length-1-(i-start)];
        (*matrix)[start+length-1][start+length-1-(i-start)] = (*matrix)[start+length-1-(i-start)][start];
        (*matrix)[start+length-1-(i-start)][start] = temp;
    }
    rotateMatrix(matrix, start+1, length-2);
    return;
}



int main(int argc, char** argv){
    //Cracking down on invalid entries
    if(argc != 2){
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }

    int n = stoi(argv[1]);
    // for(int i = 0; i < sizeof(argv[1]); i++){
    //     if(argv[1][i] < 0 || argv[1][i] > 9){
    //         cout << "Not a Valid Number." << endl;
    //         return 1;
    //     }else{
    //         n = n*10 + (argv[1][i] - 48);
    //     }
    // }

    //Populating the matrix with random values
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = rand()%10;
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    //Assigning a pointer and calling the function
    vector<vector<int>> *matr = &matrix;
    rotateMatrix(matr, 0, n);

    //Printing the final version
    cout << "\nEndProduct" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}

//Issues
/*
None so far, although I used std::stoi instead of building my own version (And having my own error messages)
*/