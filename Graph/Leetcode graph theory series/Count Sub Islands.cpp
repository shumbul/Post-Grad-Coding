// https://leetcode.com/problems/count-sub-islands/

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
    bool dfs(int i, int j, int &m, int &n, vector<vector<bool>> &vis, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid2[i][j]==0){
            return true;
        }
        if(grid1[i][j]==0){
            return false;
        }
        // calculations
        vis[i][j]=true;
        bool ans=true;  // important! to completely traverse component
        for(int k=0;k<4;k++){
            int ni=dx[k]+i, nj=dy[k]+j;
            if(!dfs(ni, nj, m, n, vis, grid1, grid2))
                ans=false;
        }
        return ans;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(), m=grid2[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] && !vis[i][j]){
                    if(dfs(i, j, m, n, vis, grid1, grid2))
                        ans++;
                }
            }
        }
        return ans;
    }
};

/*
l=size of the maximum component
Time: O(m*n*l)
Space: O(m*n)
*/