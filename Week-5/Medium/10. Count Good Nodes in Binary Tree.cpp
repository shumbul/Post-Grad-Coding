// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(int &cnt, TreeNode* node, int highest){
        if(!node){
            return;
        }
        if(node->val>=highest){
            cnt++;
        }
        dfs(cnt, node->left, max(highest, node->val));
        dfs(cnt, node->right, max(highest, node->val));
    }
public:
    int goodNodes(TreeNode* root) {
        // dfs
        int cnt=0;
        dfs(cnt, root, root->val);
        return cnt;
    }
};


/*
    Time Complexity: O(n)
    Space Complexity: O(logn)
*/