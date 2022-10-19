// https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs/problem

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int &count, vector<bool> &vis, unordered_map<int, vector<int>> &mp) {
    count++;
    vis[i]=1;
    for(auto &a: mp[i]){
        if(!vis[a]){
            dfs(a, count, vis, mp);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p, a, b;
    cin>>n>>p;
    unordered_map<int, vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a].push_back(b);        
        mp[b].push_back(a);
    }
    vector<int> ans;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int count=0;
            dfs(i, count, vis, mp);
            ans.push_back(count);
        }
    }
    
    // formula
    int res=0;
    for(int i=0;i<ans.size();i++){
        for(int j=i+1;j<ans.size();j++){
            res+=(ans[i]*ans[j]);
        }
    }
    cout<<res;
        
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/