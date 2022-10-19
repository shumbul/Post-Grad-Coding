// https://leetcode.com/problems/redundant-connection-ii/

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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> inDegEdge(1001, -1);
        DSU dsu(1001);
        
        // noting down the last edge in edges having more than 1 parent
        int d1=-1, d2=-1;
        for(int i=0; i<n; i++){
            if(inDegEdge[edges[i][1]]==-1){
                inDegEdge[edges[i][1]]=i;
            }
            else{
                d1=inDegEdge[edges[i][1]];
                d2=i;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i==d2)
                continue;
            int a=dsu.find(edges[i][0]);
            int b=dsu.find(edges[i][1]);
            if(a!=b) {
                dsu.union_(a, b);
            }
            else {
                // the edge with more than 1 parent
                if(d1!=-1){
                    return edges[d1];
                }
                return edges[i];
            }
        }
        return edges[d2];
    }
};

/*
Time: O(n)
Space: O(n)
*/