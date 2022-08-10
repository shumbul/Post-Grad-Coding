// https://leetcode.com/problems/surrounded-regions/

class Solution {
    vector<int> dx={-1, 0, 1, 0}, dy={0, 1, 0, -1};
    void dfs(int i, int j, int &n, int &m, vector<vector<char>>& board, vector<vector<bool>> &vis){
        // cout<<i<<" "<<j<<" "<<"\n";
        if(i<0 || j<0 || j>=m || i>=n || board[i][j]!='O' || vis[i][j]){
            return;
        }
        board[i][j]='_';
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            dfs(i+dx[k], j+dy[k], n, m, board, vis);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        // Step-1: Pick up all the border "O" and mark each "O" in their component as "_"
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i, 0, n, m, board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i, m-1, n, m, board, vis);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0, j, n, m, board, vis);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1, j, n, m, board, vis);
            }
        }
        
        // Step-2: "O" -> "X"
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
        // Step-2: "_" -> "O"
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='_'){
                    board[i][j]='O';
                }
            }
        }
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/