// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    void minDepth(TreeNode* root, int tempAns, int &ans) {
        if(!root) return;
        if(!root->left && !root->right)
            ans=min(ans, tempAns);
        if(root->left) minDepth(root->left, tempAns+1, ans);        
        if(root->right) minDepth(root->right, tempAns+1, ans);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        minDepth(root, 1, ans);
        return ans;
    }
};