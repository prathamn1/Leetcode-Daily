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
    int length_linked_list(ListNode* head) {
        int l=0;
        while(head) {
            head=head->next;
            l++;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=length_linked_list(head);
        ListNode* first,*second,*curr_node=head;
        for(int i=0;i<=max(k,n-k) and curr_node;i++) {
            if(i==k-1) {
                first=curr_node;
            }
            if(i==n-k) {
                second=curr_node;
            }
            curr_node=curr_node->next;
        }
        int temp =first->val;
        first->val=second->val;
        second->val=temp;
        return head;
    }
};