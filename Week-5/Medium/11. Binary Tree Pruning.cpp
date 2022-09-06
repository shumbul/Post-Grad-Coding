// https://leetcode.com/problems/binary-tree-pruning/

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
    bool help(TreeNode* root){
        if(!root)
            return false;
        bool ansR=false, ansL=false;
        if(help(root->left)){
            root->left=NULL;
            ansL=true;
        }
        if(help(root->right)){
            root->right=NULL;
            ansR=true;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val==0?true:false;
        }
        return ansL&&ansR;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        help(root);
        if(root->val==0 && root->left ==NULL && root->right==NULL)
            return NULL;
        return root;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/