//Given 2 singly linked lists, determine if they intersect
#include <iostream>
#include <vector>

using namespace std;

struct node{
    node *next = nullptr;
    int value;
};

struct linkedList{
    node *head = nullptr;
};

void printList(const linkedList &list){
    node *cur = list.head;

    while(cur != nullptr){
        cout << "Node Value: " << cur->value << endl;
        cur = cur->next;
    }

    return;
}

linkedList buildList(vector<int> nums){
    linkedList list;
    node *cur;
    node *temp;

    for(int i = 0; i < nums.size(); i++){
        temp = new node;
        temp->value = nums[i];
        if(i == 0){
            list.head = temp;
            cur = temp;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
    }

    cur = nullptr;
    return list;
}

void insertReference(const linkedList &list1, linkedList & list2, int size){
    node *cur = list1.head;

    int randomValue = rand()%size;
    for(int i = 0; i < randomValue; i++){
        cur = cur->next;
    }

    node *cur2 = list2.head;
    while(cur2->next != nullptr){
        cur2 = cur2->next;
    }

    cur2->next = cur;
    return;
}

bool checkIntersection(const linkedList &list1, const linkedList &list2){
    node *cur = list1.head;
    node *cur2 = list2.head;
    while(cur != nullptr){
        cur2 = list2.head;
        while(cur2 != nullptr){
            if(cur == cur2){
                return true;
            }
            cur2 = cur2->next;
        }
        cur = cur->next;
    }

    cur = nullptr;
    cur2 = nullptr;
    return false;
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << "Incorrect number of arguments" << endl;
    }

    bool hasReference = true;

    vector<int> list1 = {1, 2, 3, 4, 5};
    vector<int> list2 = {6, 7, 8, 9, 10};
    int list1Size = list1.size();

    linkedList linkList1 = buildList(list1);
    linkedList linkList2 = buildList(list2);

    cout << "List 1" << endl;
    printList(linkList1);

    cout << "List 2" << endl;
    printList(linkList2);

    if(hasReference){
        cout << "\nInserting Reference" << endl;
        insertReference(linkList1, linkList2, list1Size);
        cout << "List 1" << endl;
        printList(linkList1);

        cout << "List 2" << endl;
        printList(linkList2);
    }

    cout << "\nChecking for Intersection" << endl;
    bool isIntersecting = checkIntersection(linkList1, linkList2);

    if(isIntersecting){
        cout << "The linkedLists intersect." << endl;
    }else{
        cout << "The linkedLists do not intersect." << endl;
    }
    return 0;
}

//Inputs ./a.exe

//Issues
/*
No deallocation
*/

//Things I ran into
/*
Not sure how to make it intersect and not merge, maybe its not supposed to
*/