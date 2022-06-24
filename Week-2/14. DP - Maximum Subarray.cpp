// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
         // Your code here
        int maxSum=INT_MIN, sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxSum=max(maxSum, sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
    }
};