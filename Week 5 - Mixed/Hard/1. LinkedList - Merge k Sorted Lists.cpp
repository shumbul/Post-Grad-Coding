// https://leetcode.com/problems/merge-k-sorted-lists/

/*
    We use priority queue as it'll prioritize which list's node would first get included
*/

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
struct comp{
    bool operator()(ListNode* &l1, ListNode* &l2){
        return l1->val>=l2->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // LL + PQ
        // PQ will keep nodes acc to their inc order of value
        ListNode* newList=new ListNode();
        auto temp=newList;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(ListNode* node: lists){
            if(node)
                pq.push(node);
        }
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            // cout<<node->val;
            temp->next=node;
            temp=temp->next;
            if(node->next){
                pq.push(node->next);
            }
        }
        return newList->next;
    }
};

/*
Time Complexity: O(nlogk) -> Priority queue takes O(logk)
Space Complexity: O(n)
*/