// https://leetcode.com/problems/spiral-matrix-iv/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int maxm=m, maxn=n, minm=0, minn=0;
        int dir=0;
        // 0=right, 1=down, 2=left, 3=up
        int i=0, j=0;
        while(head){
            // calculate i and j
            // m*n
            // cout<<i<<" "<<j<<"\n";
            ans[i][j]=head->val;
            if(dir==0){
                if(j<maxn-1)
                    j++;
                else
                    dir=1, i++, minm++;
            }
            else if(dir==1){
                if(i<maxm-1)
                    i++;
                else
                    dir=2, j--, maxn--;
            }
            else if(dir==2){
                if(j>minn)
                    j--;
                else
                    dir=3, i--, maxm--;
            }
            else{
                if(i>minm)
                    i--;
                else
                    dir=0, j++, minn++;
            }
            head=head->next;
        }
        return ans;
    }
};

/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/