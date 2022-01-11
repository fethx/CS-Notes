// 203. Remove Linked List Elements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* del =  cur->next;
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

// 2. recursive solution, pretty simple and so elegant.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->val == val) 
            return removeElements(head->next, val);
        head->next = removeElements(head->next, val);
        return head;
    }
};