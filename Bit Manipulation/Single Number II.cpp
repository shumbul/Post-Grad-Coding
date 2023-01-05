// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto a:nums) x^=a;
        vector<int> v(32);
        for(auto a:nums) {
            int y = x^a;
            for(int i=0;i<32;i++) {
                if((y>>i)&1)v[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++) {
           // cout<<i<<" "<<v[i]<<endl;
            if(v[i]%3)ans+=(1<<i);
        }
        for(auto a:nums) ans^=a;
        return ans;
    }
};

/*
Time: O(1) (or O(32), Linear)
Space: O(1)
*/