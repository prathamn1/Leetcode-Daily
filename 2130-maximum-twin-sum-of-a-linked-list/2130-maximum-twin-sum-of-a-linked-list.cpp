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
    ListNode * reverse_list(ListNode* curr_node) {
        ListNode* prev_node=NULL,*next_node;
        while(curr_node) {
            next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
        }
        return prev_node;
    }
    ListNode* find_middle(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast and fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* half_reverse=reverse_list(find_middle(head));
        int ans=0;
        while(half_reverse) {
            ans=max(ans,half_reverse->val+head->val);
            half_reverse=half_reverse->next;
            head=head->next;
        }
        return ans;
    }
};