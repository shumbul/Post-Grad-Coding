// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        vector<int> indeg(numCourses, 0);
        
        for(auto &pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        
        queue<int> q;
        vector<bool> completed(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0)
                q.push(i), completed[i]=true;
        }
        
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int &nbr: graph[f]){
                if(completed[nbr])
                    return false;
                indeg[nbr]--;
                if(indeg[nbr]==0)
                    q.push(nbr), completed[nbr]=true;
            }
        }
        
        for(bool truth: completed)
            if(!truth)
                return false;
        
        return true;
    }
};

/*
Time: O(n+v)
Space: O(n+v)
*/