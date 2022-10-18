// https://leetcode.com/problems/loud-and-rich/

class Solution {
    void dfs(int i, vector<int> &quiet, unordered_map<int, vector<int>> &graph, vector<int> &ans) {
        if(ans[i]!=-1)
            return;
        int least_quiet=i;

        for(int &nbr: graph[i]) {
            if(ans[nbr]==-1) dfs(nbr, quiet, graph, ans);
            if(quiet[ans[nbr]]<quiet[least_quiet]) 
                least_quiet=ans[nbr];
        }
        ans[i]=least_quiet;
    }

public: vector<int>loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int,vector<int>> graph;
        int n=quiet.size();
        vector<int> ans(n, -1);

        for(int i=0; i<richer.size(); i++) {
            graph[richer[i][1]].push_back(richer[i][0]);
            // having equal to or more money
        }
   
        for(int i=0; i<n; i++) {
            dfs(i, quiet, graph, ans);
        }

        return ans;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/