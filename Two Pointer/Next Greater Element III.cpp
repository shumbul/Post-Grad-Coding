// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int k=-1;
        
        for(int i=s.length()-1; i>0 ;i--){
            if(s[i]>s[i-1]){
                k=i-1;
                break;
            }
        }
        
        if(k!=-1){
            // missed step
            for(int i=s.length()-1; i>k ;i--){
                if(s[i]>s[k]){
                    swap(s[i], s[k]);
                    break;
                }
            }
            sort(s.begin()+k+1, s.end());
        }
        
        int n2=-1;
        try{
            n2=stoi(s);
        }
        catch(...){
            return -1;
        }
        return n2!=n?n2:-1;
    }
};

/*
l = no. of digits in n
Time: O(llogl)
Space: O(l)
*/