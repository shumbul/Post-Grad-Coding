// https://leetcode.com/problems/is-graph-bipartite/

// BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, 0);
        for(int node=0;node<n;node++){
            if(color[node]!=0)
                continue;
            queue<int> q;
            q.push(node);
            color[node]=1;
            while(!q.empty()){
                int frontNode=q.front();
                q.pop();
                for(int &nbr: graph[frontNode]){
                    if(color[nbr]==color[frontNode]){
                        return false;
                    }
                    if(color[nbr]==0){
                        color[nbr]=-color[frontNode];
                        q.push(nbr);
                    }
                }
            }
        }
        return true;
    }
};
/*
Time: O(V+E)
Space: O(V+E)
*/

// DFS
class Solution {
    bool dfs(int node, vector<int> &color, vector<vector<int>>& graph) {
        for(int &nbr: graph[node]){
            if(color[nbr]==color[node])
                return false;
            if(color[nbr]==0){
                color[nbr]=-color[node];
                if(dfs(nbr, color, graph)==false)
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, 0);
        for(int node=0;node<n;node++){
            if(color[node]!=0)
                continue;
            color[node]=1;
            if(dfs(node, color, graph)==false){
                return false;
            }
        }
        return true;
    }
};

/*
Time: O(V+E)
Space: O(V+E) (stack space)
*/


// DSU

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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
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
Time: O((V+E)log(V+E))
Space: O(V)
*/