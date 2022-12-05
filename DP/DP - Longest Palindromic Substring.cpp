// https://leetcode.com/problems/longest-palindromic-substring/

// length wise matrix taversal in DP
// substr in C++ takes (pos, len) if 2 integer args are passed
// https://www.geeksforgeeks.org/substring-in-cpp/

class Solution {
public:
    string longestPalindrome(string &s) {
        // 2D DP
        int n=s.length();
        string ans;
        ans.push_back(s[0]);
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=1;
                    }
                    else if(i<n-1 && j>0){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    
                    if(dp[i][j] && ans.size()<len){
                        // cout<<i<<" "<<j<<": ";
                        ans=s.substr(i, len);
                        // cout<<ans<<"\n";
                    }
                }
            }
        }
        
        return ans;
    }
};

/*
Time, Space : O(n*m)
*/