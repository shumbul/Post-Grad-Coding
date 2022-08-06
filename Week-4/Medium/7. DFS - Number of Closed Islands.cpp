// https://leetcode.com/problems/number-of-closed-islands/

class Solution {
    void dfs(int i, int j, int &n, int &m, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=0)
            return;
        grid[i][j]=2;
        dfs(i+1, j, n, m, grid);
        dfs(i-1, j, n, m, grid);
        dfs(i, j+1, n, m, grid);
        dfs(i, j-1, n, m, grid);
    }
public:
    int closedIsland(vector<vector<int>> grid) {
        int n=grid.size(), m=grid[0].size();
        // step-1:
        // all 0s at the boundary and their connected groups will be 1s
        // because have a non-1 boundary, that is sea
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i, 0, n, m, grid);
            }
            if(grid[i][m-1]==0){
                dfs(i, m-1, n, m, grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs(0, j, n, m, grid);
            }
            if(grid[n-1][j]==0){
                dfs(n-1, j, n, m, grid);
            }
        }
        
        // step-2:
        // find the count of rest of the connected components formed by 0s
        // that's the answer
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n+m)
*/