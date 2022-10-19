// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for(auto &e: edges){
            in[e[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(!in[i])
                ans.push_back(i);
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/