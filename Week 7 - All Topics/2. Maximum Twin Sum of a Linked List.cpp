// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    void help(ListNode* node, ListNode* &node2, int &ans) {
        if(!node || !node2){
            return;
        }
        help(node->next, node2, ans);
        // cout<<node->val<<" "<<node2->val<<"\n";
        int sum=node->val+node2->val;
        ans=max(ans, sum);
        node2=node2->next;
    }
public:
    int pairSum(ListNode* head) {
        int ans=0;
        help(head, head, ans);
        return ans;
    }
};

/*
Time: O(n)
Space: O(n)
*/