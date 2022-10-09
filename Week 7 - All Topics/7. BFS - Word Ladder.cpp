// https://leetcode.com/problems/word-ladder/

/*
Notes:
    hit -> cog
    - for the beginWord, it doesn't matter if it is in the wordList or not
    - for the endWord, it does - otherwise how will we even reach to endWord?
    -1- thus, the first thing that we need to check is whether the endWord is present in the wordList or not
    - as the problem is about finding the minimum length path 
        for the transition from beginWord to endWord
    -2- we will use BFS, thus a Queue data structure
    - initially, we will push the beginWord into the queue
    - it is important to process all the words at a level together
    - because they should all be treated equally
    -3- for that, we will pop the queue elements level by level
    - for each word, we need to find it's neighbour
    -4- we find the neighbour by replacing each char with all 26 other aphabets
    - and if that newly found word is present and unvisited, we push it into the queue
    -5- we use a set of visited strings to avoid loops and level to keep track of min length
    - compare if the words match
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // step 1
        set<string> words;
        for(auto &s: wordList)
            words.insert(s);
        if(words.find(endWord)==words.end())
            return 0;
        
        // step 2
        queue<string> q;
        q.push(beginWord);
        
        int lvl=1;
        set<string> vis;
        vis.insert(beginWord);
        
        while(!q.empty()){
            // step 3
            int s=q.size();
            while(s--){
                string t=q.front();
                q.pop();
                string temp;
                for(int i=0;i<t.length();i++){
                    temp=t;
                    // step 4
                    for(int j=0;j<27;j++){
                        temp[i]='a'+j;
                        if(temp==endWord)
                            return lvl+1;
                        if(temp[i]!=t[i] && words.find(temp)!=words.end() && vis.find(temp)==vis.end()){
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
};

/*
Time Complexity: O(n*l*27)
Space Complexity: O(n*l)

where n= no. of words in wordList
        l= length of longest word
*/