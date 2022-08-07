// https://leetcode.com/problems/validate-binary-search-tree/

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
public:
    bool isValidBST(TreeNode* root, long long minLimit=LONG_MIN, long long maxLimit=LONG_MAX) {
        if(!root){
            return true;
        }
        if(root->val>=maxLimit || root->val<=minLimit){
            return false;
        }
        return isValidBST(root->left, minLimit, min(maxLimit, (long long)root->val))&&isValidBST(root->right, max(minLimit, (long long)root->val), maxLimit);
    }
};

/*
n=number of nodes
Time Complexity: O(n)
Space Complexity: O(n)
*/