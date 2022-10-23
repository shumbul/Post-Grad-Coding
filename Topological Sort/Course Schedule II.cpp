// https://leetcode.com/problems/course-schedule-ii/

class Solution {
    void topoSort(int i, vector<int> &ans, bool &isCyclic, vector<bool> &bag, vector<bool> &vis, int &n, vector<vector<int>> &graph){
        if(isCyclic)
            return;
        vis[i]=1;
        bag[i]=1;
        for(int &nbr: graph[i]){
            if(!vis[nbr]){
                topoSort(nbr, ans, isCyclic, bag, vis, n, graph);
            }
            else if(bag[nbr]){
                isCyclic=true;
                return;
            }
        }
        bag[i]=0;
        ans.push_back(i);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(vector<int> &pre: prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        // cycle detection should also be there
        
        vector<bool> vis(numCourses, false);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                vector<bool> bag(numCourses, false);
                bool isCyclic=false;
                topoSort(i, ans, isCyclic, bag, vis, numCourses, graph);
                if(isCyclic)
                    return {};
            }
        }
        return ans;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/