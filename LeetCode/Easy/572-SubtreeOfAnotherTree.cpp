//572
//Given the roots of two binary trees, root and subRoot, return true if there is a subtree of root with the same structure and node values of subroot

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

bool checkSubTree(TreeNode *root, TreeNode *subRoot){
    if(root == nullptr && subRoot == nullptr){
        return true;
    }

    if(root == nullptr || subRoot == nullptr){
        return false;
    }

    if(root->val == subRoot->val){
        return checkSubTree(root->left, subRoot->left) && checkSubTree(root->right, subRoot->right);
    }

    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot){
    if(root == nullptr){
        return false;
    }

    if(checkSubTree(root, subRoot)){
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(int argc,char** argv){

    return 0;
}