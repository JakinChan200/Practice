//84
//Given an integer array where each element is the height of the histogram,and the witdth is 1,return the largest rectangle in the histogram

#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &heights){
    stack<int> stack;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0; i <= n; i++){
        int currentHeight = (i == n) ? 0 : heights[i];

        while(!stack.empty() && heights[stack.top()] > currentHeight){
            int height = heights[stack.top()];
            stack.pop();
            int width = stack.empty() ? i : i - stack.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        stack.push(i);
    }

    return maxArea;
}