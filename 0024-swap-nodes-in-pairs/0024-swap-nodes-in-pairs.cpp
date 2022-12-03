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

//trick is to install one dummy node or helping node at the starting and then draw 4-5 node and make algorithm on copy on how to order them

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(not head or not head->next) {
            return head;
        }
        ListNode * dummy_node=new ListNode(),*curr_node=head;
        ListNode* prev_node=dummy_node;
        while(curr_node and curr_node->next) {
            prev_node->next=curr_node->next;
            curr_node->next=curr_node->next->next;
            prev_node->next->next=curr_node;
            
            prev_node=curr_node;
            curr_node=curr_node->next;
        }
        return dummy_node->next;
    }
};