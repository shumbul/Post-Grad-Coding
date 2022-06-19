// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int &numRows) {
        vector<vector<int>> dp;
        dp.resize(numRows);
        dp[0]={1};
        for(int i=1;i<numRows;i++){
            dp[i].resize(i+1);
            dp[i][0]=1;
            for(int j=0;j<i;j++){
                dp[i][j+1]=dp[i-1][j];
                if((j+1)<i){
                    dp[i][j+1]+=dp[i-1][j+1];
                }
            }
        }
        return dp;
    }
};