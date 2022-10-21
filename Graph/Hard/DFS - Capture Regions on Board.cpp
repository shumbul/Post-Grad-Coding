// https://www.interviewbit.com/problems/capture-regions-on-board/

int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
bool dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char> > &A, int &m, int &n){
    if(i<=0 || j<=0 || i>=n-1 || j>=m-1){
        return false;
    }
    // cout<<"step-1 ";
    vis[i][j]=true;
    A[i][j]='Y';
    // cout<<"step-2 ";
    for(int k=0;k<4;k++){
        int nx=dx[k]+i, ny=dy[k]+j;
        // cout<<"step-3 ";
        if(nx<0 || ny<0 || nx>=n || ny>=m || A[nx][ny]=='Y' || A[nx][ny]=='X'){
            continue;
        }
        // cout<<"step-4 ";
        if(vis[nx][ny] || dfs(nx, ny, vis, A, m, n)==false)
            return false;
        // cout<<"step-5 ";
    }
    return true;
}

void mark_o_to_x(int i, int j, vector<vector<char> > &A, int &m, int &n, char x){
    if(i<=0 || j<=0 || i>=n-1 || j>=m-1){
        return;
    }
    A[i][j]=x;
    for(int k=0;k<4;k++){
        int nx=dx[k]+i, ny=dy[k]+j;
        if(nx<0 || ny<0 || nx==n || ny==m || A[nx][ny]==x){
            continue;
        }
        else if(A[nx][ny]=='Y')
            mark_o_to_x(nx, ny, A, m, n, x);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(), m=A[0].size();
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O' && !vis[i][j]){
                if(dfs(i, j, vis, A, m, n)){
                    mark_o_to_x(i, j, A, m, n, 'X');
                }
                else{
                    mark_o_to_x(i, j, A, m, n, 'O');
                }
            }
        }
    }
}
