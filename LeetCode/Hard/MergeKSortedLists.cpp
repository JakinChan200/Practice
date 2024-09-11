//23
//Given an array of k sorted linked-lists, Merge them and return it

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* rootNode){
    cout << "[";
    while(rootNode != nullptr){
        cout << rootNode->val << " ";
        rootNode = rootNode->next; 
    }
    cout << "]" << endl;
}

ListNode * buildList(vector<int> nums){
    ListNode * head = new ListNode(25);
    ListNode * cur = head;

    for(int i = 0; i < nums.size(); i++){
        ListNode * temp = new ListNode(nums[i]);
        cur->next = temp;
        cur = cur->next;
    }
    
    cur = head;
    head = head->next;
    delete cur;
    return head;
}

// ListNode* mergeKLists(vector<ListNode*>& lists){
//     priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> queue;
//     for(int i = 0; i < lists.size(); i++){
//         if(lists[i]){
//             queue.push({lists[i]->val,lists[i]});
//         }
//     }

//     ListNode* Head = new ListNode(-1);
//     ListNode* curr = Head;
//     while(!queue.empty()){
//         auto it = queue.top();
//         queue.pop();
//         if(it.second->next)
//             queue.push({it.second->next->val,it.second->next});
//             curr->next = it.second;
//             curr = curr->next;
//     }
//     return Head->next;
// }

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *finalHead = new ListNode(0);
    ListNode *currSmallest = finalHead;
    int smallestIndex = 0;

    for(int i = lists.size()-1; i >= 0; i--){
        if(lists[i] == nullptr){
            lists.erase(lists.begin() + i);
        }
    }

    if(lists.size() == 0){
        return nullptr;
    }

    while(lists.size() > 0){
        smallestIndex = 0;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]->val < lists[smallestIndex]->val){
                smallestIndex = i;
            }
        }
        currSmallest->next = lists[smallestIndex];
        currSmallest = currSmallest->next;

        if(lists[smallestIndex]->next == nullptr){
            lists.erase(lists.begin() + smallestIndex);
        }else{
            lists[smallestIndex] = lists[smallestIndex]->next;
        }
    }

    currSmallest->next = nullptr;
    return finalHead->next;
}

int main(int argc, char** argv){
    // vector<vector<int>> numbers = {{1, 4, 5},
    //                                 {1, 3, 4},
    //                                 {2, 6}};
    
    // vector<vector<int>> numbers = {{}};

    vector<vector<int>> numbers = {{2}, {}, {-1}};

    vector<ListNode*> nodes;
    for(int i = 0; i < numbers.size(); i++){
        nodes.push_back(buildList(numbers[i]));
    }

    cout << "Lists: " << endl;
    for(int i = 0; i < nodes.size(); i++){
        printList(nodes[i]);
    }

    ListNode *answers = mergeKLists(nodes);
    cout << "Answers: " << endl;
    printList(answers);
    return 0;
}
 