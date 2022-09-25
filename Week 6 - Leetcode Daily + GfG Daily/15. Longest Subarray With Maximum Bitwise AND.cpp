// https://leetcode.com/contest/weekly-contest-312/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // the bitwise AND of n numbers will atmost be n
        // the max bitwise of n numbers will be the case when only the maximum number is present
        // that's why we would only include the maximum element
        int max_=*max_element(nums.begin(), nums.end());
        int ans=0, temp=0;
        int i=0, n=nums.size();
        while(i<n){
            if(nums[i]==max_){
                temp=0;
                while(i<n && nums[i++]==max_){
                    temp++;
                }
                ans=max(ans, temp);
            }
            i++;
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/