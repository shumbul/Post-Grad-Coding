// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
    const int mod=1e9+7;
    vector<vector<int>> dp;
    int dfs(int i, int j, int prev, vector<vector<int>>& grid){
        if(min(i, j)<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=prev)
            return 0;
        return dp[i][j] ?: dp[i][j]=(1+dfs(i+1, j, grid[i][j], grid)+dfs(i, j+1, grid[i][j], grid)+dfs(i-1, j, grid[i][j], grid)+dfs(i, j-1, grid[i][j], grid))%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        dp.resize(n, vector<int> (m, 0));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=(ans+dfs(i, j, 0, grid))%mod;
        return ans;
    }
};

/*
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/