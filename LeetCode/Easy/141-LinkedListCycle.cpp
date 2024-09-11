//141
//Given a linked list, return true or false if there is a cycle
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head){
    while(head != nullptr){
        cout << head->val <<  " ";
        head = head->next;
    }
    cout << endl;
}

ListNode * buildList(int nums){
    ListNode * head = new ListNode(25);
    ListNode * cur = head;

    for(int i = 0; i < nums; i++){
        ListNode * temp = new ListNode(rand()%50);
        cur->next = temp;
        cur = cur->next;
    }
    
    cur = head;
    head = head->next;
    delete cur;
    return head;
}

bool hasCycle(ListNode *head) {
    if(head == nullptr){
        return false;
    }

    ListNode * fast = head->next;
    ListNode * slow = head;
    int counter = 0;

    while(fast != slow){
        if(fast == nullptr){
            return false;
        }

        if(counter >= 2){
            counter = 0;
            slow = slow->next;
        }else{
            counter++;
            fast = fast->next;
        }
    }

    return true;
}

// bool hasCycle(ListNode *head){
//     set<ListNode> nodes;

//     while(head != nullptr){
//         int setSize = nodes.size();
//         nodes.insert(* head);
//         head = head->next;

//         if(setSize == nodes.size()){
//             return true;
//         }
//     }
    
//     return false;
// }

int main(int argc, char* argv[]){
    int numNodes = 10;

    ListNode * head = buildList(numNodes);
    printList(head);

    ListNode * cur = head;
    while(cur->next != nullptr){
        cur = cur->next;
    }

    cur->next = head->next->next;

    bool isCyclic = hasCycle(head);
    if(isCyclic){
        cout << "There is a cycle." << endl;
    }else{
        cout << "There is no cycle." << endl;
    }

    return 0;
}