// https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        // base condition
        if(changed.size()%2){
            // cannot be doubled array
            return ans;
        }
        
        // sort
        sort(changed.begin(), changed.end());
        int n=changed.size();
        
        multimap<int, int> mp;
        
        for(int i=0;i<n;i++){
            mp.insert({changed[i],i});
        }
        
        for(int i=0;i<n;i++){
            // add to original
            // if it's double exists
            if(mp.find(changed[i])!=mp.end()){
                mp.erase(mp.find(changed[i]));
                int req=2*changed[i];
                if(mp.find(req)!=mp.end()){
                    mp.erase(mp.find(req));
                    ans.push_back(changed[i]);
                }
                else
                    return {};
            }
        }
        return ans;
    }
};

/*
Time complexity: O(nlogn)
Space complexity: O(n)
*/