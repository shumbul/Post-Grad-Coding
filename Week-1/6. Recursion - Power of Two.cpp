// https://leetcode.com/problems/power-of-two/submissions/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        if(n==0 || n%2)
            return false;
        return isPowerOfTwo(n/2);
    }
};