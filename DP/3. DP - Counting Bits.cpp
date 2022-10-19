// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        // last digit in the binary representation of i = i&1
        // no. of ones in i = no. of ones in i/2 + last digit==1?1:0
        vector<int> ans(n+1, 0);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i>>1]+(i&1);
        }
        return ans;
    }
};