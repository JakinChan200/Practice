#include <iostream>

using namespace std;

struct node{
    node *next = nullptr;
    int value;
};

struct linkedList{
    node *head = nullptr;
};

void printLinkedList(const linkedList &list){
    node *cur = list.head;
    while(cur != nullptr){
        cout << "Node Value: " << cur->value << endl;
        cur = cur->next;
    }

    cur = nullptr;
    return;
}

void appendNode(linkedList &list, node *n){
    if(list.head == nullptr){
        list.head = n;
        return;
    }

    node *cur = list.head;
    while(cur->next != nullptr){
        cur = cur->next;
    }

    cur->next = n;
    cur = nullptr;
    return;
}

linkedList partitionList(const linkedList list, node *partition){
    linkedList left;
    linkedList right;

    node *cur = list.head;
    node *temp;
    while(cur != nullptr){
        temp = new node;
        temp->value = cur->value;
        if(temp->value < partition->value){
            appendNode(left, temp);
        }else{
            appendNode(right, temp);
        }
        cur = cur->next;
    }
    
    cur = left.head;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = right.head;
    right.head = nullptr;
    return left;
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << "Incorrect number of arguments." << endl;
    }

    linkedList list;
    node *temp;
    node *cur;
    for(int i = 0; i < 10; i++){
        temp = new node;
        if(i == 0){
            cur = temp;
            list.head = temp;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
        cur->value = rand();
        temp = nullptr;
    }

    printLinkedList(list);

    linkedList sorted = partitionList(list, list.head->next);

    cout << "\nAfter Partition around " << list.head->next->value << ": " << endl;
    printLinkedList(sorted);

    return 0;
}

//Inputs ./a.exe

//Issues
/*
The number of nodes is hardcoded
No deallocation
*/

//Things I ran into
/*
Forgot about the edge case of no head when appending
*/