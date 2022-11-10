// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        map<int, set<int>> graph;
        
        // we are building inverted tree -> decide the leaves first
        for(auto &e: edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        queue<int> q;
        for(auto &e: graph){
            if(e.second.size()==1)
                q.push(e.first);
        }
        
        while(!q.empty()){
            int s=q.size();
            if(n<=2)
               break; 
            while(s--){
                int f=q.front();
                q.pop();
                n--;
                for(int nbr: graph[f]){
                    graph[nbr].erase(f);
                    if(graph[nbr].size()==1)
                        q.push(nbr);
                }
            }
        }
        
        // tree was constructed leaves to root
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/