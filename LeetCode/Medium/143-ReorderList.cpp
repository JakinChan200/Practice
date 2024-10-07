//143
//Given the head of a singly linked list, reorder it so that it is:
// L0 -> Ln -> L1 -> Ln-1 -> ...

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int> nums){
    ListNode* dummyHead = new ListNode(5);
    ListNode* curr = dummyHead;

    for(int i = 0; i < nums.size(); i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return dummyHead->next;
}

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// No runner
void reorderList(ListNode* head){
    vector<ListNode*> nums;
    ListNode* curr = head;

    while(curr != nullptr){
        nums.push_back(curr);
        curr = curr->next;
    }

    curr = head;
    for(int i = 0; i < nums.size(); i++){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    int i = 0; 
    int j = nums.size()-1;
    ListNode *dummyHead = new ListNode(7);
    // dummyHead = head;

    while(i < j){
        dummyHead->next = nums[i];
        dummyHead = dummyHead->next;
        dummyHead->next = nums[j];
        dummyHead = dummyHead->next;
        i++;
        j--;
        dummyHead->next = nullptr;
    }

    cout << i << " " << j << endl;
    if(i == j){
        dummyHead->next = nums[i];
        dummyHead = dummyHead->next;
        dummyHead->next = nullptr;
    }

}

// With Runner
// void reorderList(ListNode* head){
//     ListNode *front = head;
//     ListNode *back = head;
//     ListNode *runner;

//     if(head == nullptr){
//         return;
//     }

//     while(back->next != nullptr){
//         back = back->next;
//     }

//     while(front != nullptr && front->next != nullptr && front->next != back){
//         runner = front;
//         while(runner->next != back){
//             runner = runner->next;
//         }

//         back->next = front->next;
//         front->next = back;
//         runner->next = nullptr;

//         front = front->next->next;
//         back = runner;
//     }
// }

int main(int argc, char** argv){
    vector<int> nums = {1, 2, 3, 4, 5};

    ListNode *input = buildList(nums);
    printList(input);

    reorderList(input);
    printList(input);
    return 0;    
}
