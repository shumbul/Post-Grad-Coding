// https://leetcode.com/contest/biweekly-contest-96/problems/minimum-operations-to-make-array-equal-ii/

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long inc=0, dec=0;
        
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]==nums2[i]){
                continue;
            }
            if(k==0)
                return -1;
            long long diff=abs(nums1[i]-nums2[i]);
            if(diff%k)
                return -1;
            if(nums1[i]>nums2[i]){
                dec+=(diff/k);
                // nums1[i]=nums1[i]-diff=nums2[i]
            }
            else{
                inc+=(diff/k);
                // nums1[i]=nums1[i]+diff=nums2[i]
            }
        }
        return inc==dec?inc:-1;
    }
};

/*
Time: O(n)
Space: O(1)
*/