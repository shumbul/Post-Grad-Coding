// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        if(targetWords.size() && startWords.size()==0)
            return -1;
        if(targetWords.size()==0)
            return 0;
        // we can use sets
        set<set<char>> s;
        for(string &word: startWords){
            set<char> temp;
            for(char &c: word)
                temp.insert(c);
            s.insert(temp);
        }
        int ans=0;
        for(string &word: targetWords){
            set<char> ms;
            for(char &c: word){
                ms.insert(c);
            }
            for(char &c:word){
                // auto it = ms.find(c);
                ms.erase(c);
                if(s.find(ms)!=s.end()){
                    ans++;
                    break;
                }
                ms.insert(c);
            }
        }
        return ans;
    }
};

/*
ns=no. of words in startWords array
ls=length of the longest words in startWords
nt=no. of words in targetWords array
lt=length of the longest words in targetWords
Time: O(ns*ls + nt*lt)
Space: O(ns*ls + nt*lt)
*/