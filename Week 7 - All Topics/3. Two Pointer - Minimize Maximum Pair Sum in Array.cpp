// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        auto v=nums;
        sort(v.begin(), v.end());
        int n=v.size();
        int ans=INT_MIN;
        for(int i=0;i<n/2;i++){
            ans=max(ans, v[i]+v[n-i-1]);
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/