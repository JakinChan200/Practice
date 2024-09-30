//230
//Given a root of a binary search tree, return the kth smallest value

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findK(TreeNode* root, int &k){
    if(root == nullptr){
        return -1;
    }

    int answer = findK(root->left, k);
    if(k < 1){
        return answer;
    }
    
    if(k == 1){
        k--;
        return root->val;
    }

    k--;

    return findK(root->right, k);
}


int kthSmallest(TreeNode* root, int k){
    return findK(root, k);
}

int main(int argc, char** argv){

    return 0;
}