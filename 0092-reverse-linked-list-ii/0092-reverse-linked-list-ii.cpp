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
    pair<ListNode* ,ListNode*> reverse_list(ListNode* curr_node,int k) {
        ListNode* prev_node=NULL,*next_node;
        for(int i=0;i<k;i++) {
            next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
        }
        return {prev_node,curr_node};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* start_rev,*curr_node=dummy;
        
        for(int i=1;i<left;i++) {
            curr_node=curr_node->next;
        }
        start_rev=curr_node->next;
        pair<ListNode* ,ListNode*> rev=reverse_list(start_rev,right-left+1);
        curr_node->next=rev.first;
        start_rev->next=rev.second;
        return dummy->next;
    }
};