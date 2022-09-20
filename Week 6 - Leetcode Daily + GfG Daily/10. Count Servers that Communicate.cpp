// https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        // index grid elements
        map<int, int> mpR, mpC;
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    mpR[i]++, mpC[j]++;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(mpR[i]>1 || mpC[j]>1)
                        ans++;
                }
            }
        }
        return ans;
    }
};

/*
Time: O(n*m)
Space: O(max(n, m))
*/