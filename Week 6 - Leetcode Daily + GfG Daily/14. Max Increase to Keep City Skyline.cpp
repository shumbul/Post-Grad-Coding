// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        auto temp=grid;
        // north
        for(int j=m-1;j>=0;j--){
            int mm=0;
            for(int i=0;i<n;i++){
                mm=max(grid[i][j], mm);
            }
            for(int i=0;i<n;i++){
                temp[i][j]=mm;
            }
        }
        // west
        for(int i=0;i<n;i++){
            int mm=0;
            for(int j=0;j<m;j++){
                mm=max(grid[i][j], mm);
            }
            for(int j=0;j<m;j++)
                temp[i][j]=min(temp[i][j],mm);
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<temp[i][j]<<" ";
                ans+=max(0, temp[i][j]-grid[i][j]);
            }
           // cout<<endl;
        }
        return ans;
    }
};

/*
Time: O(n*m)
Space: O(n*m)
*/