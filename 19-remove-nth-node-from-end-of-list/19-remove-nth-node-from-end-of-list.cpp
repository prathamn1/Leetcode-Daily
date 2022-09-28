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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_main=new ListNode(5,head);
        ListNode * dummy=head,*temp=head_main;
        int length=0;
        while(dummy) {
            length++;
            dummy=dummy->next;
        }
        length=length-n;
        while(length--) {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head_main->next;    
    }
};