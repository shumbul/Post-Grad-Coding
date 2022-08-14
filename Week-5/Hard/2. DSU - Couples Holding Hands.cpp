// https://leetcode.com/problems/couples-holding-hands/

/*
    0 4 3 2 1 5
    0 1 3 2 4 5
    Ans. 1
    
    
    0 4 3 1 2 5
    0 1 3 2 4 5
    Ans. 2    
*/

class DSU{
public:
    vector<int> par;
    DSU(int &n){
        par.resize(n, 0);
    }
    int Find(int a){
        if(a==par[a])
            return a;
        // path compression
        return par[a]=Find(par[a]);
    }
    bool Union(int a, int b){
        int par_a=Find(a);
        int par_b=Find(b);
        if(par_a==par_b)
            return false;
        par[par_b]=par_a;
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        DSU dsu(n);
        
        for(int i=0;i<n;i+=2){
            dsu.par[row[i]]=row[i];
            dsu.par[row[i+1]]=row[i];
        }
        
        int ans=0;
        for(int i=0;i<n;i+=2){
            if(dsu.Union(i, i+1))
                ans++;
        }
        return ans;
    }
};

/*
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
*/