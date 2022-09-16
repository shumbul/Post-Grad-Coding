// https://leetcode.com/problems/edit-distance/

// class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        if(n1==0)return n2;
        if(n2==0)return n1;
        long long dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=i;
        }
        dp[0][0]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        return dp[n1][n2];
    }
};