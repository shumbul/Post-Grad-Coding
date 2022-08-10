// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
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
*/

class Solution {
    map<Node*, Node*> copy;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        if(copy.find(node)==copy.end()){
            copy[node]=new Node(node->val, {});
            for(auto &n: node->neighbors){
                copy[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return copy[node];
    }
};

/*
n=number of nodes
Time Complexity: O(n)
Space Complexity: O(n)
*/