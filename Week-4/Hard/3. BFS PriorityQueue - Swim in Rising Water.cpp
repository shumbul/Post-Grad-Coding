// https://leetcode.com/problems/swim-in-rising-water/

class Solution {
    struct comp{
        bool operator()(vector<int> const&v1, vector<int> const&v2){
            return v1[0]>v2[0];
        }
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool> (grid[0].size(), 0));
        priority_queue< vector<int>, vector <vector <int> >, comp> pq;
        pq.push({grid[0][0], 0, 0}); // time, x, y
        seen[0][0]=1;
        vector<int> dx={-1, 0, 1, 0}, dy={0, -1, 0, 1};
        int ans=INT_MAX;
        while(1){
            auto v=pq.top();
            pq.pop();
            int t=v[0];
            // cout<<t<<" "<<v[1]<<" "<<v[2]<<"\n";
            if(v[1]==grid.size()-1 && v[2]==grid[0].size()-1)
                return t;
            for(int k=0;k<4;k++){
                int i=v[1]+dx[k], j=v[2]+dy[k];
                if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !seen[i][j]){
                    int newTime=t;
                    if(grid[i][j]>newTime){
                        newTime=grid[i][j];
                    }
                    pq.push({newTime, i, j});
                    seen[i][j]=1;
                    // cout<<newTime<<" "<<i<<" "<<j<<"\n";
                }
            }
        }
        return -1;
    }
};

/*
Time Complexity: O((n*m)log(n*m)) - Priority queue
Space Complexity: O(n*m)
*/