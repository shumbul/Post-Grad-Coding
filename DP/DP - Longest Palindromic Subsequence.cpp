// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 2D DP
        int n=s.length();
        int ans=1;
        vector<vector<int>> dp(n, vector<int> (n, 1));
        
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=2;
                    }
                    else if(i<n-1 && j>0){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                    ans=max(ans, dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return ans;
    }
};

/*
Time, Space : O(n*m)
*/