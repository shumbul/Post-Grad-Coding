// https://leetcode.com/problems/shifting-letters-ii/
        
// prefix sum
class Solution {
public:
    string shiftingLetters(string S, vector<vector<int>>& shifts) {
        vector<int> pre_sum(S.length()+1, 0);
        for(auto &s: shifts){
            // populating prefix sum
            if(s[2]==1)
                pre_sum[s[0]]++, pre_sum[s[1]+1]--;
            else
                pre_sum[s[0]]--, pre_sum[s[1]+1]++;
            
            // handling negative here itself
            if(pre_sum[s[0]]<0)
                pre_sum[s[0]]=25;
            if(pre_sum[s[1]+1]<0)
                pre_sum[s[1]+1]=25;
        }
        int sum=0;
        for(int i=0;i<S.length();i++){
            // fetching sum based on calculated prefix sum vector
            sum+=pre_sum[i];
            S[i]=((S[i]-'a'+sum)%26)+'a';
        }
        return S;
    }
};


/*
l = length of string s
n = size of shifts vector
    Time Complexity: O(max(l, n))
    Space Complexity: O(l)
*/


// brute force
class Solution {
public:
    string shiftingLetters(string S, vector<vector<int>>& shifts) {
        vector<int> all_shifts(S.length(), 0);
        for(auto &s: shifts){
            // this is time taking
            for(int i=s[0];i<=s[1];i++){
                if(s[2]==1)
                    all_shifts[i]++;
                else
                    all_shifts[i]--;
                if(all_shifts[i]<0)
                    all_shifts[i]=25;
            }
        }
        for(int i=0;i<S.length();i++){
            S[i]=((S[i]-'a'+all_shifts[i])%26)+'a';
        }
        return S;
    }
};


/*
l = length of string s
n = size of shifts vector
    Time Complexity: O(l*n)
    Space Complexity: O(l)
*/