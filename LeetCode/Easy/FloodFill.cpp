//733
//Given an mxn grid, color, and a starting point, all cells with the same number and connected to the starting point are replaced with "color"
#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector<int>> &image){
    for(int i = 0; i < image.size(); i++){
        for(int j  = 0; j < image[0].size(); j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(color == image[sr][sc]){ return image;}
    int originalColor = image[sr][sc];
    image[sr][sc] = color;

    if(sr != 0){
        if(image[sr-1][sc] == originalColor){
            floodFill(image, sr-1, sc, color);
        }
    }

    if(sr != image.size()-1){
        if(image[sr+1][sc] == originalColor){
            floodFill(image, sr+1, sc, color);
        }
    }

    if(sc != 0){
        if(image[sr][sc-1] == originalColor){
            floodFill(image, sr, sc-1, color);
        }
    }

    if(sc != image[sr].size()-1){
        if(image[sr][sc+1] == originalColor){
            floodFill(image, sr, sc+1, color);
        }
    }

    return image;
}

int main(int argc, char* argv[]){
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};

    int sr = 1;
    int sc = 1;
    int color = 2;

    cout << "Starting image: " << endl;
    printGrid(image);

    cout << "Answer: " << endl;
    vector<vector<int>> answer = floodFill(image,  sr, sc, color);
    printGrid(answer);
}