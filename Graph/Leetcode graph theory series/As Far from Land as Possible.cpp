// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // DP, BFS
        // DP will be applied in BFS manner from 1s to all the 0s
        int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dist(m, vector<int> (n));
        // DP: pre-storing distances
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    dist[i][j]=0;
                else
                    dist[i][j]=INT_MAX;
            }
        }
        // BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    queue<vector<int>> q;   // i, j, distance
                    q.push({i,j,0});
                    while(!q.empty()){
                        auto f=q.front();
                        int pi=f[0], pj=f[1], distance=f[2];
                        q.pop();
                        for(int k=0;k<4;k++){
                            int ni=dx[k]+pi, nj=dy[k]+pj;
                            if(ni>=0 && nj>=0 && ni<n && nj<m &&grid[ni][nj]==0 && dist[ni][nj]>distance+1){
                                dist[ni][nj]=distance+1;
                                q.push({ni, nj, distance+1});
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ans=max(ans, dist[i][j]);
        }
        // excluding cases where either land or water does't exist
        if(ans==INT_MAX || ans==0)
            return -1;
        return ans;
    }
};

/*
l=size of the maximum component
Time: O(m*n*l)
Space: O(m*n)
*/