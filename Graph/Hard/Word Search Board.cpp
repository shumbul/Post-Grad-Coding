// https://www.interviewbit.com/problems/word-search-board/

#include<bits/stdc++.h>
using namespace std;

int dx[4]={0, -1, 0, 1}, dy[4]={-1, 0, 1, 0};
bool dfs(int i, int j, int pos, vector<string> &A, string &B) {
    if(i<0 || i>A.size() || j<0 || j>A[i].size())
        return false;
    if(pos==B.size())
        return true;
    if(B[pos]!=A[i][j])
        return false;
    for(int k=0;k<4;k++){
        int nx=dx[k]+i, ny=dy[k]+j;
        if(dfs(nx, ny, pos+1, A, B))
            return true;
    }
    return false;
}
int exist(vector<string> &A, string B) {
    // dfs
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]==B[0]){
                if(dfs(i, j, 0, A, B))
                    return 1;
            }
        }
    }
    return 0;
}

int main(){
    vector<string> A={"FEDCBECD", "FABBGACG", "CDEDGAEC", "BFFEGGBA", "FCEEAFDA", "AGFADEAC", "ADGDCBAA", "EAABDDFF"};
    string B="BCDCB";

    cout<<exist(A,B);
    return 0;
}