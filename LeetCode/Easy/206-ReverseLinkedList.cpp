//206
//Given a singly linked list, reverse the list and return it

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    ListNode *curr = head;
    cout << "[";

    if(curr != nullptr){
        cout << curr->val;
        curr = curr->next;
    }

    while(curr != nullptr){
        cout << ", " << curr->val;
        curr = curr->next;
    }
    cout << "]";
}

ListNode* buildList(vector<int> nums){
    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;

    for(int i = 0; i < nums.size(); i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return dummyHead->next;
}

ListNode* reverseList(ListNode* head) {
    vector<ListNode*> nodes;

    if(head == nullptr){
        return nullptr;
    }

    ListNode *curr = head;
    while(curr != nullptr){
        nodes.push_back(curr);
        curr = curr->next;
    }

    for(int i = 1; i < nodes.size(); i++){
        cout << nodes[i]->val << endl;
        nodes[i]->next = nodes[i-1];
    }

    if(nodes.size() >= 1){
        nodes[0]->next = nullptr;
    }

    return nodes[nodes.size()-1];
}

int main(int argc, char** argv){
    vector<int> nums = {};
    
    ListNode *head = buildList(nums);
    ListNode *answer = reverseList(head);
 
    printList(answer);
    return 0;
}