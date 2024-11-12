//100
//Given the binary trees p and q, write a function to check if they are the same or not
//They are the same if they are structurally identical and the nodes have the same value

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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p == nullptr && q == nullptr){
        return true;
    }

    if(p == nullptr || q == nullptr){
        return false;
    }

    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char** argv){
    return 0;
}