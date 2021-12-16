// https://leetcode.com/problems/insertion-sort-list/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *prv = head, *tmp1 = head->next;
        while(tmp1) {
            ListNode *nxt = tmp1->next;
            if(tmp1->val <= head->val) {
                tmp1->next = head;
                head = tmp1;
                prv->next = nxt;
            } else {
                ListNode *tmp2 = head;
                while(tmp2->next->val < tmp1->val)
                    tmp2 = tmp2->next;
                if(tmp1 != tmp2->next) {
                    tmp1->next = tmp2->next;
                    tmp2->next = tmp1;
                    prv->next = nxt;
                } else {
                    prv = prv->next;
                }
            }
            tmp1 = nxt;
        }
        return head;
    }
};