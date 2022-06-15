// https://leetcode.com/problems/flood-fill/

class Solution {
    int dx[4]={-1, 0, 0, 1}, dy[4]={0, -1, 1, 0};

    void help(vector<vector<bool>> &vis, vector<vector<int>> &image, int &m, int &n, int x, int y, int &oldColor, int newColor) {
        if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || image[x][y]!=oldColor){
            return;
        }
        vis[x][y]=true;
        image[x][y]=newColor;
        for(int k=0;k<4;k++){
            help(vis, image, m, n, x+dx[k], y+dy[k], oldColor, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        int n=image.size(), m=image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int oldColor=image[x][y];
        help(vis, image, m, n, x, y, oldColor, newColor);
        return image;
    }
};