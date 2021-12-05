// Ques: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        ListNode *sl = NULL, *fs = head;
        while(fs && fs->next) {
            sl = sl==NULL ? head : sl->next;
            fs = fs->next->next;
        }
        sl->next = sl->next->next;
        return head;
    }
};