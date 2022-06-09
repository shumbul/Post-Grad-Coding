class Solution {
public:
    void reverseString(vector<char>& s, int pos=0) {
        if(pos==s.size()/2)
            return;
        swap(s[pos], s[s.size()-pos-1]);
        reverseString(s, pos+1);
    }
};