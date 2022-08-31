// https://leetcode.com/problems/shifting-letters-ii/

class Solution {
public:
    string shiftingLetters(string S, vector<vector<int>>& shifts) {
        // brute force
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