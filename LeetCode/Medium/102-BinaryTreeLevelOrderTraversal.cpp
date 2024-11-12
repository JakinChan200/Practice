//102
//Given the root of a binary tree, return the level order traversal of its nodes' values (left to right by level)

#include <bits/stdc++.h>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrder1(TreeNode *root, vector<vector<int>> &answers, int depth){
    if(root == nullptr){
        return;
    }

    if(depth > answers.size()-1 || answers.size() == 0){
        answers.emplace_back(1, root->val);
    }else{
        answers[depth].push_back(root->val);
    }

    levelOrder1(root->left, answers, depth+1);
    levelOrder1(root->right, answers, depth+1);
}

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> answers;
    int depth = 0;

    levelOrder1(root, answers, depth);

    return answers;
}

int main(int argc, char** argv){
    vector<vector<int>> answers;
    answers.emplace_back(1, 2);

    print2DVector(answers);
    return 0;
}