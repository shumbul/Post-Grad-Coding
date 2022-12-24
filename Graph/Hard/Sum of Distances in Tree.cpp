// https://leetcode.com/problems/sum-of-distances-in-tree/

// Floyd Warshall giving TLE
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Floyd warshall in tree
        long long INF=LONG_MAX;
        vector<vector<int>> mat(n, vector<int> (n, INF));
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(auto &e: edges){
            mat[e[0]][e[1]]=1;
            mat[e[1]][e[0]]=1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[i][k]!=INF && mat[k][j]!=INF)
                        mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<n;j++){
                // cout<<mat[i][j]<<" ";
                if(mat[i][j]!=INF)
                    a+=mat[i][j];
            }
            // cout<<"\n";
            ans.push_back(a);
        }
        return ans;
    }
};

/*
Time: O(n^3)
Space: O(n^3)
*/

