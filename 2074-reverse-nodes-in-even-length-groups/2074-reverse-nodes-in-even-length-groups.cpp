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
    pair<int,pair<ListNode*,ListNode*>> count_group_nodes(ListNode* curr_node,ListNode* prev_node,int group_size) {
        int skipped=0;
        while(curr_node and group_size--) {
            prev_node=curr_node;
            curr_node=curr_node->next;
            skipped++;
        }
        return {skipped,{prev_node,curr_node}};
    }
    
    pair<ListNode*,ListNode*> reverse_list(ListNode* curr_node,int k) {
        ListNode* prev_node=NULL,*next_node;
        while(curr_node and k--) {
            next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
        }
        return {prev_node,curr_node};
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr_node=head,*prev_node=NULL;
        int group_size=1;
        while(curr_node) {
            pair<int,pair<ListNode*,ListNode*>> pr=count_group_nodes(curr_node,prev_node,group_size);
            if(pr.first%2!=0) {
                curr_node=pr.second.second;
                prev_node=pr.second.first;
            }else {
                pair<ListNode*,ListNode*> rev_pair=reverse_list(curr_node,group_size);
                prev_node->next=rev_pair.first;
                curr_node->next=rev_pair.second;
                prev_node=curr_node;
                curr_node=curr_node->next;
            }
            group_size++;
        }
        return head;
    }
};