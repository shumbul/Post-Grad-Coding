// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        int ans=-1;
        for(string s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                long t1=st.top();
                st.pop();
                long t2=st.top();
                st.pop();
                long t;
                if(s=="+") t=t2+t1;
                else if(s=="-") t=t2-t1;
                else if(s=="/") t=t2/t1;
                else if(s=="*") t=t2*t1;
                // cout<<t1<<" "<<s<<" "<<t2<<" "<<t<<"\n";
                st.push(t);
            }
            else{
                long temp;
                stringstream ss;
                ss<<s;
                ss>>temp;
                // cout<<temp<<"\n";
                st.push(temp);
            }
        }
        ans=st.top();
        st.pop();
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/