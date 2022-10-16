// https://leetcode.com/problems/number-of-provinces/

class Solution {
    void dfs(int i, vector<bool> &vis, map<int, vector<int>> &graph) {
        vis[i]=1;
        for(auto &nbr: graph[i]){
            if(!vis[nbr]){
                dfs(nbr, vis, graph);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        map<int, vector<int>> graph;
        
        // adj matrix to adj list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]){
                    graph[i].push_back(j);
                    // graph[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n, 0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
           if(!vis[i])
               dfs(i, vis, graph), cnt++;
        }
        
        return cnt;
    }
};

/*
Time Complexity: O(n*n)
Space Complexity: O(n*n)

where n= no. of words in wordList
        l= length of longest word
*/