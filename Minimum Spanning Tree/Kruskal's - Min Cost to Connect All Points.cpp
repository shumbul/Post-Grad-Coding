// https://leetcode.com/problems/min-cost-to-connect-all-points/
// prerequisite: https://www.youtube.com/watch?v=fAuF0EuZVCk&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j&index=4&ab_channel=TusharRoy-CodingMadeSimple

class Solution {
    class DSU{
        vector<int> par;
    public:
        DSU(int &n){
            par.resize(n);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        int find(int a){
            if(a==par[a])
                return a;
            return par[a]=find(par[a]); // path compression
        }
        void union_(int &a, int &b){
            par[a]=b;   // rest is handled by the func calling union_
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // step-1 : forming edges with cost
        // index the points
        int k=0;
        unordered_map<int, pair<int,int>> idxToPoint;
        map<pair<int,int>, int> pointToIdx;
        for(auto &p: points){
            if(pointToIdx.count({p[0],p[1]}))
                continue;
            pointToIdx[{p[0],p[1]}]=k;
            idxToPoint[k++]={p[0],p[1]};
        }
        
        // we have in total k unique points
        // now we would find and store dist of each point to one another in graph
        vector<pair<int, pair<int, int>>> edges;
        // {{dist12, idx1, idx2}}
        for(int i=1;i<k;i++){
            for(int j=0;j<i;j++){
                pair<int, int> p1=idxToPoint[i], p2=idxToPoint[j];
                int dist=abs(p1.first-p2.first)+abs(p1.second-p2.second);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        
        // step-2 : DSU
        DSU dsu(k);
        
        // step-3 : Kruskal's
        int ans=0;
        for(auto &e: edges){
            int a=e.second.first, b=e.second.second;
            a=dsu.find(a), b=dsu.find(b);
            if(a==b)
                continue;   // same group forms cycle
            ans+=e.first;
            dsu.union_(a, b);
        }
        return ans;
    }
};