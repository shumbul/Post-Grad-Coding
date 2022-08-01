// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void dfs(map<int, vector<int>> &mp, int diagLvl, Node* root)
{
    if(!root)
        return;
    mp[diagLvl].push_back(root->data);
    dfs(mp, diagLvl+1, root->left);
    dfs(mp, diagLvl, root->right);
}

vector<int> diagonal(Node *root)
{
   // your code here
   // dfs
   vector<int> ans;
   map<int, vector<int>> mp;
   dfs(mp, 0, root);
   for(auto &a:mp){
       for(auto &b: a.second){
           ans.push_back(b);
       }
   }
   return ans;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/