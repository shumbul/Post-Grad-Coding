// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int i:nums)
            a=a^i;
        return a;
    }
};