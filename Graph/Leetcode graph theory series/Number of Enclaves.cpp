// https://leetcode.com/problems/number-of-enclaves/

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
    bool dfs(int i, int j, int &m, int &n, vector<vector<bool>> &vis, vector<vector<int>>& grid, int &siz) {
        // returns false if component touches the boundary
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        // the cases to ignore
        if(vis[i][j] || grid[i][j]==0){
            return true;
        }
        // calculations
        siz++;
        vis[i][j]=true;
        bool ans=true;  // important! to completely traverse component
        for(int k=0;k<4;k++){
            int ni=dx[k]+i, nj=dy[k]+j;
            if(!dfs(ni, nj, m, n, vis, grid, siz))
                ans=false;
        }
        return ans;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Basically, the ques expects us to return no. of 1s in such components who are not touching the boundary
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    int siz=0;
                    if(dfs(i, j, m, n, vis, grid, siz))
                        ans+=siz;
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