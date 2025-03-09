#include <iostream>
#include <queue>

using namespace std;

struct node{
    vector<node> child;
};

int BFS(node root){
    queue<node> q;
    q.push(root);

    while(!q.empty()){
        node currNode = q.pop();
        for(auto child : currNode){
            if(condition is met){ return child}

            q.push(child);
        }
    }
    return;
}
