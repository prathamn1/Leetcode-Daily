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
//always remember that we have to point prev->next to the forward coming node till we got distinct node otherwise keep previous node still at it's place.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-101,head);
        ListNode* prev_node=dummy;
        while(head) {
            if(head->next and head->val==head->next->val) {
                while(head->next and head->val==head->next->val) {
                    head=head->next;
                }
                prev_node->next=head->next;
            //a node is distinct or included in ans when the above if block do not runs and the else runs
            }else {
                prev_node=prev_node->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};