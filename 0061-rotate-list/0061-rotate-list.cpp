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

    pair<ListNode*,ListNode*> reverse(ListNode* head,int length) {
        ListNode* curr_node=head,*prev_node=NULL,*next_node;
        while(length!=0) {
            next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
            length--;
        }
        return {prev_node,curr_node};
    }
    int length_list(ListNode* head) {
        int l=0;
        while(head) {
            l++;
            head=head->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(not head) {
            return NULL;
        }
        int n=length_list(head);
        k=k%n;
        if(k==0) {
            return head;
        }
        ListNode* head_rev=reverse(head,n).first;
        
        auto reverse_firstK=reverse(head_rev,k);
        
        head_rev->next=reverse(reverse_firstK.second,n-k).first;
        
        return reverse_firstK.first;
    }
};

