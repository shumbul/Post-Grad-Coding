// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, INT_MAX);
        int maxi=-1;
        if(nums[0])
            dp[0]=0, maxi=0;
        for(int i=0;i<n && i<=maxi;i++){
            for(int j=i+1; j<=min(n-1, nums[i]+i);j++){
                dp[j]=min(dp[j], dp[i]+1);
            }
            maxi=max(maxi, nums[i]+i);
        }
        return dp[n-1]==INT_MAX?0:dp[n-1];
    }
};


/* 
Time: O(n^2)
Space: O(n)
*/