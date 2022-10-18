// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
    bool dfs(int i, vector<int> &color, vector<vector<int>>& graph) {
        if(color[i])
            return color[i]==2;
        color[i]=1;
        for(int &nbr: graph[i]){
            if(color[nbr]==2) // safe
                continue;
            if(color[nbr]==1 || dfs(nbr, color, graph)==false)
                return false;
        }
        color[i]=2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        // white-gray-black dfs
        vector<int> color(n, 0);
        // white=0, gray=1, black=2
        for(int i=0;i<n;i++){
            if(dfs(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/