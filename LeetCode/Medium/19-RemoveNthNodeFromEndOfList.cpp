//19
//Given the head of the linked list, remove the nth node from the end of the list and return the head

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* buildList(vector<int> nums){
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;

    for(int i = 0; i < nums.size(); i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    curr = dummyHead->next;
    dummyHead->next = nullptr;
    delete dummyHead;
    return curr;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* dummy = new ListNode(0, head);
    ListNode* curr = dummy;

    for(int i = 0; i < n; i++){
        head = head->next;
    }

    while(head != nullptr){
        head = head->next;
        curr = curr->next;
    }

    curr->next = curr->next->next;

    return dummy->next;
}

int main(int argc, char** argv){
    vector<int> listNums = {1, 2};
    int n = 1;

    ListNode* list = buildList(listNums);
    printList(list);

    ListNode *modifiedList = removeNthFromEnd(list, n);

    printList(modifiedList);

    return 0;    
}