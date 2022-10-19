// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisite) {
        // No cycle should be there
        // There should be a valid Topological sort in order to return true
        vector<int> inDeg(n);
        unordered_map<int, vector<int>> prereq;
        for(auto &p: prerequisite){
            inDeg[p[0]]++;
            prereq[p[1]].push_back(p[0]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(inDeg[i]==0)
                q.push(i), vis[i]=true;
        }
        // queue contains all the courses with no dependencies
        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(int &course: prereq[course]){
                if(vis[course])
                    return false;
                inDeg[course]--;
                if(inDeg[course]==0){
                    vis[course]=true;
                    q.push(course);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};

/*
Time Complexity: O(V+E) - Topological sorting
Space Complexity: O(V+E) - Adjacency list map
*/