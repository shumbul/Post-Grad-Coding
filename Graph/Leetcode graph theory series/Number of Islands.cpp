// https://leetcode.com/problems/number-of-islands

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || vis[i][j]){
            return;
        }
        // cout<<i<<" "<<j<<"\n";
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            dfs(ni, nj, m, n, grid, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    // cout<<i<<" "<<j<<"\n";
                    dfs(i, j, m, n, grid, vis);
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