// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/


// Based on given constraints:
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
    void inorder(TreeNode* node, TreeNode* parent, int &start, unordered_map<int, TreeNode*> &par, TreeNode* &initialNodes){
        if(!node)
            return;
        if(node->val==start){
            initialNodes=node;
        }
        if(parent)
            par[node->val]=parent;
        inorder(node->left, node, start, par, initialNodes);        
        inorder(node->right, node, start, par, initialNodes);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> par;
        TreeNode* initialNodes;
        
        // Step-1 is to traverse and fill par map, initialNodes
        inorder(root, nullptr, start, par, initialNodes);
        // for(auto &p: par){
        //     cout<<p.first->val<<" "<<p.second->val<<"\n";
        // }
        
        // Step-2 BFS
        queue<TreeNode*> q;
        unordered_set<int> vis;
        q.push(initialNodes);
        vis.insert(initialNodes->val);
        
        int ans=0;
        
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                TreeNode* temp=q.front();
                q.pop();
                // cout<<temp->val<<" ";
                if(par.find(temp->val)!=par.end() && vis.find(par[temp->val]->val)==vis.end()){
                    q.push(par[temp->val]);
                    vis.insert(par[temp->val]->val);
                }
                if(temp->left && vis.find(temp->left->val)==vis.end()){
                        q.push(temp->left);
                        vis.insert(temp->left->val);
                }
                if(temp->right && vis.find(temp->right->val)==vis.end()){
                        q.push(temp->right);
                        vis.insert(temp->right->val);
                }
            }
            // cout<<"\n";
        }
        return ans-1;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

// General:
class Solution {
    void inorder(TreeNode* node, TreeNode* parent, int &start, map<TreeNode*, TreeNode*> &par, TreeNode* &initialNodes){
        if(!node)
            return;
        if(node->val==start){
            initialNodes=node;
        }
        if(parent)
            par[node]=parent;
        inorder(node->left, node, start, par, initialNodes);        
        inorder(node->right, node, start, par, initialNodes);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> par;
        TreeNode* initialNodes;
        
        // Step-1 is to traverse and fill par map, initialNodes
        inorder(root, nullptr, start, par, initialNodes);
        // for(auto &p: par){
        //     cout<<p.first->val<<" "<<p.second->val<<"\n";
        // }
        
        // Step-2 BFS
        queue<TreeNode*> q;
        set<TreeNode*> vis;
        q.push(initialNodes);
        vis.insert(initialNodes);
        
        int ans=0;
        
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                TreeNode* temp=q.front();
                q.pop();
                // cout<<temp->val<<" ";
                if(par.find(temp)!=par.end() && vis.find(par[temp])==vis.end()){
                    q.push(par[temp]);
                    vis.insert(par[temp]);
                }
                if(temp->left && vis.find(temp->left)==vis.end()){
                        q.push(temp->left);
                        vis.insert(temp->left);
                }
                if(temp->right && vis.find(temp->right)==vis.end()){
                        q.push(temp->right);
                        vis.insert(temp->right);
                }
            }
            // cout<<"\n";
        }
        return ans-1;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/