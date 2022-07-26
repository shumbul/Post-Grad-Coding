// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int ans=0;
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1+max(height(root->left), height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        ans=max(ans,  leftHeight+rightHeight+1);
        return ans>0?ans-1:ans;
    }
};