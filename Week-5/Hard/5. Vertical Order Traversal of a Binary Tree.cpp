// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    void help(TreeNode* root, map<int, vector<vector<int>>> &mp, int lvl, int depth){
        if(!root)
            return;
        mp[lvl].push_back({depth, root->val});
        // 0: {0, 1} {2, 5}       
        // -1: {1, 2}      
        // -2: {2, 4}
        // 1: {1, 4}
        // 0: {2, 6}
        // 2: {2, 7}

        help(root->left, mp, lvl-1, depth+1);
        help(root->right, mp, lvl+1, depth+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<vector<int>>> mp;
        help(root, mp, 0, 0);
        for(auto &a: mp)
            sort(a.second.begin(), a.second.end());
        vector<vector<int>> ans;
        for(auto &a: mp){
            vector<int> temp;
            for(auto &b: a.second)
                temp.push_back(b[1]);
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/