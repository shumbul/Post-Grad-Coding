// https://leetcode.com/problems/island-perimeter/

class Solution {
    vector<int> dx={-1, 0, 1, 0}, dy={0, 1, 0, -1};
    void dfs(int i, int j, int &ans, vector<vector<bool>> &vis, int &n, int &m, vector<vector<int>>& grid) {
        for(int k=0;k<4;k++){
            int ii=i+dx[k], jj=j+dy[k];
            if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]){
                if(!vis[ii][jj]){
                    vis[ii][jj]=1;
                    dfs(ii, jj, ans, vis, n, m, grid);
                }
            }
            else{
                ans++;
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    vis[i][j]=true;
                    dfs(i, j, ans, vis, n, m, grid);
                    return ans;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/