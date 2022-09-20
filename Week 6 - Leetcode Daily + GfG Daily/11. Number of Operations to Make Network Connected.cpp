// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
    int find(int a, vector<int> &par){
        if(a==par[a])
            return a;
        return par[a]=find(par[a], par);
    }
    void union_(int a, int b, vector<int> &par, vector<int> &rank){
        if(rank[b]>rank[a]){
            par[a]=b;
            rank[b]++;
        }
        else{
            par[b]=a;
            rank[a]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // basically
        // we need to find out the number of redundent connections
        // there are n servers and m connections
        int m=connections.size();
        if(m<n-1)
            return -1;
        
        // reason: m should atleast be n-1 to make sure all computers are connected
        
        int extra=0;
        vector<int> par(n), rank(n, 1);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(auto &c: connections){
            int c0=c[0], c1=c[1];
            c0=find(c0, par);
            c1=find(c1, par);
            if(c0!=c1){
                union_(c0, c1, par, rank);
            }
            else{
                extra++;
            }
        }
        
        // they all should have the same parent
        int group=0;
        for(int i=0;i<n;i++){
            if(find(i, par)==i)
                group++;
        }
        
        return extra<group-1?-1:group-1;
    }
};

/*
Time: O(n)
Space: O(n)
*/