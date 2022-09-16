// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

class Solution {
    void helper(ListNode* ptr, ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return;
        if(!list1){
            ptr->next=list2;
        }
        else if(!list2){
            ptr->next=list1;
        }
        else if(list1->val<list2->val){
            ptr->next=list1;
            helper(ptr->next, list1->next, list2);
        }
        else{
            ptr->next=list2;
            helper(ptr->next, list1, list2->next);
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr=new ListNode(0);
        helper(ptr, list1, list2);
        return ptr->next;
    }
};