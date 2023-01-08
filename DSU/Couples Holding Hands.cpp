// https://leetcode.com/problems/couples-holding-hands/

class Solution {
    class DSU {
    public:
        vector<int> par;
        DSU(int n, vector<int> row){
            par.resize(n,0);
            for(int i=0;i<n;i+=2){
                par[row[i]]=row[i];
                par[row[i+1]]=row[i];
            }
        }
        bool union_(int a, int b){
            // cout<<a<<" "<<b<<"\n";
            a=find(a), b=find(b);
            if(a==b)
                return false;
            // cout<<a<<" "<<b<<"\n";
            par[a]=b;
            return true;
        }
        int find(int a){
            if(par[a]==a)
                return a;
            return par[a]=find(par[a]);
        }
    };
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(), ans=0;
        DSU dsu(n, row);
        for(int i=0;i<n;i+=2){
            // cout<<i<<" -> ";
            if(dsu.union_(i, i+1))
                ans++;
        }
        return ans;
    }
};

/*
Time: O(V+E)
Space: O(V+E)
*/