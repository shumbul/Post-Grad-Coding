// https://leetcode.com/problems/maximal-rectangle/

class Solution {
    int MAH(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> nsleft(n), nsright(n);
        // populating next smallest to the left
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                nsleft[i]=-1;
            }
            else if(arr[i]>arr[st.top()]){
                nsleft[i]=st.top();
                st.push(i);
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsleft[i]=-1;
                    st.push(i);
                }
                else{
                    nsleft[i]=st.top();
                    st.push(i);
                }
            }
        }
        while(!st.empty())
            st.pop();
        
        // populating next smallest to the right
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                nsright[i]=n;
            }
            else if(arr[i]>arr[st.top()]){
                nsright[i]=st.top();
                st.push(i);
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsright[i]=n;
                    st.push(i);
                }
                else{
                    nsright[i]=st.top();
                    st.push(i);
                }
            }
        }
        while(!st.empty())
            st.pop();
        int mah=0;
        for(int i=0;i<n;i++){
            cout<<nsright[i]<<' '<<nsleft[i]<<'\n';
            mah=max(mah, arr[i]*(nsright[i] - nsleft[i] - 1));
        }
        
        return mah;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // step-1: dp table
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<int>> dp(r, vector<int> (c, 0));
        for(int i=0;i<c;i++){
            dp[0][i]=matrix[0][i]-'0';
        }
        int ans=0;
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                    dp[i][j]=((dp[i-1][j])?(dp[i-1][j]+1):1);
                else dp[i][j]=0;
            }
        }
        // step-2: finding ans using Maximum Area Histogram logic
        for(auto &a: dp){
            ans=max(ans, MAH(a));
            // for(auto v:a){
            //     cout<<v<<' ';
            // }
            // cout<<'\n';
        }
        return ans;
    }
};