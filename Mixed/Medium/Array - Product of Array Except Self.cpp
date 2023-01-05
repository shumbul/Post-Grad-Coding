// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // right and left products
        int n=nums.size();
        vector<int> right(n, 1), left(n, 1);
        
        // populate values in rigth and left
        int rightprod=1;
        for(int i=0;i<n;i++){
            right[i]=rightprod;
            rightprod*=nums[i];
        }
        int leftprod=1;
        for(int i=n-1;i>=0;i--){
            left[i]=leftprod;
            leftprod*=nums[i];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            // cout<<right[i]<<" "<<left[i]<<"\n";
            ans[i]=(right[i]*left[i]);
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/