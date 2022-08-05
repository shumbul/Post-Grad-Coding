// https://leetcode.com/problems/number-of-enclaves/

class Solution {
    vector<int> dx = {-1, 0, 1, 0}, dy={0, 1, 0, -1};
    
    void dfs(int i, int j, int &n, int&m, vector<vector<int>>& grid) {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1){
            return;
        }
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            dfs(i+dx[k], j+dy[k], n, m, grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i, 0, n, m, grid);
            }
            
            if(grid[i][m-1]==1){
                dfs(i, m-1, n, m, grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0, j, n, m, grid);
            }
            
            if(grid[n-1][j]==1){
                dfs(n-1, j, n, m, grid);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    grid[i][j]=1;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n+m)
*/