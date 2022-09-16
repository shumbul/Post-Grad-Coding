// https://leetcode.com/problems/fibonacci-number/submissions/

class Solution {
    vector<int> dp=vector<int>(31, -1);
public:
    int fib(int n) {
        if(dp[n]!=-1) return dp[n];
        if(n<2) return dp[n]=n;
        return dp[n]=fib(n-1)+fib(n-2);
    }
};