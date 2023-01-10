// https://leetcode.com/problems/shortest-bridge/

class Solution {
    int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
    void dfsConvertTo2(int i, int j, int &m, int &n, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(vis[i][j] || grid[i][j]!=1)
            return;
        vis[i][j]=1;
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            dfsConvertTo2(i+dx[k], j+dy[k], m, n, vis, grid);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // Bascially, find the min distance between the 2 islands
        // DFS: we can make 2nd island's 1s as 2
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!vis[i][j]){
                    dfsConvertTo2(i, j, m, n, vis, grid);
                    goto converted;
                }
            }
        }

        converted:
        // BFS: now we will find min distance between 1s from any 2
        int dist=0, ans=-1;
        queue<pair<int, int>> q;
        vis.resize(n, vector<bool> (m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto p=q.front();
                q.pop();
                int pi=p.first, pj=p.second;
                for(int k=0;k<4;k++){
                    int ni=dx[k]+pi, nj=dy[k]+pj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==0){
                        if(grid[ni][nj]==1)
                            return dist;
                        if(grid[ni][nj]==0){
                            q.push({ni, nj});
                            vis[ni][nj]=1;
                        }
                    }
                }
            }
            dist++;
        }

        return ans;
    }
};

/*
TC: O(m*n)
SC: O(m*n)
*/

/*
[
[1,1,1,1,1],
[1,0,0,0,1],
[1,0,1,0,1],
[1,0,0,0,1],
[1,1,1,1,1]
]
*/