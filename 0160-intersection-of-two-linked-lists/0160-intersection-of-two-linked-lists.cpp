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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode* curr_a=headA,*curr_b=headB;
        while(curr_a) {
            l1++;
            curr_a=curr_a->next;
        }
        while(curr_b) {
            l2++;
            curr_b=curr_b->next;
        }
        if(l2>l1) {
            swap(l1,l2);
            swap(headA,headB);
        }
        while(l1-l2!=0) {
            headA=headA->next;
            l1--;
        }
        while(headA and headB) {
            if(headA==headB) {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};