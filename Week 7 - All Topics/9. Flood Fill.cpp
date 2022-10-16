// https://leetcode.com/problems/flood-fill/solution/

class Solution {
    vector<int> dx={-1, 0, 1, 0}, dy={0, 1, 0, -1};
    void floodfill(int sr, int sc, int color, int parClr, vector<vector<int>>& image){
     //   cout<<sr<<' '<<sc<<"\n";
        image[sr][sc]=color;
        // check 4 directionally
        for(int k=0;k<4;k++){
            int newr=dx[k]+sr, newc=dy[k]+sc;
            if(newr>=0 && newr<image.size() && newc>=0 && newc<image[0].size()){
                // cout<<newr<<'-'<<newc<<" "<<image[newr][newc]<<"\n";
                if(image[newr][newc]==parClr){
                  //  cout<<newr<<'-'<<newc<<"\n";
                    floodfill(newr, newc, color, parClr, image);
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        if(image[sr][sc]==color)
            return image;
        floodfill(sr, sc, color, image[sr][sc], image);
        return image;
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/