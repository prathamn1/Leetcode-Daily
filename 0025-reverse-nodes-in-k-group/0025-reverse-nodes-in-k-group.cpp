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
    ListNode* reverse_list(ListNode* curr_node,int k) {
        ListNode* next_node,*prev_node=NULL;
        for(int i=0;i<k;i++) {
            next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node; 
        } 
        return prev_node;
    }
    ListNode is_k_nodes_available(ListNode* start,int k) {
        while(start and k!=0) {
            start=start->next;
            k-=1;
        }
        return ListNode(k,start);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy_head(0,NULL);
        ListNode* start=head,*k_head=&dummy_head;
        while(true) {
            ListNode k_node=is_k_nodes_available(start,k);
            if(k_node.val==0) {
                k_head->next=reverse_list(start,k);
                k_head=start;
                start=k_node.next;
            }else {
                k_head->next=start;
                break;
            }
        }
        return dummy_head.next;
    }
};