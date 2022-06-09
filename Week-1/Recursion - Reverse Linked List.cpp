// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* ans=NULL;
    void helper(ListNode* head, ListNode* prev){
        if(!head){
            ans=prev;
            return;
        }
        ListNode* temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
        helper(head, prev);
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        helper(head, NULL);
        return ans;
    }
};