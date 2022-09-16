// https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long int> in(n, 0);
        for(auto &e: roads){
            in[e[1]]++;            
            in[e[0]]++;
        }
        
        sort(in.begin(), in.end());
        
        long long int ans=0;
        for(int i=0;i<n;i++)
            ans+=(in[i]*(i+1));
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/