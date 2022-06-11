// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n==0 || n%4)
            return false;
        return isPowerOfFour(n/4);
    }
};