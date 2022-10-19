// https://practice.geeksforgeeks.org/contest/interview-series-68/problems/#

class Solution {

  public:
    int noConseBits(int query) {
        // 7->111
        // 111->110 = 6
        // 1111111 -> 1101101 > 0110110
        // highest priority is to unset it from rightmost to leftmost
        // binary conversion
        if(query==0)
            return 0;
        int q=query;
        string bin;
        while(q){
            if(q&1){
                bin+='1';
            }
            else{
                bin+='0';
            }
            q=q>>1;
        }
        
        reverse(bin.begin(), bin.end());
        
        stack<int> st;
        for(int i=0;i<bin.length();i++){
            if(bin[i]=='1'){
                st.push(1);
                if(st.size()==3){
                    // unset
                    bin[i]='0';
                    while(!st.empty())
                        st.pop();
                }
            }
            else{
                while(!st.empty())
                    st.pop();
            }
        }
        
        // bin to decimal
        int ans=0;
        ans=stoi(bin, 0, 2);
        return ans;
    }
};

/*
Time Complexity: O(logn*log(logn))
Space Complexity: O(logn)
*/