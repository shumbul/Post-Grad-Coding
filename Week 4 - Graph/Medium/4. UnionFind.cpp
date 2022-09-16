// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
    vector<int> par, rank;
    void Union(int a, int b){
        int par_a=Find(a);
        int par_b=Find(b);
        // Note that parent or parent is attached to other's parent and not the parent of child
        if(par_a!=par_b){
            if(rank[a]>rank[b]){
                par[par_b]=par_a;
                rank[par_a]++;
            }
            else{
                par[par_a]=par_b;
                rank[par_b]++;
            }
        }
    }
    int Find(int a){
        if(a==par[a])
            return a;
        return par[a]=Find(par[a]);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        par.resize(n, 0);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto &e: edges){
            Union(e[0], e[1]);
//             cout<<e[0]<<'&'<<e[1]<<"\n\n";
            
//             for(int i=0;i<n;i++){
//                 cout<<i<<' '<<par[i]<<"\n";
//             }
        }
        return Find(src)==Find(dest);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/