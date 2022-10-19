// https://leetcode.com/problems/climbing-stairs/

// top-down
class Solution {
    int dp[46];
public:
    int climbStairs(int n) {
        if(dp[n]!=0)
            return dp[n];
        if(n==1)
            return dp[1]=1;
        if(n==2)
            return dp[2]=2;
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};

// bottom-up
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(46);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};