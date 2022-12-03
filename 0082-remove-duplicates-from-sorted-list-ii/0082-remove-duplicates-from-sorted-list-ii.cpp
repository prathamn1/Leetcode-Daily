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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-101,head);
        ListNode* prev_node=dummy;
        while(head) {
            if(head->next and head->val==head->next->val) {
                while(head->next and head->val==head->next->val) {
                    head=head->next;
                }
                prev_node->next=head->next;
            }else {
                prev_node=prev_node->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};