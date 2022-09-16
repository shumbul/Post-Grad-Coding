// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// gives TLE on large test cases as DP is required for the optimized solution

class Solution {
    bool help(int i, int bucketSum, int bucketNum, vector<bool> picked, vector<int>& nums, int &requiredSum, int &K){
        // base condition
        if(bucketNum==K){
            return true;
        }
        if(bucketSum==requiredSum){
            return help(0, 0, bucketNum+1, picked, nums, requiredSum, K);
        }
        else if(bucketSum>requiredSum){
            return false;
        }
        if(i>=nums.size())
            return false;

        if(picked[i]){
            // skip
            return help(i+1, bucketSum, bucketNum, picked, nums, requiredSum, K);
        }
        else{
            // skip
            bool op1 = help(i+1, bucketSum, bucketNum, picked, nums, requiredSum, K);
            // pick
            picked[i]=1;
            bucketSum+=nums[i];
            bool op2 = help(i+1, bucketSum, bucketNum, picked, nums, requiredSum, K);
            return op1 | op2;
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         // Write your code here.
        int n=nums.size();
        vector<bool> picked(n, false);
        int requiredSum=accumulate(nums.begin(), nums.end(), 0);
        if(requiredSum%k)
            return false;
        else requiredSum/=k;
        return help(0, 0, 0, picked, nums, requiredSum, k);
    }
};