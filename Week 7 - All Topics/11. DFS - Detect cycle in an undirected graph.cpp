// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
    bool dfs(int i, vector<bool> &vis, int par, vector<int> adj[]) {
        vis[i]=1;
        for(int &nbr: adj[i]){
            if(nbr!=par && (vis[nbr] || dfs(nbr, vis, i, adj))){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        // using dfs
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i, vis, -1, adj))
                    return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/