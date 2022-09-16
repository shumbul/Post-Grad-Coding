// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
    void help(int pos, int num, int &k, string vec, unordered_set<int> &ans, int &n){
        // cout<<pos<<" "<<num<<" "<<vec<<" "<<"\n";
        if(pos==n-1){
            char ch='0'+num;
            vec.push_back(ch);
            stringstream ss;
            ss<<vec;
            int temp;
            ss>>temp;
            ans.insert(temp);
            return;
        }
        char ch='0'+num;
        vec.push_back(ch);
        if(num-k>=0){
            help(pos+1, num-k, k, vec, ans, n);
        }
        if(num+k<10){
            help(pos+1, num+k, k, vec, ans, n);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        // dfs
        string vec;
        unordered_set<int> ans;
        for(int i=1;i<10;i++)
            help(0, i, k, vec, ans, n);
        vector<int> res;
        for(auto &a:ans)
            res.push_back(a);
        return res;
    }
};

/*
    Time Complexity: O(2^n)
    Space Complexity: O(2^n)
*/