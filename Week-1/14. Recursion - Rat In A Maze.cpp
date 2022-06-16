// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030

int dx[4]={1, 0, 0, -1}, dy[4]={0, -1, 1, 0};
char d[4]={'D', 'L', 'R', 'U'};

void help(int i, int j, int &n, vector < vector < int >> & arr, string path, vector<string> &ans) {
    if(i<0 || j<0 || i==n || j==n || arr[i][j]==0) {
        return;
    }
    else if(i==n-1 && j==n-1) {
        ans.push_back(path);
        return;
    }
    else{
        arr[i][j]=0;
        // lexicographical => DLRU
        for(int k=0;k<4;k++){
            path.push_back(d[k]);
            help(i+dx[k], j+dy[k], n, arr, path, ans);
            path.pop_back();
        }
        arr[i][j]=1;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    string path;
    help(0, 0, n, arr, path, ans);
    return ans;
}