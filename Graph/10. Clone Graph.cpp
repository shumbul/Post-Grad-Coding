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
    // original and clone map
    unordered_map<Node*, Node*> clone;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        if(clone.find(node)==clone.end()){
            // using this check, we avoid cloning node again
            // eg. 1->2; 2->1 => if 1 is created and then 2 gets created
            // 1 won't get created again through 2 (nbr)
            clone[node]=new Node(node->val);
            for(Node* nbr: node->neighbors){
                clone[node]->neighbors.push_back(cloneGraph(nbr));
            }
        }
        return clone[node];
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/