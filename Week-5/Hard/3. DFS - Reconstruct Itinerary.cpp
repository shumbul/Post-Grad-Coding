// https://leetcode.com/problems/reconstruct-itinerary/

// Topological sorting based question
// But DFS
class Solution {
    void dfs(string air, vector<string> &ans, map<string, multiset<string>> &mp){
        auto multi_set=mp[air];
        for(auto &airport:multi_set){
            if(mp[air].find(airport)!=mp[air].end()){
                mp[air].erase(mp[air].find(airport));
                dfs(airport, ans, mp);
            }
        }
        ans.push_back(air);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // graph creation
        map<string, multiset<string>> mp;
        for(auto &t: tickets){
            mp[t[0]].insert(t[1]);
        }
        
        vector<string> ans;
        dfs("JFK", ans, mp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
n=size of tickets
    Time Complexity: O(n)
    Space Complexity: O(n)
*/