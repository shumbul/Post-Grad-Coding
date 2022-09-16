// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        int n=beginWord.length();
        for(string &s: wordList) {  // O(n*m)
            if(s.length()==n)
                words.insert(s);    // O(1)
        }
        if(words.find(endWord)==words.end()){   // O(m)
            return 0;
        }
        words.erase(beginWord); // O(m)
        
        // BFS
        queue<string> q;
        q.push(beginWord);  // O(m)
        int ans=0;
        
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                string curr=q.front(), temp;
                q.pop();
                if(curr==endWord){
                    return ans;
                }
                for(int i=0;i<n;i++){
                    temp=curr;
                    for(int k=0;k<27;k++){
                        temp[i]='a' + k;
                        if(words.find(temp)!=words.end()){
                            q.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

/*
Let n be the no. of words in the wordList and m be the length of the largest word in that list
Given m = 10, the time and space complexities are linear

Time Complexity: O(n*m*27) -> Linear
Space Complexity: O(n*m) -> Linear
*/