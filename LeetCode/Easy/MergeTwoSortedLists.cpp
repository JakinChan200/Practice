//Given two lists, merge them in increasing order
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}     
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

ListNode * buildList(vector<int> nums){
    ListNode * head;
    ListNode * cur;

    for(int i = 0; i < nums.size(); i++){
        if(i == 0){
            head = new ListNode(nums[i]);
            cur = head;
        }else{
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
    }
    return head;
}

void printList(ListNode * list){
    ListNode * cur = list;
    
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
}

//Case if one list is [] and the other is [1, 2, 3]
ListNode * mergeTwoLists(ListNode * list1, ListNode * list2){
    ListNode * mergedHead = new ListNode(0);
    ListNode * cur = mergedHead;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            cur->next = list1;
            list1 = list1->next;
        }else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    if(list1 == nullptr){
        cur->next = list2;
    }else{
        cur->next = list1;
    }
    return mergedHead->next;
}

ListNode * Solution(ListNode * list1, ListNode * list2){
    if(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            list1->next = Solution(list1->next, list2);
            return list1;
        }else{
            list2->next = Solution(list1, list2->next);
            return list2;
        }
    }else{
        if(list1 == nullptr){
            return list2;
        }else{
            return list1;
        }
    }
    return list1;
}

int main(int argc, char* argv[]){
    // int numFirst = -1;
    // int numSecond = -1;
    
    // do{
    //     cout << "How many values in the first list?" << endl;
    //     cin >> numFirst;
    // }while(numFirst < 0);

    // do{
    //     cout << "How many values in the second list?" << endl;
    //     cin >> numSecond;
    // }while(numSecond < 0);

    // ListNode *head1;
    // ListNode *cur;
    // int curValue = 0;
    // for(int i = 0; i < numFirst; i++){
    //     cout << "Enter value " << i+1 << " for list 1: " << endl; 
    //     cin >> curValue;
    //     if(i == 0){
    //         head1 = new ListNode(curValue);
    //         cur = head1;
    //     }else{
    //         cur->next = new ListNode(curValue);
    //         cur = cur->next;
    //     }
    // }

    // ListNode *head2;
    // for(int i = 0; i < numSecond; i++){
    //     cout << "Enter value " << i+1 << " for list 2: " << endl; 
    //     cin >> curValue;
    //     if(i == 0){
    //         head2 =  new ListNode(curValue);
    //         cur = head2;
    //     }else{
    //         cur->next = new ListNode(curValue);
    //         cur = cur->next;
    //     }
    // }

    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};

    ListNode * head1 = buildList(list1);
    ListNode * head2 = buildList(list2);
    
    cout << "List 1" << endl;
    printList(head1);
    cout << "\nList 2" << endl;
    printList(head2);

    ListNode * head = mergeTwoLists(head1, head2);
    
    cout << "\nThe solution is: " << endl;
    printList(head);
    return 0;
}
