#include <iostream>
#include <vector>

using namespace std;

//Initialize C to be the sum of its section of numbers length k
//So C[1] would be the sum of the first k numbers, C[2] would be the sum of the next k, etc
void firstPart(vector<int> &A, vector<int> &C, int n, int k){
    for(int i = 1; i <= n/k; i++){
        for(int j = ((i-1)*k) + 1; j <= i*k; j++){
            C[i] += A[j]; //Changed this so that its C[1] instead of C[i+1]
        }
    }
}

//Adds the running sum of C[previous] and puts it in the correct place in B (Technically could be combined with part 1)
//This creates checkpoints
void secondPart(vector<int> &B, vector<int> &C, int n, int k){
    for(int i = 1; i <= n/k; i++){
        B[i*k] = B[(i-1)*k] + C[i];
    }
}

//Parallelize each section of k numbers where you iterate through the numbers in the section and incrementally compute the prefix sum
void thirdPart(vector<int> &A, vector<int> &B, int n, int k){
    for(int i = 1; i <= n/k; i++){
        for(int j = (i-1)*k + 1;  j <= (i*k)-1; j++){
            B[j] += B[j-1] + A[j];
        }
    }
}

void bruteForce(vector<int> &A, vector<int> &B){
    for(int i = 1; i < A.size(); i++){
        B[i] = B[i-1] + A[i];
    }
}

void initializeVector(vector<int> &vect){
    for(int i = 1; i < vect.size(); i++){
        vect[i] = i;
    }
}
void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv){

    int n;
    int k;
    cin >> n;
    cin >> k;

    vector<int> A(n+1, 0);
    vector<int> B(n+1, 0);
    vector<int> C((n/k)+1, 0);

    initializeVector(A);
    printVector(A);

    cout << "\nFirst Part" << endl;
    cout << "C:" << endl;
    firstPart(A, C, n, k);
    printVector(C);

    cout << "\nSecond Part" << endl;
    cout << "B:" << endl;
    secondPart(B, C, n, k);
    printVector(B);

    cout << "\nThird Part" << endl;
    thirdPart(A, B, n, k);
    cout << "B: " << endl;
    printVector(B);

    cout << "\nSolution" << endl;
    bruteForce(A, B);
    cout << "B: " << endl;
    printVector(B);
    return 0;
}