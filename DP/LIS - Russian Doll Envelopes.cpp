// https://leetcode.com/problems/russian-doll-envelopes/
// LIS in (nlogn)

class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        if(n==0)
            return 0;
        sort(env.begin(), env.end(), cmp);
        vector<int> lis;
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(), lis.end(), env[i][1])-lis.begin();
            if(it>=lis.size()) lis.push_back(env[i][1]);
            else lis[it]=env[i][1];
        }
        return lis.size();
    }
};

/*
eg1.
(2,1) (2,6) (3,4) -> 1,4
(2,6) (2,1) (3,4) -> 1,4

eg2.
[[4,5],[4,6],[6,7],[2,3],[1,1]]

[[1,1],[2,3],[4,5],[4,6],[6,7]]  [1,3,5,6,7]
[[1,1],[2,3],[4,6],[4,5],[6,7]]  [1,3,6,7]
*/
