// https://leetcode.com/problems/largest-palindromic-number

class Solution {
public:
    string largestPalindromic(string num) {
        map<int, int> mp;
        // time: O(1), space: O(10)
        for(char c:num){
            mp[c-'0']++;
        }
        if(mp.size()==1){
            if(num[0]!='0')
                return num;
            return "0";
        }
        priority_queue<int> even, one;

        // time: O(10log10)
        for(auto &a:mp){
            // cout<<a.first<<" "<<a.second<<"\n";
            if(a.second%2){
                one.push(a.first);
                if(a.second>1)
                    even.push(a.first);
            }
            else{
                even.push(a.first);
            }
        }
        
        // base case
        string ans;
        if(even.size() && even.top()==0){
            ans=(one.top()+'0');
            return ans;
        }

        // time: O(10*n)
        while(!even.empty()){
            int a=even.top();
            even.pop(); 
            int half=mp[a]/2;
            while(half--)
                ans+=(a+'0');
        }
        string temp=ans;

        // time: O(n)
        reverse(temp.begin(), temp.end());
        if(one.size()){
            ans+=(one.top()+'0');
        }
        ans+=temp;
        return ans;
    }
};

/*
Note that we can also loop ver numbers 0 to 9 ans avoid priority queue 
    Time Complexity: O(n)
    Space Complexity: O(n)
*/