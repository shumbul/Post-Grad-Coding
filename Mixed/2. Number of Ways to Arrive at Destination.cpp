// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#define ll long long

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        // create a graph
        map<int, vector<vector<int>>> mp;
        for(auto &a: roads){
            mp[a[0]].push_back({a[1], a[2]});
            mp[a[1]].push_back({a[0], a[2]});
        }
        
        if(mp.find(0)==mp.end() || mp.find(n-1)==mp.end())
            return 0;
        
        // 0 to n-1
        // bfs + priority queue + dp
        
        vector<ll> ways(n, 0);
        vector<ll> dist(n, INT_MAX);
        const int mod=1e9+7;
        ways[0]=1;
        dist[0]=0;
        
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; 
        // time, node
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto t=pq.top();
            ll time=t[0], node=t[1];
            pq.pop();
            
            // if we are reaching the node in a longer time than we can
            if(time>dist[node]) continue;
                
            // we are at node n1
            for(auto &a: mp[node]){
                // if we can get there in a better time
                // relaxing distance in Djikstra
                if(dist[a[0]]>time+a[1]){
                    dist[a[0]]=time+a[1];
                    ways[a[0]]=ways[node];
                    pq.push({dist[a[0]], a[0]});
                }
                // else if = found min dist
                else if(dist[a[0]]==time+a[1]){
                    ways[a[0]]=(ways[a[0]]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/