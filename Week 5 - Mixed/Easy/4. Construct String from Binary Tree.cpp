// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    void help(TreeNode* root, string &ans){
        if(!root)
            return;
        
        ans+=to_string(root->val);
        
        if(root->left || root->right){
            ans+='(';
            help(root->left, ans);
            ans+=')';
        }
        if(root->right){
            ans+='(';
            help(root->right, ans);
            ans+=')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        
        string ans;
        help(root, ans);
        
        return ans;
    }
};


/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/