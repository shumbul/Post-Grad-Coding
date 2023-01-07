// https://leetcode.com/problems/possible-bipartition

// Similar problem: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
    class DSU {
    public:
        vector<int> par;
        DSU(int n){
            par.resize(n);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        void union_(int a, int b){
            a=find(a), b=find(b);
            par[a]=b;
        }
        int find(int a){
            if(par[a]==a)
                return a;
            return par[a]=find(par[a]);
        }
    };
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(auto &d: dislikes){
            graph[d[0]-1].push_back(d[1]-1);
            graph[d[1]-1].push_back(d[0]-1);
        }
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int nbr=graph[i][j];
                if(dsu.find(nbr)==dsu.find(i)){
                    return false;
                }
                // put neighbors in separate groups than node i
                dsu.union_(graph[i][0], nbr);
            }
        }
        return true;
    }
};

/*
Time: O(V+E)
Space: O(V+E)
*/