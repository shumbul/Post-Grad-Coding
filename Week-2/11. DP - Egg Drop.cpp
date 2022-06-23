// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

// recursive DP - gives TLE
class Solution {
    int help(int e, int f, vector<vector<int>> &dp) {
        if(dp[e][f]!=-1)
            return dp[e][f];
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        if(e==1)
            return f;
        if(f==0)
            return 0;
        int mini=INT_MAX;
        int val=INT_MAX;
        for(int i=1;i<=f;i++){
            val=min(val,max(superEggDrop(e-1, i-1), superEggDrop(e, f-i)));   // breaks, unbroken
        }
        mini=val+1;
        return dp[e][f]=mini;
    }
public:
    int superEggDrop(int e=2, int f) {
        vector<vector<int>> dp(101, vector<int> (10001, -1));
        return help(e, f, dp);
    }
};

// 2D DP k*n giving TLE
class Solution {
public:
    int superEggDrop(int k=2, int n) {
        int dp[k+1][n+1];
        memset(dp, 0, sizeof dp);
        for(int j=1;j<=n;j++){
            dp[1][j]=j;
        }
        for(int i=2;i<=k;i++){  // eggs
            for(int j=1;j<=n;j++){  // floors
                dp[i][j]=1;
                // starting with diff floors
                int m=INT_MAX;
                for(int a=1;a<=j;a++){
                    m=min(m, max(dp[i-1][a-1], dp[i][j-a]));  // broken, unbroken
                }
                dp[i][j]+=m;
            }
        }
        return dp[k][n];
    }
};