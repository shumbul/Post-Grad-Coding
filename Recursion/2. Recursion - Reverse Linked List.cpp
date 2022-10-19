// https://leetcode.com/problems/reverse-linked-list/

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