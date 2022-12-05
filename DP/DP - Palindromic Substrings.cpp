//

class Solution {
public:
    int countSubstrings(string s) {
        // 2D DP
        int n=s.length();
        int ans=0;
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len<=2){
                        dp[i][j]=1;
                    }
                    else if(i<n-1 && j>0){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    
                    if(dp[i][j]) 
                        ans++;
                }
            }
        }
        
        return ans;
    }
};

/*
Time, Space : O(n*m)
*/