// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, int> table;
        int k=0;
        for(char &c: key){
            if(c!=' ' && table.find(c)==table.end()){
                table[c]=k++;
            }
        }
        string ans;
        for(auto &m: message){
            if(m==' ')
                ans+=' ';
            else
                ans+=table[m]+'a';
        }
        return ans;
    }
};

/*
n=size of key
    Time Complexity: O(n)
    Space Complexity: O(n)
*/