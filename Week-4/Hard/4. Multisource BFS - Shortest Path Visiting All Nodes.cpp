// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

/*
    Approach:
    1. It says shortest path => BFS
    2. We can visit a node muliple times
    3. We can also visit any edge multiple times
    4. What's unique is that we won't repeat a configuration again
    5. For that we can maintain bitmap
    6. In the BFS, we need to start from every node because we need to catch the shortest path from any node
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<vector<int>> q;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            q.push({i, 1<<i, 0});
            st.insert({i, 1<<i});
        }
        while(!q.empty()){
            int s=q.size();
            // cout<<"-------\n";
            while(s--){
                auto f=q.front();
                q.pop();
                // cout<<f[0]<<" "<<f[1]<<" "<<f[2]<<"\n";
                if(f[1]==((1<<n)-1)){
                    return f[2];
                }
                for(int &neighbor: graph[f[0]]){
                    int mask = f[1] | (1<<neighbor);
                    if(st.find({neighbor, mask})==st.end()){
                        q.push({neighbor, mask, f[2]+1});
                        st.insert({neighbor, mask});
                    }
                }
            }
        }
        return -1;
    }
};

/*
Time: O(2^n)
Space: O(2^n)
*/