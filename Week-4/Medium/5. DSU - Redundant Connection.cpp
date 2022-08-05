// https://leetcode.com/problems/redundant-connection/

class DSU {
    vector<int> par, rank;
public:
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
            if(rank[a]<rank[b]){
                par[par_a]=par_b;
                rank[b]++;
            }
            else{
                par[par_b]=par_a;
                rank[a]++;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(2*n);
        vector<int> ans;
        for(auto &e: edges){
            int a=e[0], b=e[1];
            int par_a=dsu.Find(a);
            int par_b=dsu.Find(b);
            if(par_a!=par_b){
                dsu.Union(par_a, par_b);
            }
            else{
                ans=e;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/