//2579
//Each minute, adjacent vertical and horizontal cells become colored starting with 1 cell at minute 1
//Given the number of minutes, how many cells are colored

using namespace std;

long long coloredCells(int n) {
    int increment = 0;
    long long sum = 1;

    for(int i = 0; i < n; i++){
        sum += increment;
        increment += 4;
    }
    return sum;
}