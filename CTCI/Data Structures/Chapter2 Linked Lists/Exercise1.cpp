//Remove duplicates from an unsorted linked list

#include <iostream>
#include <vector>
#include "windows.h"
using namespace std;

struct node{
    node * next = nullptr;
    int value = 0;
};

struct linkedlist{
    node * head = nullptr;
};

void removeDuplicates(linkedlist list){
    node *prev = list.head;
    node *cur  = list.head->next;
    vector<bool> data(10, false);

    while(cur != nullptr){
        if(data[cur->value] == false){
            data[cur->value] = true;
            cur = cur->next;
            prev = prev->next;
        }else{
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
    }
}

int main(int argc, char** argv){
    //Error Checking
    //Checks if there is the correct number of inputs
    if(argc <= 1){
        cout << "Please include the length of the linked list." << endl;
    }

    //Checks whether the input is valid (n > 0)
    int n = atoi(argv[1]);
    if(n <= 0){
        cout << "Please enter a number greater than 0." << endl;
    }

    //Declare and initialize a list of n numbers
    linkedlist list;
    for(int i = 0; i < n; i++){
        node *temp = new node;
        temp->value = rand()%10;
        if(i == 0){
            list.head = temp;
        }else{
            node *cur = list.head;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            cur->next = temp;
        }
        cout << " " << temp->value;
    }
    cout << endl;

    //Call Function
    removeDuplicates(list);

    //Display results
    cout << "Results" << endl;
    node *cur = list.head;
    while(cur != nullptr){
        cout << " " << cur->value;
        cur = cur->next;
    }
    return 0;
}

//Inputs ./a.exe n
//n is the length of the linked list

//Issues
/*
No deallocation of the entire linkedlist
*/

//Things I ran into
/*
I found that line 51 (node *temp = new node) needs to be a pointer
*/