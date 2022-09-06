//Given a linkedlist that circles back on itself, return the node that it circles back on
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
    int count = 0;

    while(cur != nullptr && count < 20){
        cout << "Node Value: " << cur->value << endl;
        cur = cur->next;
        count++;
    }

    return;
}

linkedList buildList(vector<int> nums){ 
    linkedList list;
    node *temp;
    node *cur;

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
    
    cur->next = list.head->next->next;
    return list;
}

node findLoop(const linkedList &list){
    if(list.head == nullptr || list.head->next ==  nullptr){
        return *list.head;
    }
    node *cur = list.head;
    node *cur2 = list.head->next;

    int index1 = 0;
    int index2 = 0;
    while(cur2 != nullptr){
        index1 = 0;
        cur = list.head;

        while(index1 != index2){
            if(cur == cur2){
                return *cur;
            }else{
                cur = cur->next;
                index1++;
            }
        }
        cur2 = cur2->next;
        index2++;
    }
}
int main(int argc, char** argv){
    if(argc != 1){
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }

    vector<int> nums = {1, 2, 3, 4, 5};

    linkedList list = buildList(nums);

    printList(list);

    node loopie = findLoop(list);

    cout << "The beginning of the loop is " << loopie.value << endl;
    return 0;
}

//Inputs ./a.exe

//Issues
/*
There might be issues with empty/blank lists
No deallocation
*/

//Things I ran into/learned
/*
On line 65 and 52, gotta return a dereferenced version
*/