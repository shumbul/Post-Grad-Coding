// https://leetcode.com/problems/longest-consecutive-sequence/

class DSU {
    vector<int> par, rank;
public:
    DSU(int n){
        par.resize(n);        
        rank.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i, rank[i]=1;
    }
    int find(int a){
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
    void union_(int a, int b){
        a=find(a), b=find(b);
        if(a==b)
            return;
        if(rank[b]>=rank[a]){
            // b dominates
            rank[b]+=rank[a];
            par[a]=b;
        }
        else{
            rank[a]+=rank[b];
            par[b]=a;
        }
    }
    int res(int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, rank[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        // we union the indices
        DSU dsu(n);
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            // to find consecutive elements faster
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=i;
        }
        
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(vis.find(nums[i])!=vis.end()){
                cout<<i;
                continue;
            }
            if(mp.find(nums[i]-1)!=mp.end()){
                dsu.union_(mp[nums[i]-1], i);
            }
            if(mp.find(nums[i]+1)!=mp.end()){
                dsu.union_(mp[nums[i]+1], i);
            }
            vis.insert(nums[i]);
        }
        
        return dsu.res(n);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/