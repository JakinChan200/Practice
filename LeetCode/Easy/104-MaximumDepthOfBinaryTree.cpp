//104
//Given the root of a binary tree, return its maximum depth

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

int maxDepth(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main(int argc, char** argv){

    return 0;
}
