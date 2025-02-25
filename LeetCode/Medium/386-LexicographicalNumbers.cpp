//386
//Given an integer n, return all numbers in the range [1, n] sorted in lexicographical order
//Runs in O(n) time and uses O(1) extra space

#include <vector>

using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> ans(n);
    int x = 1;

    for(int i = 0; i < n; i++){
        ans[i] = x;
        if(x * 10 > n){
            if(x == n){
                x /= 10;
            }
            x++;

            while(x % 10 == 0){
                x /= 10;
            }
        }else{
            x *= 10;
        }
    }
    return ans;
}