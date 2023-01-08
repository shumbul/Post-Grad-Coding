// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
    void dfs(int i, int j, int height, int m, int n, vector<vector<int>> &vis, vector<vector<int>>& heights, bool pacific) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==2 || heights[i][j]<height)
            return;
        // avoid repitions
        if(pacific && vis[i][j]==1 || !pacific && vis[i][j]==-1)
            return;
        // vis
        if(vis[i][j]==0)
            vis[i][j]=pacific?1:-1;
        else if(vis[i][j]==1 && !pacific){
            vis[i][j]=2;
        }
        // recursion
        for(int k=0;k<4;k++){
            int ni=dx[k]+i, nj=dy[k]+j;
            dfs(ni, nj, heights[i][j], m, n, vis, heights, pacific);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // imagine the reverse situation
        // water is coming to cells and we have to return cells where water is reached from both the oceans
        // pacific ocean
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> ans;
        // pacific
        for(int i=0;i<n;i++){
            dfs(i, 0, heights[i][0], m, n, vis, heights, true);
        }
        for(int j=0;j<m;j++){
            dfs(0, j, heights[0][j], m, n, vis, heights, true);
        }
        // atlantic
        for(int i=0;i<n;i++){
            dfs(i, m-1, heights[i][m-1], m, n, vis, heights, false);
        }
        for(int j=0;j<m;j++){
            dfs(n-1, j, heights[n-1][j], m, n, vis, heights, false);
        }
        // answer
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==2)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};

/*
TC: O(m*n)
SC: O(m*n)
*/