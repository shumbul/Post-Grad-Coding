// https://leetcode.com/problems/redundant-connection/

#define ll long long

class DSU{
public:
    vector<ll> par;
    DSU(ll n){
        par.resize(n);
        for(ll i=0;i<n;i++){
            par[i]=i;
        }
    }
    ll find(ll a){
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
    void union_(ll a, ll b){
        a=find(a), b=find(b);
        ll idx=max(a, b);
        par[a]=idx, par[b]=idx;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans(2,-1);
        DSU dsu(1001);
        for(int i=0; i<edges.size(); i++) {
            int a=dsu.find(edges[i][0]);
            int b=dsu.find(edges[i][1]);
            if(a!=b) {
                dsu.union_(a, b);
            }
            else {
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
            }
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/