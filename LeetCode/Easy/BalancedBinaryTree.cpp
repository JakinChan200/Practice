// Given a Binary Tree, return whether it is balanced (whether the height of the two sub-trees differ by more than one)

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
 
int getHeight(TreeNode* node){
    if(node == nullptr){
        return 1;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if(leftHeight == -1 || rightHeight == -1){
        return -1;
    }

    if(abs(leftHeight = rightHeight) > 1){
        return -1;
    }

    if(leftHeight > rightHeight){
        return leftHeight;
    }

    return rightHeight;
}

bool isBalanced(TreeNode* root){
    if(getHeight(root) == -1){
        return false;
    }
    return true;
}

void buildTree(vector<int> *tree){

}

int main(int argc, char* argv[]){

}