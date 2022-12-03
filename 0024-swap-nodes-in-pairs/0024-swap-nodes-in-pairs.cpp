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
    ListNode* swapPairs(ListNode* head) {
        if(not head or not head->next) {
            return head;
        }
        ListNode * dummy_node=new ListNode(),*curr_node=head,*next_node;
        ListNode* prev_node=dummy_node;
        while(curr_node and curr_node->next) {
            next_node=curr_node->next;
            curr_node->next=curr_node->next->next;
            next_node->next=curr_node;
            prev_node->next=next_node;
            prev_node=next_node->next;
            curr_node=curr_node->next;
        }
        return dummy_node->next;
    }
};