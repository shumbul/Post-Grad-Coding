// https://leetcode.com/problems/number-of-people-aware-of-a-secret

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(forget, 0);
        const int mod=1e9+7;
        dp[forget-1]=1;
        n--;
        while(n--){
            for(int i=0;i<forget-1;i++){
                dp[i]=dp[i+1];
            }
            int temp=0;
            for(int i=0;i<forget-delay;i++){
                temp=(temp+dp[i])%mod;
            }
            dp[forget-1]=temp;
        }
        
        int ans=0;
        for(int i=0;i<forget;i++){
            ans=(ans+dp[i])%mod;
        }
        
        return ans;
    }
};

/*
    Time Complexity: O(n*forget)
    Space Complexity: O(forget)
*/