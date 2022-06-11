// https://leetcode.com/problems/remove-linked-list-elements/submissions/

class Solution {
    void help(ListNode* temp, ListNode* head, int &val){
        if(!head){
            temp->next=NULL;
            return;
        }
        if(head->val!=val){
            temp->next=head;
            help(temp->next, head->next, val);
        }
        else{
            help(temp, head->next, val);
        }
        
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        auto temp2=temp;
        help(temp2, head, val);
        return temp->next;
    }
};