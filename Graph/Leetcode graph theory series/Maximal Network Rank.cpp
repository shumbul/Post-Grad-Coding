// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> mp;
        for(auto &r: roads){
            mp[r[0]].insert(r[1]);
            mp[r[1]].insert(r[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool> vis(n, 0);
            // connected -> delete repeated network/edge
            for(int nbr: mp[i]){
                ans=max(ans, (int)mp[nbr].size()+(int)mp[i].size()-1);
                vis[nbr]=1;
            }
            // disconnected
            for(int j=0;j<n;j++){
                if(i!=j && !vis[j]){
                    ans=max(ans, (int)mp[i].size()+(int)mp[j].size());
                }
            }
        }
        return ans;
    }
};

/*
Time: O(n*n)
Space: O(n)
*/