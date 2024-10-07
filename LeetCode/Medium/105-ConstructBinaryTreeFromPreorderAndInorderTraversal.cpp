//105
//Given the integer arrays preorder and inorder, construct and return the binary tree.

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

void printTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

TreeNode* build(vector<int> &pre, vector<int> &in, int preLow, int preHigh, int inLow, int inHigh){
    if(preLow > preHigh || inLow > inHigh){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(pre[preLow]);

    if(preLow == preHigh){
        return root;
    }

    int i = inLow;
    while(i <= inHigh){
        if(in[i] ==pre[preLow])
            break;
        i++;
    }

    int leftCount = i-inLow;
    int rightCount = inHigh-1;

    root->left = build(pre, in, preLow+1, preLow+ leftCount, inLow, i-1);
    root->right = build(pre, in, preLow+leftCount+1, preHigh, i+1, inHigh);
    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    int n = preorder.size();
    return build(preorder, inorder, 0, n-1, 0, n-1);
}

int main(int argc, char** argv){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *answer = buildTree(preorder, inorder);
    printTree(answer);
    return 0;
}