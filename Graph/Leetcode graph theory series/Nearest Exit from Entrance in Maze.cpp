// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // BFS
        int n=maze.size(), m=maze[0].size();
        int ei=entrance[0], ej=entrance[1];        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int ans=0;
        int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

        q.push({ei, ej});
        vis[ei][ej]=1;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto p=q.front();
                int pi=p.first, pj=p.second;
                q.pop();
                if(!(pi==ei && pj==ej) && (pi==0||pj==0||pi==n-1||pj==m-1)){
                    return ans;
                }
                for(int k=0;k<4;k++){
                    int ni=dx[k]+pi, nj=dy[k]+pj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && maze[ni][nj]=='.'){
                        q.push({ni, nj});
                        vis[ni][nj]=1;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};

/*
TC: O(m*n)
SC: O(m*n)
*/