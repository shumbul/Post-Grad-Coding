// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto &s: wordList){
            if(s.length()==beginWord.size())
                words.insert(s);
        }
        if(words.find(endWord)==words.end())
            return -1;

        priority_queue<pair<int, string>> q;
        map<string, int> vis;
        q.push({0,beginWord});
        vis[beginWord]=0;
        while(!q.empty()){
            auto t=q.top();
            int len=-t.first;
            string s=t.second;
            q.pop();
            // cout<<len<<" "<<s<<"\n";
            if(s==endWord){
                return len;
            }
            string temp=s;
            for(int i=0;i<temp.length();i++){
                temp=s;
                for(int j=0;j<26;j++){
                    temp[i]='A'+j;
                    if(temp!=s && words.find(temp)!=words.end() && (vis.find(temp)==vis.end() || vis[temp]>len)){
                        q.push({-(len+1), temp});
                        vis[temp]=(len+1);
                    }
                }
            }
        }
        return -1;
    }
};

/*
Time: O(V+E)
Space: O(V+E)
*/