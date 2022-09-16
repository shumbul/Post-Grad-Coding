// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<1) return 0;
        int ans=1;
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        ans=*max_element(dp.begin(), dp.end());
        return ans;
    }
};