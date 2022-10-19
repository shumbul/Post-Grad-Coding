// https://leetcode.com/problems/jump-game 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // two pointer
        int i;
        // our first pointer
        int maxi=0;
        // our second pointer
        
        for(i=0;i<nums.size()&&i<=maxi;i++){
            maxi=max(maxi, nums[i]+i);
        }
        return i==nums.size();
    }
};

/* 
Time: O(n)
Space: O(n)
*/