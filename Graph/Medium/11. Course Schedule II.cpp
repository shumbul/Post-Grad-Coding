// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // Topological sort
        unordered_map<int, vector<int>> prereq;
        vector<int> inDeg(n, 0);
        for(auto &courses: prerequisites){
            prereq[courses[1]].push_back(courses[0]);   // implies course[0] should be ompleted first and then course[1] can be completed
            inDeg[courses[0]]++;
        }
        // insert all the courses with no prerequisite in a queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                // no prereq
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int courseNo=q.front();
            q.pop();
            ans.push_back(courseNo);
            for(int &course: prereq[courseNo]){
                inDeg[course]--;
                if(inDeg[course]==0){
                    q.push(course);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(inDeg[i])
                return {};
        }
        return ans;
    }
};

/*
V = no. of courses
E = total prerequisites
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/