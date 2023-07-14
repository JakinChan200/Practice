//235
//Given a Binary Search Tree, find the lowest common ancestor of two inputs
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode * head){
    if(head == nullptr){
        return;
    }

    printTree(head->left);
    cout << head->val <<  " ";
    printTree(head->right);
}

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q){
    if(root == nullptr){
        return nullptr;
    }

    if(p->val == root->val || q->val == root->val){
        return root;
    }

    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

void insertNode(TreeNode* head, TreeNode * node){
    // if(head = nullptr){
    //     return;
    // }

    if(node->val < head->val){
        if(head->left == nullptr){
            head->left = node;
        }else{
            insertNode(head->left, node);
        }
    }else{
        if(head->right == nullptr){
            head->right = node;
        }else{
            insertNode(head->right, node);
        }
    }
    return;
}

TreeNode * buildTree(int num){
    TreeNode * head = new TreeNode(25);

    for(int i = 1; i < num; i++){
        int temp = rand()%50;
        insertNode(head, new TreeNode(temp));
    }

    return head;
}

int main(int argc, char* argv[]){
    int numNodes = 5;

    TreeNode * head = buildTree(numNodes);
    cout << "Tree: " << endl;
    printTree(head);

    TreeNode * answer = lowestCommonAncestor(head, head->left, head->left->left);
    cout << "\nAnswer: " << answer->val << endl;
  
    return 0;
}