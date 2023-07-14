//Return kth to last element of a singly linked list
#include <iostream>

using namespace std;

struct node{
    node *next = nullptr;
    int value;
};

struct linkedList{
    node *head = nullptr;
};

int kthFromLast(const linkedList &list, int k){
    node *cur = list.head;
    int count = 0;
    while(cur != nullptr){
        count++;
        cur = cur->next;
    }

    cur = list.head;
    for(int i = 0; i < count-k; i++){
        cur = cur->next;
    }

    return cur->value;
}

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Not correct amount of arguments" << endl;
        return 1;
    }

    linkedList list;
    int k = stoi(argv[1]);
    int n = k + rand()%20;
    node *cur;
    for(int i = 0; i < n; i++){
        node *temp = new node;
        if(i == 0){
            list.head = temp;
            cur = temp;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
        temp->value = i;
        temp = nullptr;
        delete temp;
    }



    //Find the kth to last element
    int value = kthFromLast(list, k);

    cout << "The number of total nodes is: " << n << endl;
    cout << "The " << k << "th element from the end is " << value << endl; 
    return 0;
}

//Inputs ./a.exe k

//Issues
/*
No deallocation of entire linkedlist
*/

//Things I ran into
/*
I found that line 51 (node *temp = new node) needs to be a pointer
    > and that cur is a pointer, makes it somewhat conlfusing, as you can set everything the otherway, where they don't have to be pointers, and instead of ->, you use .
*/