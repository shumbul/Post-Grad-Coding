// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(), diff=0;
        // 00, 11, 22
        // 10, 21
        // 20
        for(int i=0;i<n;i++){
            priority_queue<int, vector<int>, greater<int>> temp;
            for(int j=0;j<n;j++){
                // cout<<j<<" "<<j-diff<<"\n";
                if(j<n && j-diff>=0 && j-diff<m)
                    temp.push(mat[j][j-diff]);
            }
            for(int j=i;j<n;j++){
                if(j<n && j-diff>=0 && j-diff<m){
                    mat[j][j-diff]=temp.top();
                    temp.pop();
                }
            }
            diff++;
        }
        
        // 01, 12, 23
        // 02, 13
        // 03
        
        diff=1;
        for(int j=0;j<m;j++){
            priority_queue<int, vector<int>, greater<int>> temp;
            for(int i=0;i<m;i++){
                // cout<<i<<" "<<i+diff<<"\n";
                if(i<n && i+diff<m)
                    temp.push(mat[i][i+diff]);
            }
            for(int i=0;i<m;i++){
                if(i<n && i+diff<m){
                    mat[i][i+diff]=temp.top();
                    temp.pop();
                }
            }
            diff++;
        }        
        return mat;
    }
};

/*
    Time Complexity: O(n*m)
    Space Complexity: O(n*m)
*/