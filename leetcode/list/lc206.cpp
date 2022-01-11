//206. Reverse Linked List

// solution 1. recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || head -> next == NULL) return head;
        ListNode* last = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return last;
    }
};

// solution 2. iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;            
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}; 