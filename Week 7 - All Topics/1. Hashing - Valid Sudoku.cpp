// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        map<int, unordered_set<int>> mp_row, mp_col;
        map<pair<int, int>, unordered_set<int>> mp_box;
        int n=nums.size(), m=nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]=='.') continue;
                // cout<<i<<' '<<j<<'\n';
                
                if(mp_row[i].find(nums[i][j])!=mp_row[i].end())
                    return false;
                mp_row[i].insert(nums[i][j]);
                if(mp_col[j].find(nums[i][j])!=mp_col[j].end())
                    return false;
                mp_col[j].insert(nums[i][j]);                
                // cout<<" pass \n";
                if(mp_box[{(i/3),(j/3)}].find(nums[i][j])!=mp_box[{(i/3),(j/3)}].end())
                    return false;
                mp_box[{(i/3),(j/3)}].insert(nums[i][j]);
            }
        }
        return true;
    }
};

/*
Time: O(m*n)
Space: O(max(m,n))
*/