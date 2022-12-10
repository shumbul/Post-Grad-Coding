// https://www.codingninjas.com/codestudio/problems/smallest-equivalent-string_1381859

#include <bits/stdc++.h> 
class DSU{
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
        else if(a<b){
            par[b]=a;
        }
        else
            par[a]=b;
    }
    int find(int a){
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
};
string smallestString(string s, string t, string str)
{
	// Write your code here.
    int n=s.length();
    DSU dsu(26);
    for(int i=0;i<n;i++){
        dsu.union_(s[i]-'a', t[i]-'a');
    }
    for(int i=0;i<str.length();i++){
        str[i]=dsu.find(str[i]-'a')+'a';
    }
    return str;
}

/*
Time, Space: O(n+26)
*/