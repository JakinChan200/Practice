//226
//Given a binary tree, invert it and return the root
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

void printTree(TreeNode * head){
    if(head == nullptr){
        return;
    }

    printTree(head->left);
    cout << " " << head->val << " ";
    printTree(head->right);
}

void insertIntoTree(TreeNode * head, TreeNode * node){
    //TreeNode * cur = head;

    if(node->val < head->val){
        if(head->left == nullptr){
            head->left = node;
        }else{
            insertIntoTree(head->left, node);
        }
    }else{
        if(head->right == nullptr){
            head->right = node;
        }else{
            insertIntoTree(head->right, node);
        }
    }
    return;
}

// void iterateTree(TreeNode * root, TreeNode * head){
//     if(root == nullptr){
//         return;
//     }

//     insertIntoTree(head, new TreeNode(root->val));
//     iterateTree(root->left, head);
//     iterateTree(root->right, head);
//     return;
// }

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr){
        return nullptr;
    }

    TreeNode * current = new TreeNode(root->val);

    current->left = invertTree(root->right);
    current->right = invertTree(root->left);

    return current;
}

TreeNode * buildTree(int numNodes){
    TreeNode * head = new TreeNode(25);

    for(int i = 1; i < numNodes; i++){
        int temp = rand()%50;
        insertIntoTree(head, new TreeNode(temp));
    }

    return head;
}

int main(int argc, char* argv[]){
    int numNodes = 5;

    TreeNode * head = buildTree(numNodes);
    printTree(head);

    cout << "\nAnswer: " << endl;
    TreeNode * answer = invertTree(head);
    printTree(answer);
    return 0;
}