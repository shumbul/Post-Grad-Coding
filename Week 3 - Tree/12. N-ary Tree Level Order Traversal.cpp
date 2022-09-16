// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> lvl;
            int s=q.size();
            while(s--){
                auto top=q.front();
                q.pop();
                lvl.push_back(top->val);
                for(auto ch:top->children)
                    q.push(ch);
                }
            ans.push_back(lvl);
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/