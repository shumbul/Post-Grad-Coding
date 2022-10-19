// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)
            return NULL;
        if(original==target)
            return cloned;
        auto left = getTargetCopy(original->left, cloned->left, target);      
        if(left)
            return left;
        auto right = getTargetCopy(original->right, cloned->right, target);
        if(right)
            return right;
        return NULL;
    }
};

/*
Time: O(n)
Space: O(n)
*/