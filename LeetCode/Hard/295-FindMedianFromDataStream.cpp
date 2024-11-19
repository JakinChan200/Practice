//295
//return the median if off number, mean of the middle two numbers if even numbers

#include <bits/stdc++.h>

using namespace std;

priority_queue<long> small, large;

void addNum(int num){
    small.push(num);
    large.push(-small.top());
    small.pop();
    if(small.size() < large.size()){
        small.push(-large.top());
        large.pop();
    }
}

double findMedian(){
    return small.size() > large.size() ? small.top() : (small.top() - large.top() / 2.0);
}

int main(int argc, char** argv){
    return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */