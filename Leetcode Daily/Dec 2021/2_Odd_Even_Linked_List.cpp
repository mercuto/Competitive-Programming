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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *cur = head;
        ListNode *newList = new ListNode(-1);
        ListNode *curNew = newList;
        while(cur && cur->next) {
            // cout<<"cur: "<<cur->val<<endl;
            // cout<<"curNew: "<<curNew->val<<endl;
            curNew->next = cur->next;
            curNew = curNew->next;
            if(!cur->next->next)
                break;
            cur->next = cur->next->next;
            cur = cur->next;
            
            /*ListNode *t1 = head;
            while(t1) {
                cout<<t1->val<<" ";
                t1 = t1->next;
            } cout<<endl;
            t1 = newList;
            while(t1) {
                cout<<t1->val<<" ";
                t1 = t1->next;
            } cout<<endl;
            if(cur) cout<<cur->val<<" cur not null"<<endl;*/
        }
        curNew->next = NULL;
        cur->next = newList->next;
        return head;
    }
};