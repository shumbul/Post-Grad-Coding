// https://leetcode.com/problems/min-cost-to-connect-all-points/

class UnionFind {
    int par[1002], rank[1002];
public:
    UnionFind(int n){
        for(int i=0;i<n;i++)
            par[i]=i, rank[i]=0;
    }
    int find(int a){
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
    void union_(int a, int b){
        if(rank[a]<rank[b]){
            // b dominates
            par[a]=b;
            rank[b]++;
        }
        else{
            par[b]=a;
            rank[a]++;
        }
    }    
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // union find
        int n=points.size();
        UnionFind uf(n);
        
        // indexing the points
        map<pair<int, int>, int> idx;
        int i=0;
        for(int i=0;i<n;i++){
            idx[{points[i][0], points[i][1]}]=i;
        }
        
        // create a graph - keep distances in key
        // using multiset so that the graph is sorted by default
        
        multiset<pair<int, pair<int, int>>> mp; 
        // <distance, <point1, point2>>
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp.insert({abs(points[j][0]-points[i][0]) + 
                        abs(points[j][1]-points[i][1]),
                           {idx[{points[i][0], points[i][1]}], 
                            idx[{points[j][0], points[j][1]}]}
                          });
            }
        }    
        int ans=0;
        
        // traverse in the distance multiset
        for(auto &d: mp){
            int dist=d.first, x1y1=d.second.first, x2y2=d.second.second;
            x1y1=uf.find(x1y1);
            x2y2=uf.find(x2y2);
            if(x1y1!=x2y2){
                uf.union_(x1y1, x2y2);
                ans+=dist;
            }
        }
        return ans;
    }
};

/*
Time complexity: O(n^2)
Space complexity: O(n)
*/