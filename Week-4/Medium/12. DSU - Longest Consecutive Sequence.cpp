// https://leetcode.com/problems/longest-consecutive-sequence/

// Did a mistake in union find rank path compression
// rank[parent] has to be updated. Similarly, for parent.
// I initially updated the rank of child; Be aware! 

class DSU {
public:
    vector<int> par, rank;
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1, 1);
        for(int i=1;i<=n;i++)
            par[i]=i;
    }
    void Union(int a, int b){
        int par_a=Find(a);
        int par_b=Find(b);
        if(par_a!=par_b){
            if(rank[par_a]<=rank[par_b]){
                par[par_a]=par_b;
                rank[par_b]+=rank[par_a];
            }
            else{
                par[par_b]=par_a;
                rank[par_a]+=rank[par_b];
            }
        }
    }
    int Find(int a){
        if(a==par[a])
            return a;
        return par[a]=Find(par[a]);
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(n);
        map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]=i;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end())
                dsu.Union(mp[nums[i]], mp[nums[i]-1]);
            if(mp.find(nums[i]+1)!=mp.end())
                dsu.Union(mp[nums[i]], mp[nums[i]+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<dsu.rank[i]<<" "<<dsu.par[i]<<"\n";
            ans=max(ans, dsu.rank[i]);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/