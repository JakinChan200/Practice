//Check if a linked list is a palindrome
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
        cout << "Node value: " << cur->value << endl;
        cur = cur->next;
    }

    cur = nullptr;
    return;
}

linkedList buildList(vector<int> &nums){
    linkedList list;
    node *cur = nullptr;
    node *temp;

    for(int i = 0; i < nums.size(); i++){
        temp = new node;
        temp->value = nums[i];
        if(i == 0){
            list.head = temp;
            cur = list.head;
        }else{
            cur->next = temp;
            cur = cur->next;
        }
    }
    return list;
}

bool checkPalindrome(linkedList &list){
    node *cur = list.head;
    int count = 0;

    while(cur != nullptr){
        count++;
        cur = cur->next;
    }

    vector<int> listHalf;
    cur = list.head;

    for(int i = 0; i < count; i++){
        if(i < count/2){
            listHalf.push_back(cur->value);
        }else if(i == count/2 && count % 2 == 1){
            
        }else{
            if(listHalf[listHalf.size()-1] != cur->value){
                return false;
            }
            listHalf.pop_back();
        }
        cout << cur->value << endl;
        cur = cur->next;
    }
    return true;
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }
    vector<int> nums = {1, 2, 3, 2, 1};

    linkedList list = buildList(nums);

    cout << "List: " << endl;
    printList(list);

    cout << "Checking Palindrome" << endl;

    bool isPalindrome = checkPalindrome(list);

    if(isPalindrome){
        cout << "The linkedList is a Palindrome." << endl;
    }else{
        cout << "The linkedList is not a Palindrome." << endl;
    }

    return 0; 
}

//Inputs ./a.exe

//Issues
/*
The value of the nodes is hardcoded
No deallocation
*/

//Things I ran into
/*

*/