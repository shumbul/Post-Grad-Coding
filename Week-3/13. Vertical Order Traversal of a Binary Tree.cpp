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
    void getOrder(TreeNode* root, int lvl, int depth, map<int, vector<vector<int>>> &mp) {
        if(!root)
            return;
        mp[lvl].push_back({depth, root->val});
        getOrder(root->left, lvl-1, depth+1, mp);        
        getOrder(root->right, lvl+1, depth+1, mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,  vector<vector<int>>> mp;
        getOrder(root, 0, 0, mp);
        int s=mp.size();
        for(auto &a: mp){
            sort(a.second.begin(), a.second.end());   
        }
        for(auto &a:mp){
            vector<int> temp;
            for(auto b: a.second){
                temp.push_back(b[1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
Time complexity: 
    getOrder -> O(n), n is the no. of nodes in the tree
    map travelsal & sorting -> O(h*nlogn), h is the height of the tree
    => O(h*nlogn)
Space complexity: O(n)
*/