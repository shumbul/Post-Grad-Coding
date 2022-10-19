// https://leetcode.com/problems/palindrome-linked-list/submissions/

class Solution {
    ListNode* start;
    bool helper(ListNode* end){
        if(!end)
            return true;
        if(!helper(end->next))
                return false;
        if(start->val!=end->val)
            return false;
        start=start->next;
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* end=head;
        start=head;
        return helper(end);
    }
};