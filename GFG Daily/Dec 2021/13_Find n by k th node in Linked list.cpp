// https://practice.geeksforgeeks.org/problems/find-nk-th-node-in-linked-list/1
int fractional_node(struct Node *head, int k)
{
    Node *fast = head;
    Node *slow = new Node(-1);
    slow->next = head;
    while(true) {
        int kFast = k;
        while(fast && kFast) {
            fast = fast->next;
            kFast--;
        }
        slow = slow->next;
        if(kFast!=0 || !fast) {
            break;
        }
    }
    return slow->data;
}