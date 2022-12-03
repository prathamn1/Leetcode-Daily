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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_x=new ListNode(),*great_x=new ListNode();
        ListNode *curr_small=small_x,*curr_great=great_x;
        while(head) {
            if(head->val<x) {
                curr_small->next=new ListNode(head->val);
                curr_small=curr_small->next;
            }else {
                curr_great->next=new ListNode(head->val);
                curr_great=curr_great->next;
            }
            head=head->next;
        }
        curr_small->next=great_x->next;
        return small_x->next;
    }
};