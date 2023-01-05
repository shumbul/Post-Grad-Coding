// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int rightLim=0, upLim=0, leftLim=m-1, downLim=n-1;
        vector<int> ans;
        
        while(rightLim<=leftLim && upLim<=downLim){
            for(int i=rightLim; i<=leftLim; i++){
                ans.push_back(matrix[upLim][i]);
            }
            upLim++;
            if(ans.size()==m*n)
                break;
            for(int i=upLim; i<=downLim; i++){
                ans.push_back(matrix[i][leftLim]);
            }
            if(ans.size()==m*n)
                break;
            leftLim--;
            for(int i=leftLim; i>=rightLim; i--){
                ans.push_back(matrix[downLim][i]);
            }
            if(ans.size()==m*n)
                break;
            downLim--;
            for(int i=downLim; i>=upLim; i--){
                ans.push_back(matrix[i][rightLim]);
            }
            if(ans.size()==m*n)
                break;
            rightLim++;
        }
        
        return ans;
    }
};

/*
Time: O(n*m)
Extra Space: O(1)
*/