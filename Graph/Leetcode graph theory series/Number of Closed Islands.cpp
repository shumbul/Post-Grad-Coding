// https://leetcode.com/problems/number-of-closed-islands/

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
    bool dfs(int i, int j, int &m, int &n, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        
        if(vis[i][j] || grid[i][j])
            return true;
        vis[i][j]=1;
        bool ans=true;
        for(int k=0;k<4;k++){
            int ni=dx[k]+i, nj=dy[k]+j;
            if(dfs(ni, nj, m, n, vis, grid)==false)
                ans=false;
        }
        return ans;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // basically, 0s neighbors can only be 1s and should not fall on the boundary
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int ans=0;
        // dfs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(dfs(i, j, m, n, vis, grid)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

/*
l=size of largest component
Time: O(m*n*l)
Space: O(m*n)
*/