// https://leetcode.com/problems/accounts-merge/

class Solution {
    class DSU {
    public:
        vector<int> par;
        DSU(int n){
            par.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }
        void union_(int a, int b){
            a=find(a), b=find(b);
            if(a==b)
                return;
            if(a<b)
                par[b]=a;
            else
                par[a]=b;
        }
        int find(int a){
            if(a==par[a])
                return a;
            return par[a]=find(par[a]);
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> ids;
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(ids.find(email)==ids.end())
                    ids[email]=i;
                else{
                    dsu.union_(ids[email], i);
                }
            }
        }
        set<string> mergedMail[n];
        for(auto &i: ids){
            string mail=i.first;
            int id=dsu.find(i.second);
            mergedMail[id].insert(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            vector<string> v;
            v.push_back(accounts[i][0]);
            set<string> mails=mergedMail[i];
            for(auto &m: mails){
                v.push_back(m);
            }
            if(v.size()>1)
                ans.push_back(v);
        }
        return ans;
    }
};

/*
n=no. of accounts
k=mail length of mail
Time: O(nklog(nk))
Space: O(nk)
*/