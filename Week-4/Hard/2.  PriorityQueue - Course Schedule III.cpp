// https://leetcode.com/problems/course-schedule-iii/

class Solution {
    static bool compare(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
public:
    int scheduleCourse(vector<vector<int>> courses) {
        int t=0;
        int ans=0;
        priority_queue<int> q;  // stores duration
        sort(courses.begin(), courses.end(), compare);
        for(auto &c:courses){
            t+=c[0];
            q.push(c[0]);
            if(t>c[1]){
                t-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};

/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/