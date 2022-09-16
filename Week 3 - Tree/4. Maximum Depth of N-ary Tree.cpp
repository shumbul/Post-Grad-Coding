// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    void maxDepth(Node* root, int tempAns, int &ans) {
        if(!root) return;
        ans=max(ans, tempAns);
        
        for(auto ch:root->children)
            if(ch) maxDepth(ch, tempAns+1, ans);
    }
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int ans = 1;
        maxDepth(root, 1, ans);
        return ans;
    }
};