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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head=list1;
        ListNode* before_rem=NULL,*after_rem=list1;
        for(int i=0;i<b;i++) {
            if(i==a-1) {
                before_rem=after_rem;
            }
            after_rem=after_rem->next;
        }
        after_rem=after_rem->next;
        if(before_rem==NULL) {
            head=list2;
        }else {
            before_rem->next=list2;
        }
        while(list2->next) {
            list2=list2->next;
        }
        list2->next=after_rem;
        return head;
    }
};