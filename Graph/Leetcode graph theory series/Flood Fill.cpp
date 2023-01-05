// Flood Fill
// https://leetcode.com/problems/flood-fill

class Solution {
    vector<int> dx={-1, 0, 1, 0}, dy={0, 1, 0, -1};
    int m,n;
    void dfs(int i, int j, vector<vector<int>>& image, int basecolor, int &color){
        // cout<<i<<" "<<j<<"\n";
        image[i][j]=color;
        for(int k=0;k<4;k++){
            int ni=dx[k]+i, nj=dy[k]+j;
            if(ni<0 || nj<0 || ni>=n || nj>=m || image[ni][nj]!=basecolor){
                continue;
            }
            dfs(ni, nj, image, basecolor, color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size(), m=image[0].size();
        if(image[sr][sc]==color)
            return image;
        dfs(sr, sc, image, image[sr][sc], color);
        return image;        
    }
};

/*
Time, Space: O(m*n)
*/