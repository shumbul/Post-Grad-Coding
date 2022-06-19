// https://leetcode.com/problems/target-sum/

// DP
class Solution {
    int dp[21][2001];   // includes positive plus negative targets
    int help(int i, vector<int>& nums, int target){
        if(i==nums.size()){
            if(target==0)
                return 1;
            return 0;
        }
        if(dp[i][target+1000]!=-1)
            return dp[i][target+1000];
        // add
        if(nums[i]<=target)
            return dp[i][target+1000] = help(i+1, nums, target-nums[i])+help(i+1, nums, target);
        
        // subtract
        return dp[i][target+1000] = help(i+1, nums, target);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(target>sum || (target+sum)%2)
            return 0;
        int t=(sum+target)/2;
        int ans=help(0, nums, t);
        return ans;
    }
};

// Recursion
class Solution {
    vector<pair<int, int>> dp;
    int help(int i, int &ans, vector<int>& nums, int target){
        if(i==nums.size()){
            if(target==0)
                return 1;
            return 0;
        }
        // add
        help(i+1, ans, nums, target-nums[i]);
        // subtract
        help(i+1, ans, nums, target+nums[i]);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        dp.resize(nums.size(), vector<pair<int, int>> ({-1, -1}));
        help(0, ans, nums, target);
        return ans;
    }
};