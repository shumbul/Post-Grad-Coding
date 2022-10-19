// https://leetcode.com/problems/max-area-of-island/

class Solution {
    vector<int> dx={-1, 0, 1, 0}, dy={0, 1, 0, -1};
    void dfs(int i, int j, int &size, 
        vector<vector<bool>>& vis, int &m, int &n, vector<vector<int>>& grid)
    {
        if( i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!=1){
            return;
        }
        
        size++;
        vis[i][j]=1;
        
        for(int k=0;k<4;k++){
            int newi=i+dx[k], newj=j+dy[k];
            dfs(newi, newj, size, vis, m, n, grid);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(), m=grid[0].size();
        
        int size=0;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    // it is a land
                    // let's find the size
                    size=0;
                    
                    if(!vis[i][j])
                        dfs(i, j, size, vis, m, n, grid);
                    ans=max(ans, size);
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