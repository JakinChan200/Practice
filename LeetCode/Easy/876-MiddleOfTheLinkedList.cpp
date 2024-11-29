//876
//Given a linked list, return the middle of the linked list. If there are 2, return the second one

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildLinkedList(vector<int> nums){
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    for(int i = 0; i < nums.size(); i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return dummy->next;
}

ListNode* middleNode(ListNode* head){
    ListNode* mid = head;
    ListNode* runner = head;

    while(runner != nullptr && runner->next != nullptr){
        runner = runner->next->next;
        mid = mid->next;
    }

    return mid;
}

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ListNode* input = buildLinkedList(nums);

    ListNode* answer = middleNode(input);
    cout << answer->val << endl;
    return 0;
}