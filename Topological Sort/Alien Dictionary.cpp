// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        // creating a graph
        map<char, vector<char>> graph;
        vector<int> inDeg(K, 0);
        for(int i=1;i<N;i++){
            string s1=dict[i-1], s2=dict[i];
            int lim=min(s1.size(), s2.size()), k=0;
            while(k<lim){
                if(s1[k]!=s2[k]){
                    graph[s1[k]].push_back(s2[k]);  // s1[i] comes before s2[i]
                    inDeg[s2[k]-'a']++;
                    break;
                }
                k++;
            }
        }
        queue<int> q;
        string ans;
        // now we have the graph, performing topological sort on the same
        for(int i=0;i<K;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back('a'+a);
            for(char &c: graph['a'+a]){
                inDeg[c-'a']--;
                if(inDeg[c-'a']==0){
                    q.push(c-'a');
                }
            }
        }
        // cout<<ans;
        return ans;
    }
};

/*
Time: O(e+v)
Space: O(e+v)
*/