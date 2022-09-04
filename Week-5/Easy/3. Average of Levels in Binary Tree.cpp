// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        // bfs
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> ans;
        while(!q.empty()){
            int s=q.size();
            int S=s;
            double d=0;
            while(s--){
                TreeNode* f=q.front();
                q.pop();
                d+=f->val;
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
            d/=S;
            ans.push_back(d);
        }
        return ans;
    }
};

/*
    Time Complexity: O(2^n)
    Space Complexity: O(2^n)
*/