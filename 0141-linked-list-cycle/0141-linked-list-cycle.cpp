/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(not head) {
            return false;
        }
        ListNode *slow=head,*fast=head->next;
        while(slow!=fast and fast and fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast) {
            return true;
        }
        return false;
    }
};