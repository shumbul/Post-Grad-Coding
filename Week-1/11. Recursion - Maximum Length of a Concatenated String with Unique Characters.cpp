// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/

class Solution {
    bool compare(vector<bool> selected, string currString) {
        vector<bool> selfCheck(26, 0);    // checks whether the string is valid in itself, eg. "cerc" or "eccr" are not valid because of repeated c's
        for(int i=0;i<currString.size(); i++){
            if(selfCheck[currString[i]-'a'])
                return false;
            selfCheck[currString[i]-'a']=true;
        }
        // if it reaches here, self check is passed
        // now checking concatenating compatibility with other strings
        for(int i=0;i<currString.size(); i++){
            if(selected[currString[i]-'a'])    // fails the unique characters condition
                return false;
        }
        return true;
    }

    int help(int i, vector<string> &arr, vector<bool> selected, int len) {
        // base condition
        if(i==arr.size()){
            return len;
        }

        string currString = arr[i];    // i'th string in arr
        if(compare(selected, currString)==false) {
                // that means we cannot merge or concatenate this string with the group of strings merged so far
            // so simply skip this string
            return help(i+1, arr, selected, len);
        }
        else {
            // no conflicts => either pick or skip, handle both cases for getting required max length
            // if we skip, it's the same as the if case above
            int op1 = help(i+1, arr, selected, len);

            // if we pick
            for(int j=0;j<currString.length();j++) {
                selected[currString[j]-'a']=true;
            }
            len+=currString.length();
            int op2 = help(i+1, arr, selected, len);
            return max(op1, op2);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        vector<bool> selected(26, false); // initialized for helper
        return help(0, arr, selected, 0);
    }
};