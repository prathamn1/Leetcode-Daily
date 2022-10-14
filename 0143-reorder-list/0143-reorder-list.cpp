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
    ListNode* reverse(ListNode* node){
        if(not node) {
            return NULL;
        }
        ListNode *prev=NULL,*curr=node,*forward=NULL;
        while(curr) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    ListNode* find_mid(ListNode* node) {
        ListNode* slow =node, * fast=node->next;
        while(fast->next and fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        if(not head->next) {
            return;
        }
        ListNode* mid=find_mid(head);
        ListNode* head_end=reverse(mid->next);
        mid->next=NULL;
        ListNode* head_start=head;
        int n=0;
        
        while(head_end and head_start) {
            if(n%2==0) {
                ListNode* temp=head_start->next;
                head_start->next=head_end;
                head_start=temp;
            }else{
                ListNode* temp=head_end->next;
                head_end->next=head_start;
                head_end=temp;
            }
            n+=1;
        }
        
    }
};