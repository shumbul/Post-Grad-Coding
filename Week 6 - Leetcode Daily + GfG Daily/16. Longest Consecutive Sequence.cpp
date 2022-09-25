// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=0, temp=0, prev;
        bool first=true;
        for(auto &a: st){
            if(first){
                temp=1;
                prev=a;
                first=false;
            }
            else{
                if(a==prev+1){
                    temp++;
                    prev=a;
                }
                else{
                    temp=1;
                    prev=a;
                }
            }
            ans=max(ans, temp);
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/