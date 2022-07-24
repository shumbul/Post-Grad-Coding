// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    void maxDepth(TreeNode* root, int tempAns, int &ans) {
        if(!root) return;
        ans=max(ans, tempAns);
        if(root->left) maxDepth(root->left, tempAns+1, ans);        
        if(root->right) maxDepth(root->right, tempAns+1, ans);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        maxDepth(root, 1, ans);
        return ans;
    }
};