//Delete a node that is not the head or tail
#include <iostream>

using namespace std;
struct node{
    node *next = nullptr;
    int value;
};

struct linkedList{
    node *head = nullptr;
};

void deleteNode(linkedList &list, node* n){
    node *cur = list.head;
    while(cur->next != n){
        cur = cur->next;
    }

    cur->next = n->next;
    n->next = nullptr;
    delete n;
}

void printLinkedList(const linkedList &list){
    node *cur = list.head;
    while(cur != nullptr){
        cout << "Node value: " << cur->value << endl;
        cur = cur->next;
    }

    cur = nullptr;
    delete cur;
    return;
}

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Incorrect number of arguments" << endl;
    }

    //Building the linkedlist
    int n = stoi(argv[1]);
    linkedList list;
    node *temp;
    node *cur;
    node *nodeToDelete;
    for(int i = 0; i < n*2; i++){
        temp = new node;
        if(i == 0){
            list.head = temp;
            cur = temp;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
        temp->value = i;

        if(i == n){
            nodeToDelete = temp;
        }
        temp = nullptr;
    }

    printLinkedList(list);

    deleteNode(list, nodeToDelete);

    //After deleting node
    cout << "After deleting node:" << endl;
    printLinkedList(list);
    return 0;
}

//Inputs ./a.exe n
//n is the middle of the linkedList

//Issues
/*
No deallocation of the entire linkedlist
*/

//Things I ran into
/*

*/