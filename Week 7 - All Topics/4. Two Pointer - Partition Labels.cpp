// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        
        int i=0, j=0, siz=0;
        vector<int> ans;
        
        while(i<s.length()){
            j=max(j, mp[s[i]]);
            siz++;
            if(i>=j){
                ans.push_back(siz);
                siz=0;
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