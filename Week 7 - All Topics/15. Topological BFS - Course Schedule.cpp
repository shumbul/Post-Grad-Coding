// https://leetcode.com/problems/course-schedule/

// Topological Sort using BFS: Detecting cycle in directed graph using BFS

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisite) {
        int np=prerequisite.size();
        // create a graph -> adj list
        unordered_map<int, vector<int>> graph;
        vector<int> inDeg(n, 0);
        for(int i=0;i<np;i++){
            graph[prerequisite[i][1]].push_back(prerequisite[i][0]);
            inDeg[prerequisite[i][0]]++;
        }
        // check for cycle
        // using bfs
        vector<bool> vis(n, false);
        // store all the courses with no dependency in queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i), vis[i]=true;
            }
        }
        while(!q.empty()){
            int s=q.size();
            while(s--) {
                int f=q.front();
                q.pop();
                for(int &nbr: graph[f]){
                    if(vis[nbr])
                        return false;
                    inDeg[nbr]--;
                    if(inDeg[nbr]==0)
                        q.push(nbr), vis[nbr]=true;
                }
            }
        }
        // checking if we have completed all the courses
        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;
        return true;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/