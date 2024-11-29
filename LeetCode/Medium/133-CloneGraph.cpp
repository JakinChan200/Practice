//133
//Given a reference of a node in a connected undirected graph, return a deep copy of the graph

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

auto init = []() -> bool {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return true;
}();

Node* dfs(Node* node, unordered_map<Node*, Node*> &map){
    if(map.find(node) != map.end()){
        return map[node];
    }

    Node* clone = new Node(node->val);
    map[node] = clone;

    for(Node* neighbor : node->neighbors){
        clone->neighbors.push_back(dfs(neighbor,map));
    }

    return clone;
}

Node* cloneGraph(Node* node) {
    if(!node) return node;

    unordered_map<Node*, Node*> map;

    return dfs(node, map);
}

int main(int argc, char** argv){
    
    return 0;
}