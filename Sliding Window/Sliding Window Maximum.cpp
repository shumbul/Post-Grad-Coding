// https://leetcode.com/problems/sliding-window-maximum/

// we can also solve it using deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        
        // base case
        if(n<=k){
            int max_=nums[0];
            for(int i=1;i<n;i++)
                max_=max(nums[i], max_);
            return {max_};
        }
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        // first iteration
        for(int i=0;i<k;i++){
            if(pq.empty()){
                pq.push({nums[i], i});
            }
            else if(pq.top().first<=nums[i]){
                while(pq.size())
                    pq.pop();
                pq.push({nums[i], i});
            }
            else{
                pq.push({nums[i], i});
            }
        }
        ans.push_back(pq.top().first);
        
        // next iterations
        int pos=k;
        while(pos<n){
            if(pq.top().first<=nums[pos]){
                while(pq.size())
                    pq.pop();
                pq.push({nums[pos], pos});
            }
            else{
                while(!pq.empty() && pq.top().second<=pos-k)
                    pq.pop();
                pq.push({nums[pos], pos});
            }
            ans.push_back(pq.top().first);
            pos++;
        }
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/