//98
//Given a Binary Tree, return whether or not it is valid

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

bool checkSubTree(TreeNode* root, long min, long max){
    if(root == nullptr){
        return true;
    }
    if(root->val <= min || root->val >= max){
        return false;
    }

    return checkSubTree(root->left, min, root->val) && checkSubTree(root->right, root->val, max);
}

bool isValidBST(TreeNode*root){
    return checkSubTree(root, (long)INT_MIN, (long)INT_MAX);
}


// bool checkSubTree(TreeNode* root, vector<int> smaller, vector<int> larger){
//     if(root == nullptr){
//         return true;
//     }

//     for(int i = 0; i < smaller.size(); i++){
//         if(smaller[i] >= root->val){
//             return false;
//         }
//     }

//     for(int i = 0; i < larger.size(); i++){
//         if(larger[i] <= root->val){
//             return false;
//         }
//     }

//     bool left = true;
//     if(root->left != nullptr){
//         vector<int> temp = larger;
//         temp.push_back(root->val);
//         left = checkSubTree(root->left, smaller, temp);
//     }

//     bool right = true;
//     if(root->right != nullptr){
//         vector<int> temp = smaller;
//         temp.push_back(root->val);
//         right = checkSubTree(root->right, temp, larger);
//     }

//     return left && right;
// }

// bool isValidBST(TreeNode* root){
//     if(root == nullptr){
//         return true;
//     }

//     vector<int> smaller = {root->val};
//     vector<int> larger = {root->val};
//     vector<int> temp;
//     return checkSubTree(root->left, temp, larger) && checkSubTree(root->right, smaller, temp);
// }

int main(int argc, char** argv){

    return 0;
}