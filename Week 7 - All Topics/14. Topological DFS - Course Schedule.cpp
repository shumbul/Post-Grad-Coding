// https://leetcode.com/problems/course-schedule/

// Topological Sort using DFS: Detecting cycle in directed graph using DFS

class Solution {
    bool dfs(int i, vector<bool> &currVis, vector<bool> &vis, unordered_map<int, vector<int>> &graph) {
        vis[i]=1;
        currVis[i]=1;
        for(int &nbr: graph[i]){
            if(!vis[nbr]){
                if(dfs(nbr, currVis, vis, graph))
                    return true;
            }
            else if(currVis[nbr]){
                return true;
            }
        }
        currVis[i]=false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisite) {
        // create a graph -> adj list
        unordered_map<int, vector<int>> graph;
        for(int i=0;i<prerequisite.size();i++){
            graph[prerequisite[i][0]].push_back(prerequisite[i][1]);
        }
        // check for cycle
        // using dfs
        vector<bool> vis(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                vector<bool> currVis(numCourses, false);
                // cout<<i<<"\n";
                if(dfs(i, currVis, vis, graph))
                    return false;
            }
        }
        return true;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/