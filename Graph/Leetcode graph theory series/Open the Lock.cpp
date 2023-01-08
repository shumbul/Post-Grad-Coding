// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for(string &d:deadends){
            deads.insert(d);
        }
        // if target is a deadend
        if(deads.find(target)!=deads.end())
            return -1;
        if(deads.find("0000")!=deads.end())
            return -1;
        // BFS
        queue<string> q;
        q.push("0000");
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            // cout<<"\n";
            while(s--){
                string f=q.front();
                // cout<<f<<" ";
                q.pop();
                if(f==target)
                    return ans;
                string temp=f;
                for(int k=0;k<4;k++){
                    char c=f[k];
                    (c=='0')?(c='9'):(c=c-1);
                    temp[k]=c;
                    if(deads.find(temp)==deads.end()){
                        deads.insert(temp);
                        q.push(temp);
                    }
                    c=f[k];
                    c=='9'?c='0':c=c+1;
                    temp[k]=c;
                    if(deads.find(temp)==deads.end()){
                        deads.insert(temp);
                        q.push(temp);
                    }
                    temp[k]=f[k];
                }
            }
            ans++;
        }
        return -1;
    }
};

/*
Time: O(10*1000)
Space: O(10*1000)
*/