//Add two numbers represented by linked lists
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

void populateList(linkedList &list){
    node *temp;
    node *cur;
    for(int i = 0; i < 3; i++){
        temp = new node;
        if(i == 0){
            list.head = temp;
            cur = list.head;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
        cur->value = rand()%10;
    }
    cur = nullptr;
    temp = nullptr;
    return;
}

void printList(linkedList &list){
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
    return;
}
linkedList addList(const linkedList &list1, const linkedList &list2){
    linkedList solution;
    node *cur1 = list1.head;
    node *cur2 = list2.head;
    node *temp;

    while(cur1 != nullptr){
        temp = new node;
        temp->value = cur1->value + cur2->value;
        appendNode(solution, temp);
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return solution;
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }

    linkedList first;
    linkedList second;

    populateList(first);
    populateList(second);

    cout << "\nFirst List: " << endl;
    printList(first);

    cout << "\nSecond List: " << endl;
    printList(second);

    linkedList solution = addList(first, second);

    cout << "\nSolution: " << endl;
    printList(solution);
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

*/