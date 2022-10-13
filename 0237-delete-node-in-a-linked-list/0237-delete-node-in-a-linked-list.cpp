/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//if we can't delete anything or can't traverse then the easiest way to solve is to copy the value of the next node to the current node and make the last node to null
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next) {
            node->val=node->next->val;
            node=node->next;
        }
        node->val=node->next->val;
        node->next=NULL;
        
    }
};