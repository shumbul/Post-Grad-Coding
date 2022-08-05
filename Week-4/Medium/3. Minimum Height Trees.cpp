// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edge) {
        if(n==1)
            return {0};
        unordered_map<int, unordered_set<int>> mp;
        for(auto &e: edge){
            mp[e[0]].insert(e[1]);                       
            mp[e[1]].insert(e[0]);
        }
        queue<int> q;
        for(auto &e:mp){
            if(e.second.size()==1)
                q.push(e.first);
        }
        
        while(!q.empty()){
            int s=q.size();
            if(n<=2){
                break;
            }
            while(s--){
                int f=q.front();
                q.pop();
                for(auto &e: mp[f]){
                    mp[e].erase(f);
                    if(mp[e].size()==1){
                        q.push(e);
                    }
                }
                n--;
            }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/